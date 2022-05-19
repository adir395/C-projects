/* Assignment: 5.1
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#define N 80
#include <stdio.h>
int SumEvenDigits(long num);
long CreateNumber(long number);
int CheckArithmeticSeries(long Number, int Diff);
void checkEven(int* arr, int size, int* n, int* o);
int checkSer(int* arr, int size);
int Symmetric(char* begin, char* end);
void Reducing(char* str);

void main()
{
	int arr[] = { 1,3,5,7,9 }, arr2[] = {1,4,24,-88,75,70,-35,42};
	int size = 5,size2=8,diff=2;
	int* n = NULL, * o = NULL;
	long i=46729,number=13579;
	char str[N] = "Th8j23$%2kmn6}3h", str2[N] = "asdfghjkllkjhgfdsa";
	printf("%d\n", SumEvenDigits(i));
	printf("%d\n", CreateNumber(i));
	printf("%d\n", CheckArithmeticSeries(number, diff));
	checkEven(arr2, size2, &o, &n);
	printf("%d %d\n",o,n);
	printf("%d\n", checkSer(arr, size));
	printf("%d\n", Symmetric(str2[0], str2[17]));
	Reducing(str);
}

int SumEvenDigits(long num)
{
	if (num == 0)
		return 0;
	if (num % 2 == 0)
		return SumEvenDigits(num / 10) + num % 10;
	SumEvenDigits(num / 10);
}

long CreateNumber(long number)
{
	if (number == 0)
		return 0;
	if (number % 2 != 0)
		return CreateNumber(number / 10) * 10 + number % 10;
	CreateNumber(number / 10);
}

int CheckArithmeticSeries(long Number, int Diff)
{
	if (Number >= 0 && Number <= 9)
		return 1;
	if (Number % 10 - (Number / 10) % 10 != Diff)
		return 0;
	if (Number % 10 - (Number / 10) % 10 == Diff)
		CheckArithmeticSeries(Number / 10, Diff);
}

void checkEven(int* arr, int size, int* n, int* o)
{
	if (size == 0)
		return 0;
	if (arr[size - 1] < 0)
		*n += 1;
	if (arr[size - 1] % 2 != 0)
		*o += 1;
	checkEven(arr, size-1, n, o);
}

int checkSer(int* arr, int size)
{
	if (size == 0)
		return 1;
	if (arr[size - 1] < arr[size - 2])
		return 0;
	if (arr[size - 1] > arr[size - 2])
		checkSer(arr, size - 1);
}

int Symmetric(char* begin, char* end)
{
	if (begin == end||end-begin==1)
		return 1;
	if (*begin != *end)
		return 0;
	if (*begin == *end)
		Symmetric(begin + 1, end - 1);
}

void Reducing(char* str)
{
	if (*str == '\0')
		return;
	Reducing(str + 1);
	if (*str >= '0' && *str <= '9')
		printf("%c", *str);
}