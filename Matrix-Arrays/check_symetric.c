#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int create(int x[size][size], int a, int b);
int transponse(int x[size][size], int y[size][size], int a);
int printt(int x[size][size], int y[size][size], int c);
int check(int x[size][size], int y[size][size], int c);

void main()
{
	srand(time(NULL));

	int x[size][size], trans[size][size];
	int upper, lower;

	printf("Enter the upper number: ");
	scanf_s("%d", &upper);

	printf("Enter the lower number: ");
	scanf_s("%d", &lower);

	create(x, upper, lower);
	transponse(x, trans, 3);
	printt(x, trans, 3);
	check(x, trans, 3);

	system("pause");

}
int create(int x[size][size], int a, int b)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
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
int check(int x[size][size], int y[size][size], int c)
{
	int cont = 0;

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (y[j][i] == x[i][j])
			{
				cont++;
			}
		}
	}

	if (cont > 0)
	{
		printf("That array is not symetric!\n\n");
	}
	else
	{
		printf("That array is symetric!\n\n");
	}

	return 0;

}