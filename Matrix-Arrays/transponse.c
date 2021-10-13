#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int create(int x[size][size], int a, int b);
int transponse(int x[size][size], int y[size][size], int a);
int printt(int x[size][size],int y[size][size], int c);

void main()
{
	srand(time(NULL));

	int x[size][size], ma, mi,trans[size][size];
	int upper, lower;

	printf("Enter the upper number: ");
	scanf_s("%d", &upper);

	printf("Enter the lower number: ");
	scanf_s("%d", &lower);

	create(x, upper, lower);
	transponse(x, trans, 5);
	printt(x, trans, 5);

	

	system("pause");

}
int create(int x[size][size], int a,int b)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x[i][j] = rand() % ((a - b + 1) + b);
		}
	}

	return x[size][size];
}


int transponse(int x[size][size], int y[size][size], int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			y[j][i] = x[i][j];
		}
	}

	return y[size][size];
}
int printt(int x[size][size], int y[size][size], int c)
{
	printf("\n\n");
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("\t%d", x[i][j]);
		}
		printf("\n\n");
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
}
