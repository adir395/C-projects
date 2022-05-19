/* Assignment: 2
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.141592654
int main()
{
	int triangle = 1, rectangle = 2, square = 3, cycle = 4,po;
	float base, height, length, area,radius;
    printf("please enter number of the shape do you want triangle=1, rectangle=2, square=3, cycle=4 \n");
	scanf("%d", &po);
	switch (po)
	{
	case 1:
		printf("You choose triangle \n");
		printf("Please enter the base : \n");
		scanf("%f", &base);
		printf("Please enter the height : \n");
		scanf("%f", &height);
		area = (base * height) / 2;
		printf("The area of this triangle is : %.3f\n", area);
		break;

	case 2:
		printf("You choose rectangle \n");
		printf("Please enter the length : \n");
		scanf("%f", &length);
		printf("Please enter the height : \n");
		scanf("%f", &height);
		area = length * height;
		printf("The area of this rectangle is : %.3f\n", area);
		break;

	case 3:
		printf("You choose square \n");
		printf("Please enter the height : \n");
		scanf("%f", &height);
		area = height * height;
		printf("The area of this square is : %.3f\n", area);
		break;

	case 4:
		printf("You choose cycle \n");
		printf("Please enter the radius : \n");
		scanf("%f", &radius);
		area = radius * radius * PI;
		printf("The area of this cycle is : %.10f\n", area);
		break;

	default: printf("You are stupid, you enter wrong number !!!!\n");
	}
	return 0;
}