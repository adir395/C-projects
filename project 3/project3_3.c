/* Assignment: 3.3
Author: Adir Melker, ID: 316614569
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 80
void rotate_left(char str1[]);
void rotate_right(char str2[]);
int intersection(char str1[], char str2[]);

void main()
{
	char str1[N],str2[N];
	printf("Please enter the first sentence:\n");
	gets(str1);
	printf("Please enter the second\n");
	gets(str2);
	rotate_right(str1);
	rotate_right(str1);
	rotate_left(str2);
	rotate_left(str2);
	rotate_left(str2);
	printf("First string after 2 rotations right: ");
    puts(str1);
	printf("Second string after 3 rotations left: ");
	puts(str2);
	printf("Intersection of the last 2 strings:%d", intersection(str1, str2));
}
void rotate_left(char str1[N])
{
	int i, x=0;
	char temp1[N] = { '\0' }, temp2[N] = { '\0' };
	for (i = 0; str1[i] != ' '; i++)
		temp1[i] = str1[i];
	for (i++; str1[i] != '\0'; i++,x++)
		temp2[x] = str1[i];
	strcat(temp2, " ");
	strcat(temp2, temp1);
	strcpy(str1,temp2);
}

void rotate_right(char str2[N])
{
	int i, x = 0,k;
	char temp1[N] = { '\0' }, temp2[N] = { '\0' };
	for (i = strlen(str2); str2[i] != ' '; i--);
	for (k = 0; k < i; k++)
		temp2[k] = str2[k];
	for (i++; str2[i] != '\0'; i++,x++)
		temp1[x] = str2[i];
	
	strcat(temp1, " ");
	strcat(temp1, temp2);
	strcpy(str2,temp1);

}
int intersection(char str1[], char str2[])
{
	int i, count = 0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
		if (str1[i] == str2[i] || str1[i] == str2[i] + ('a' - 'A') || str1[i] == str2[i] - ('a' - 'A'))
			if (str1[i]!=' '&&str2[i]!=' ')
				count++;
	return count;
}