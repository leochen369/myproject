#include<stdio.h>
#include<stdlib.h>

#define student 3
#define exams 4
void minimum(int grade[][exams], int pupils, int tests);
void maximum(int grade[][exams], int pupils, int tests);
void average(int grade[][exams], int pupils, int tests);
void printfarray(int grade[][exams], int pupils, int tests);
void printfmenu();
int main() {
	int studentgrades[student][exams] = { {77,68,86,73},{96,87,89,78},{70,90,86,81} };
	void(*processgrade[4])(int[student][exams], int, int)
		= { printfarray,minimum,maximum,average };
	int choice = 0;
	while (choice != 4) {
		do {
			printfmenu();
			scanf_s("%d",&choice);

		} while (choice < 0 || choice>4);
		if (choice != 4) {
			(*processgrade[choice])(studentgrades, student, exams);
		}
		else
		{
			printf("\tprogram ended.\n");
		}
	
	}
	system("pause");
	return 0;
}
void minimum(int grades[][exams], int puplis, int tests)
{
	int i, j;
	int lowgrade = 100;
	for (i = 0; i < puplis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] < lowgrade)
			
				lowgrade = grades[i][j];
			
		}
	}
	printf("\n\tthe lowest grade is %d", lowgrade);
	printf("\n");
}
void maximum(int grades[][exams], int puplis, int tests)
{
	int i, j;
	int highgrade = 0;
	for (i = 0; i < puplis; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j] > highgrade)

				highgrade = grades[i][j];

		}
	}
	printf("\n\tthe highest grade is %d", highgrade);
	printf("\n");
}
void average(int grades[][exams], int puplis, int tests)
{
	int i, j,total;
	int lowgrade = 100;
	for (i = 0; i < puplis; i++)
	{
		total = 0;
		for (j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
		printf("\n\tthe average grade for student %d is %.1f", i + 1, (double)total / tests);
	}
	printf("\n");
}
void printfarray(int grades[][exams], int puplis, int tests)
{
	int i, j;
	printf("\n\t\t\t[0]     [1]    [2]    [3]");
	for (i = 0; i < puplis; i++)
	{
		printf("\n\tstudentgrades[%d]", i);
		for (j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}
void printfmenu()
{
	printf("\n");
	printf("\tenter a choice:\n");
	printf("\t0print the array of grades\n");
	printf("\t1 find the minimum grade\n");
	printf("\t2 find the maximum grade\n");
	printf("\t3 print the average on all tests for each student\n");
}