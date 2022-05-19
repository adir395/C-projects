/* Assignment: 3
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float num1;
	int num2;
	printf("Please enter a float number :\n");
	scanf("%f", &num1);
	printf("The value is : %.4f\n",num1);
	printf("The integer value is : %.0f\n", num1);
	num2 = num1;
	printf("The integer in hexadecimal base is: 0x%x\n", num2);
	printf("The char is : %c",num2);
	return 0;
}