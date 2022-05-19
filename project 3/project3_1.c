/* Assignment: 3.1
Author: Adir Melker, ID: 316614569
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int contain(int big[], int size_b, int small[], int size_s);
void getBig(int size_b, int big[]);
void getSmall(int size_s, int small[]);
void digits(int arr[], int size, int statistics[]);
void arrToZero(int statistics);


int main() {
	int big[10], small[5], size_b=10 , size_s=5,x,statistics[10];
	getBig(size_b,big);
	getSmall(size_s,small);
	x=contain(big,size_b,small,size_s);
	printf("%d\n", x);
	digits(big, size_b, statistics);
	arrToZero(statistics);
	digits(small, size_s, statistics);

}


void getBig(int size_b,int big[])//get the bigger arry
{
	printf("Please enter 10 numbers\n");
	for (int i = 0; i < size_b; i++) 
	{
		printf("Enter the %d number:", i + 1);
		scanf_s("%d", &big[i]);
	}
}
void getSmall(int size_s, int small[])//get samll aray
{
	printf("Please enter 5 numbers\n");
	for (int i = 0; i < size_s;i++)
	{
		printf("Enter the %d number:",i+1);
		scanf_s("%d",&small[i]);
	}
}

int contain(int big[], int size_b, int small[], int size_s)//function that check if the small array is inside the bigger arry consecutive
{
	int i=0, j=0,counter=0;
	while (i < size_b)
	{
		if (big[i] == small[j]) {
			i++;
			j++;
			counter++;
			if (counter == size_s)
				return small[0];
		}
		else {
			i ++;
			j = 0;
			counter = 0;
		}
		
	}
	if (counter!=size_s)
		return -1;
}

void digits(int arr[], int size, int statistics[])
{
	int i,l,k,j,counter=0;
	for (i = 0; i < 10; i++)
	{
		counter=0;
		for(int x=0;x<size;x++)
		{
			if (arr[i] >= 100)
			{
				l = arr[x] / 100; 
				if (i == l)
				counter++;
			}
			if (arr[i]>=10)
			{
				k = (arr[x] / 10) % 10;
				if (i == k)
				counter++;
			}
			j = arr[x] % 10;
			if (i == j)
				counter++;
		}
		statistics[i] = counter;
	}
	for (int h = 0; h < 10; h++)
		printf("%d\t", statistics[h]);
	printf("\n");
}

void arrToZero(int statistics[])//rest the arry
{
	for (int i = 0; i < 10; i++)
		statistics[i] = 0;
}