/* Assignment: 5.2
Author: Adir Melker, ID: 316614569
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int DayNumber; //1-31
	int WorkHours; // 1-12
} WorkDay;
typedef struct {
	long ID;//ת.ז.
	int HourlySal; // שכר לשעה
	int workdays; //מספר ימי עבודה של העובד בחודש הנוכחי
	WorkDay* wd; //מצביע למערך דינאמי של נתוני ימי העבודה בחודש נוכחי 
	double salary; //  סה"כ שכר עבודה של העובד בחודש נוכחי
} Worker;
void InputWorkDay(WorkDay* pWD);
void PrintWorkDay(WorkDay wd);
void InputWorker(Worker* pW);
void PrintWorker(Worker w);
Worker* InitFactory(int* pSize);
void PrintFactory(Worker* pWorker, int size);
void  CalculateSalary(Worker* pWorker, int size);

int main() {
	Worker* pFactory = NULL;
	int size,i;
	pFactory = InitFactory(&size);
	CalculateSalary(pFactory, size);
	PrintFactory(pFactory, size);
	for (i = 0; i < size; i++)
		free(pFactory[i].wd);
	free(pFactory);
	return 0;
}

void InputWorkDay(WorkDay* pWD)
{
	printf("Please enter day number: ");
	scanf_s("%d", &(pWD->DayNumber));
	printf("Please enter how many hours: ");
	scanf_s("%d", &(pWD->WorkHours));
	printf("\n");
}

void PrintWorkDay(WorkDay wd)
{
	printf("%d Days\n", wd.DayNumber);
	printf("%d Hours\n", wd.WorkHours);
}

void InputWorker(Worker* pW)
{
	int i;
	printf("ID: ");
	scanf_s("%ld", &(pW->ID));
	printf("Hourly salary: ");
	scanf_s("%d", &(pW->HourlySal));
	printf("Work days: ");
	scanf_s("%d",&(pW->workdays));
	pW->wd = (WorkDay*)malloc((pW->workdays) * sizeof(WorkDay));
	if (pW->wd == NULL)
		return;
	for (i = 0; i < pW->workdays; i++)
		InputWorkDay(&(pW->wd[i]));
}

void PrintWorker(Worker w)
{
	int i;
	printf("Worker ID: %ld\n", w.ID);
	printf("Is hourly salary is:%d\n", w.HourlySal);
	printf("He work %d days:\n", w.workdays);
	for (i = 0; i < w.workdays; i++)
		PrintWorkDay(w.wd[i]);
	printf("Is salary is :%.4lf \n", w.salary);
}

Worker* InitFactory(int* pSize)
{
	int i;
	Worker* arr = NULL;
	printf("Please enter number of workers: ");
	scanf_s("%d", pSize);
	printf("\n");
	arr = (Worker*)malloc(*pSize * sizeof(Worker));
	if (arr == NULL)
		return 0;
	for(i=0;i<*pSize;i++)
	{ 
		arr[i].wd = (WorkDay*)malloc(1 * sizeof(WorkDay));
		if (arr[i].wd == NULL)
			return 0;
		InputWorker(&arr[i]);
	}
	return arr;
}

void PrintFactory(Worker* pWorker, int size)
{
	int i;
	for (i = 0; i < size; i++)
		PrintWorker(pWorker[i]);
}

void  CalculateSalary(Worker* pWorker, int size)
{
	int i,j, hours;
	for (i = 0; i < size; i++)
	{
		hours = 0;
		for (j = 0; j < pWorker[i].workdays; j++)
			hours += pWorker[i].wd[j].WorkHours;
		pWorker[i].salary = pWorker[i].HourlySal * hours;
	}
}