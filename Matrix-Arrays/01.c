#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int matrix1(int x[size][size], int a,int b,int c);
int matrix2(int y[size][size], int a,int b,int c);
int sum(int x[size][size], int y[size][size], int z[size][size], int c);

void main()
{
	srand(time(NULL));

	int m1[size][size], m2[size][size], summ[size][size];
	int upper, lower;

	printf("Enter the upper number: ");
	scanf_s("%d", &upper);

	printf("Enter the lower number: ");
	scanf_s("%d", &lower);

	matrix1(m1, upper, lower, 5);
	matrix2(m2, upper, lower, 5);
	sum(m1,m2,summ,5);


	system("pause");

}
int matrix1(int x[size][size], int a,int b, int c)
{

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			x[i][j] = rand() % (a - b + 1) + b;
		}
	}
	printf("\n\n");
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("\t%d", x[i][j]);
		}
		printf("\n\n");
	}
	

	return x[size][size];
}
int matrix2(int y[size][size], int a, int b, int c)
{

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			y[i][j] = rand() % (a - b + 1) + b;
		}
	}
	printf("\n\n");
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("\t%d", y[i][j]);
		}
		printf("\n\n");
	}

	return y[size][size];
}
int sum(int x[size][size], int y[size][size], int z[size][size], int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			z[i][j] = x[i][j] + y[i][j];
		}
	}
	printf("\n\n");
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("\t%d", z[i][j]);
		}
		printf("\n\n");
	}

	return z[size][size];
}