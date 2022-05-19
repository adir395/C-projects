/*Assignment:4.3
Author:Adir Melker,ID:316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long** shrink(int** arr1, int size);
int count(int **arr1);
void freem(int** arr,int size);

int main()
{
	int i, j, size, ** arr1 = NULL;
	long long **arr2 = NULL;
	printf("Please enter the size of the matrix:");
	scanf_s("%d", &size);
	if ((size) % 2 != 0)
		return NULL;
	arr1 = (int**)malloc(size * sizeof(int*));
	if (arr1 == NULL)
	{
		printf("Error");
		return 0;
	}
	for (i = 0; i < size; i++)
	{
		arr1[i] = (int*)malloc(size * sizeof(int));
		if (arr1[i] == NULL)
		{
			printf("error");
			return 0;
		}
	}
	printf("Please enter the matrix:\n");//get the matrix from user
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			scanf_s("%d", &arr1[i][j]);
	printf("\n\n");
	arr2=shrink(arr1, size);
	for (i = 0; i < size / 2; i++)
	{
		for (j = 0; j < size / 2; j++)
			printf("%lld ", arr2[i][j]);
		printf("\n");
	}
	freem(arr2, size / 2);
	freem(arr1, size);
}
long long** shrink(int** arr1, int size)
{
	long long** arr2 = NULL;
    int i=0,j=0,x=0,k=0;
	arr2 = (long long**)malloc(size/2 * sizeof(long long*));
	if (arr2 == NULL)
	{
		printf("ERROR");
		return 0;
	}
	for (i = 0; i < size/2; i++)
	{
		arr2[i] = (long*)malloc(size / 2 * sizeof(long long));
		if (arr2[i] == NULL)
		{
			printf("ERROR");
			return 0;
		}
	}
	for (i = 0; i < size / 2; i++)
	{
		for (j = 0; j < size/2; j++)
		{
			arr2[i][j] = arr1[x][k];
			arr2[i][j] = count(arr1[x][k + 1]) * arr2[i][j] + arr1[x][k + 1];
			arr2[i][j] = count(arr1[x+1][k]) * arr2[i][j] + arr1[x+1][k];
			arr2[i][j] = count(arr1[x+1][k + 1]) * arr2[i][j] + arr1[x+1][k + 1];
			k += 2;	
		}
		x += 2;
		k = 0;	
	}	
	return arr2;
}
int count(int arr1)
{
	int count = 0;
	while (arr1)
	{
		arr1 /= 10;
		count++;
	}
	if (count == 1)
		return 10;
	if (count == 2)
		return 100;
	if (count == 3)
		return 1000;
	if (count == 4)
		return 10000;
	if (count == 5)
		return 100000;
}

void freem(int** arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		free(arr[i]);
	free(arr);
}