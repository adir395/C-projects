/* Assignment: 3.2
Author: Adir Melker, ID: 316614569
*/

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define size 5
int sumLine(int arr[size][size]);
int calcPlusLine(int [size][size],int line);
int sumColumn(int arr[size][size]);
int calcPlusColumn(int arr[size][size], int column);
int twin(int arr[size][size]);
int allTwin(int arr[size][size], int line);


void main()
{
	int i,j;
	int arr[size][size];
	for (i = 0; i < size; i++)
	{
		printf("please enter numbers to the %d line :\n", i+1);
		for (j = 0; j < size; j++)
			scanf_s("%d", &arr[i][j]);//get the matrix from the user 5*5
	}
	printf("Sum of maximums of lines: %d \n", sumLine(arr));
	printf("Sum of maximums of cols: %d \n", sumColumn(arr));
	printf("Number of equal pairs of neighbors: %d \n", twin(arr));
}

int sumLine(int arr[size][size])//get the matrix and calc the sum of the biggest number in each line
{
	int sum = 0,i;
	for (i = 0; i < size; i++) 
		sum+= calcPlusLine(arr,i);
	return sum;

}
int calcPlusLine(int arr[size][size],int line)//check the biggest number in the line
{
	int max,j;
	max = arr[line][0];
	for (j = 1; j < size; j++)
	{
		if (max < arr[line][j])
			max = arr[line][j];
	}
	return max;
}

int sumColumn(int arr[size][size])//get the matrix and calc the sum of the biggest number in each coll
{
	int i,sum=0;
	for (i = 0; i < size; i++)
		sum += calcPlusColumn(arr, i);
	return sum;
}

int calcPlusColumn(int arr[size][size], int column)//check the biggest number in the coll
{
	int j,max;
	max = arr[0][column];
	for (j = 1; j < size; j++) 
	{
		if (max < arr[j][column])
			max = arr[j][column];
	}
	return max;
}

int twin(int arr[size][size])//get matrix and check hw many twin have
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
		sum += allTwin(arr, i);
	return sum;
}

int allTwin(int arr[size][size], int line)//get the line on the matrix and check all the possible twin
{
	int j, count = 0;
	for (j = 0; j < size; j++)
	{
		if (arr[line][j] == arr[line][j+1])
			count++;
		if (arr[line][j] == arr[line + 1][j])
			count++;
		if (arr[line][j] == arr[line + 1][j + 1])
			count++;
		if (arr[line][j] == arr[line + 1][j - 1])
			count++;
	}
	return count;
}