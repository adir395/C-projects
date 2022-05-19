/* Assignment: 4
Author: Adir Melker, ID: 316614569
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 50
void str_statistics(char* str, int* smallLetter, int* capitalLetter, int* digits);

void main()
{
	int smallLetter, capitalLetter, digits;
	char str[N];
	printf("Please enter a string: \n");
	gets(str);
	str_statistics(str,&smallLetter,&capitalLetter,&digits);
	printf("%d small letters\n", smallLetter);
	printf("%d capital letters\n", capitalLetter);
	printf("%d digits\n", digits);
}

void str_statistics(char *str,int *smallLetter, int *capitalLetter, int *digits)
{
	int i;
	*smallLetter=0, *capitalLetter=0, *digits=0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			*smallLetter+=1;
		if (str[i] >= 'A' && str[i] <= 'Z')
			*capitalLetter+=1;
		if (str[i] >= '0' && str[i] <= '9')
			*digits+=1;
	}

}