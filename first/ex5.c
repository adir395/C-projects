/* Assignment: 5
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int num1, min, max;
	printf("Please Enter a number between 0 and 9999 \n");
	scanf("%d", &num1);
	min = num1 % 10;
	if ((num1 >= 1000)&&(num1<=9999))
	{
		printf("the min is %d\n", min);
		max = num1/1000;
		printf("The max is : %d\n", max);
	}
	 else if ((num1>=100)&&(num1<=999))
	{
		printf("the min is %d\n", min);
		max = num1 / 100;
		printf("The max is : %d\n", max);
	}
	 else if ((num1>=10)&&(num1<=99))
	{
		printf("the min is %d\n", min);
		max = num1 / 10;
		printf("The max is : %d \n", max);
	}
	 else if ((num1 >= 0) && (num1 <= 9))
	{
		printf("the min is %d\n", num1);
		printf("The max is : %d \n", num1);
	}
	else
		printf("Wrong number\n");
	return 0;
}