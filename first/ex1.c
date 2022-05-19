/* Assignment: 1
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define first_price 10.20
#define every_km 1.30
#define luggage 2.00
int main()
{
	float di,total_price;
	int bag;
	printf("Please enter the distance : \n");
	scanf("%f", &di);
	printf("Please enter how many luggage : \n");
	scanf("%d", &bag);
	total_price = (di* every_km) + (bag * luggage) + first_price;
	printf("The total price for the travel is : %.3f", total_price);
	return 0;
}
