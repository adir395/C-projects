/* Assignment: 2
Author: Adir Melker, ID: 316614569 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printMenu();
void info();
int isEven(int a);
int isPositive(int b);
int countDigits(int c);
void printFloatMax();
int getLongNumber();
int reverseDigits(int e);
void maxCountDivisors();
int countDiv(int num);
int mostCount(int a);
int printMaxCountDivisors(int low,int high);
void countSpecialNumbers();
int printSpecialNumbers(); 
void allShapes();
int triangle(int x);
int square( int x);
int rectangle(int x, int y);

int main()
{
	int num1;//get number from user
	do{
		printMenu();
	scanf_s("%d", &num1);
		switch (num1)
		{
		case 1:
			info();
			break;
		case 2:
			printFloatMax();
			break;
		case 3:
			getLongNumber();
			break;
		case 4:
			maxCountDivisors();
			break;
		case 5:
			countSpecialNumbers();
			break;
		case 6:
			allShapes();
			break;
		case 7:
			printf("Have a nice day\n");
			return 0;
		}
	}while (num1);
	return 0;
}
void printMenu()//print menu
{
	printf("\nMenu :\n");
	printf("Please choose an option: \n");
	printf("1- info\n");
	printf("2- Print the number with the max float\n");
	printf("3- Reverse the digits and add 5 \n");
	printf("4- Pick the number that has the max amount of divisors\n");
	printf("5- Print the special numbers\n");
	printf("6- Print shapes\n");
	printf("7- Exit\n");
}

void info()//get number from user
{
	int num1;
	printf("Please enter a number: \n");
	scanf_s("%d", &num1);
	switch (isEven(num1))
	{
	case 0:
		printf("%d Is odd\n", num1);
		break;
	case 1:
		printf("%d Is even\n", num1);
	}
	switch (isPositive(num1))
	{
	case 0:
		printf("%d Is negative\n", num1);
		break;
    case 1:
		printf("%d Is positive\n", num1);
    }
	printf("%d has %d digits\n", num1,countDigits(num1));
}

int isEven (int a)//check if number is odd or even
{
	if ((a % 2) == 0)
		return 1;
	else 
		return 0;
}

int isPositive(int b)//if positive or not
{
	if (b > 0)
		return 1;
	else
		return 0;
}

int countDigits(int c)//how many digits
{
	int count=0,b=c;
	while (c)
	{
		c = c / 10;
		count++;
	}
	return count;
}

void printFloatMax()
{
	float num1, max = 0;
	int count = 0, pos;
	printf("Enter number:\n");
	scanf_s("%f", &num1);
	while (num1) //always get number from the user that different from 0
	{
		count++;//count the position of the number
		if ((max - (int)max) < (num1 - (int)num1)) //check if the inger part after the . is bigger that the last one
		{
			max=num1;
			pos=count;
		}
		scanf_s("%f", &num1);
	}
	printf("%.5f\n%d",max,pos);
}

int getLongNumber()
{
	int num1;
	printf("Please enter a number: \n");
	scanf_s("%d", &num1);
	printf("%d\n", reverseDigits(num1) + 5);//call the fonction and add 5
	return 0;
}

int reverseDigits(int e)
{
	int h = 0, j = 0;
	while (e)
	{
		j = e % 10;//the last number
		h = h * 10 + j;//reverse the digit
		e = e / 10;
	}
	return h;
}
void maxCountDivisors()
{
	int low, high;
	do
	{
		printf("Please enter 2 numbers\n");
		scanf_s("%d %d", &low, &high);
		if (low > high || high < 0 || low < 0)
			printf("You enter inccorect number try again\n");
	} while (low > high || high < 0 || low < 0);

   printMaxCountDivisors(low,high);

}
int countDiv(int num)//fonction that check how many divisiors have the number and return thae result
{
	int x,count=0;
	for (x = 1; x <= num; x++)
		if ((num % x) == 0)
			count++;
	return count;
}

int printMaxCountDivisors(low, high)
{
	int y,max=0,z=0,a=0;
	for (y = low; y < high; y++) {
		if (countDiv(y) <= countDiv(high))
			max = countDiv(high);
		else
			max = countDigits(y);
	}
	
		
	printf("%d Has %d div\n",y,max);
	return max;
}


void countSpecialNumbers()
{
	printf("%d", printSpecialNumbers() );
}


int printSpecialNumbers()
{
	int x, i,k,y,z,count=0;
	for (x = 1000; x <= 9999; x++)
	{
		i = x % 10;
		k = (x / 10) % 10;
		z = (x / 100) % 10;
		y = x / 1000;
		if (i != k && i != z)//check all the diffrence option
			if (i != y && k != z)
				if (k != y && z != y)
					count++;
	}
	return count;//return the count to the call fonction
}

void allShapes()
{
	int choise, size, height, width;
	do {
		printf("Please enter what Geometric shape do you want\n");
		printf("1.Triangle\n2.Square\n3.Rectangle\n");
		scanf_s("%d", &choise);
		if ((choise <= 0 || choise > 3))
			printf("You enter wrong number try again\n\n");
	} while (choise <= 0 || choise > 3);
    switch (choise)
		{
		case 1:
			printf("Enter size: ");
			scanf_s("%d", &size);
			triangle(size);
			break;
		case 2:
			printf("Enter size: ");
			scanf_s("%d", &size);
			square(size);
			break;
		case 3:
			printf("Enter height and width:");
			scanf_s("%d %d", &height, &width);
			rectangle(height, width);
		}
}

int triangle(int x)
{
	int i, j;
	for (j = 1; j <= x; j++) 
	{
		for (i = 1; i <= j; i++)
			printf("*");
	printf("\n");
	}
	return 0;
}

int square(int x)
{
	int i,k;
	for (i = 0; i < x; i++)
	{
		for (k= 1; k <= x; k++)
			printf("*");
		printf("\n");
	}
	return 0;
}
int rectangle(int x , int y)
{
	int i,j;
	for (i = 1; i <=x ; i++)
	{
		for (j = 1; j <= y; j++)
		{

			if (j > 1 && j < y && i>1 && i<x)
				printf("$");
			else
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

