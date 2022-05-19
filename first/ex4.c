/* Assignment: 4
Author: Adir Melker, ID: 316614569*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int exam, project, av1, av2, av3, av4, av5,avtotal,final;
	printf("Please enter the exam score : \n");
	scanf("%d", &exam);
	if (exam >= 56)
	{
		printf("Please enter the project score :\n");
		scanf("%d", &project);
		printf("Please enter all 5 homework scores :\n");
		scanf("%d %d %d %d %d", &av1, &av2, &av3, &av4, &av5);
		avtotal = (av1 + av2 + av3 + av4 + av5) / 5;
		final = exam * 0.7 + project * 0.1 + avtotal * 0.2;
		printf("Your score is : %d\n", final);
		printf("Great job you pass\n");
	}
	else
	{
		printf("Your score is %d\n", exam);
		printf("You didn't pass\n");
	}
	return 0;
}

