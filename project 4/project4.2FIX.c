/* Assignment: 4.2
Author: Adir Melker, ID: 316614569
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int* divide(int a[], int size_a, int b[], int size_b);
int* allocArray(int size);
void insertArray(int* arr, int size);

void main()
{
	int size_a,size_b ;
	int *arr_a=NULL, *arr_b=NULL,*arr_c=NULL;
	printf("Please enter size of a:");
	scanf_s("%d",&size_a);
	arr_a = allocArray(size_a);
	printf("Enter %d elements of a: ",size_a);
	insertArray(arr_a, size_a);
	printf("Please enter size of b:");
	scanf_s("%d",&size_b);
	arr_b = allocArray(size_b);
	printf("Enter %d elements of b: ",size_b);
	insertArray(arr_b, size_b);
	arr_c=divide(arr_a, size_a, arr_b, size_b);
	free(arr_a);
	free(arr_b);
	for (int k = 0; k < size_b; k++)
		printf("%d ",arr_c[k]);
	free(arr_c);
}

int* allocArray(int size)
{
	int* arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL)
	{
		printf("Don't have space");
		return 1;
	}
	return arr;
}
void insertArray(int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		scanf_s("%d", &arr[i]);
}
int* divide(int arr_a[], int size_a, int arr_b[], int size_b)
{
	int i = 0, j = 0, count=0;
	int* arr_c = NULL;
	arr_c = allocArray(size_b);
	while (i < size_b)
	{
		while (j < size_a)
		{
			if (arr_a[j] % arr_b[i] == 0)
				count++;
			j++;
		}
		j = 0;
		arr_c[i] = count;
		count = 0;
		i++;
	}
	return arr_c;
}
