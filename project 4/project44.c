/*Assignment:4.4
Author:Adir Melker,ID:316614569*/
#define _CRT_SECURE_NO_WARNINGS
#define N 50 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** init_arr(int* psize);
char** add(char** arr, int* psize, char* str);
void twice(char** arr, int size, int index);
int find(char** arr, int size, char* str);
void print(char** arr, int size);

void main()
{
	int i,size = 0;
	char* str = NULL, ** arr = NULL,word[N];
	arr = init_arr(&size);
	
	do
	{
		printf("1-Add\n");
		printf("2-Twice\n");
		printf("3-Find\n");
		printf("4-Prinf\n");
		printf("5-End\n");
		scanf("%d", &i);
		if (i < 1 || i > 5)
			printf("Bad choice.Try again\n");
		switch (i)
		{
		case(1):
			printf("Please add one more word :");
			scanf("%s", word);
			arr = add(arr, &size, word);
			printf("Done\n");
			break;

		case(2):
			printf("Please enter index:");
			scanf("%d", &i);
			twice(arr, size, i);
			print(arr, size);
			break;
		case(3):
			printf("Please enter word:\n");
			scanf("%s",word);
			printf("%d\n", find(arr, size, word));
			break;
		case(4):
			print(arr, size);
			break;
		}
	} while (i!=5);
	free(str);
	free(arr);
	printf("Goodbye");	

}

char** init_arr(int* psize)//get the arr
{
	int i;
	char word[N];
	printf("Please enter number of word:");
	scanf("%d", psize);
	char** temp = (char**)malloc((*psize) * sizeof(char*));
	if (temp == NULL)
		return NULL;
	printf("Please enter word:");
	for (i = 0; i < *psize; i++)
	{
		scanf("%s", word);
		temp[i] = (char*)malloc((strlen(word) + 1) * sizeof(char));
		if (temp[i] == NULL)
			return NULL;
		strcpy(temp[i], word);
	}
	return temp;
}

char** add(char** arr, int* psize, char* str)//add one word
{
	{
		int i, flag = 0;
		char** tempArr = { NULL };

		for (i = 0; i < *psize; i++)
		{
			if (strcmp(arr[i], str) == 0)
				flag = 1;
		}

		if (flag == 0)
		{
			*psize += 1;

			tempArr = (char**)malloc(*psize * sizeof(char*));
			if (arr == NULL)
			{
				*psize = *psize - 1;
				return NULL;
			}

			for (i = 0; i < *psize; i++) 
			{
				if (i < *psize - 1) 
				{
					tempArr[i] = (char*)malloc(strlen(arr[i]));
					if (tempArr[i] == NULL)
						return NULL;
					strcpy(tempArr[i], arr[i]);
				}
				else
				{
					tempArr[i] = (char*)malloc(strlen(str) + 1);
					if (tempArr[i] == NULL)
						return NULL;
					strcpy(tempArr[i], str);
				}
			}
		}

		free(arr);

		if (flag == 1)
			return NULL;

		return tempArr;
	}
}

void twice(char** arr, int size, int index)//duplicate the word in the index
{
	char temp[N] = { NULL };
	strcpy(temp, arr[index]);
	strcat(temp, arr[index]);
	arr[index] = (char*)malloc(strlen(arr[index])* sizeof(char));
	strcpy(arr[index], temp);
}

int find(char** arr, int size, char* str)//find the index of the word
{
	int i;
	for (i = 0; i < size; i++)
		if (strcmp(arr[i], str) == 0)
			return i;
	return -1;
}

void print(char** arr, int size)//print the arr
{
	int i;
	for (i = 0; i < size; i++)
		printf("%s ", arr[i]);
	printf("\n");
}