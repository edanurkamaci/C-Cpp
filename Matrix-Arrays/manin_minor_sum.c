#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int majorr(int x[size][size],  int c);
int minorr(int x[size][size], int c);

void main()
{
	srand(time(NULL));

	int x[size][size],ma,mi;
	int upper, lower;

	printf("Enter the upper number: ");
	scanf_s("%d", &upper);

	printf("Enter the lower number: ");
	scanf_s("%d", &lower);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			x[i][j] = rand() % (upper - lower + 1) + lower;
		}
	}
	ma =majorr(x, 5);
	mi =minorr(x, 5);
	printf("\n\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("\t%d", x[i][j]);
		}
		printf("\n\n");
	}
	
	printf("Sum of major diognal: %d\n", ma);
	printf("Sum of minor diognal: %d\n", mi);

	printf("\n\n");
	system("pause");
}
int minorr(int x[size][size], int c)
{
	int sum=0,count=c-1;

	for (int i = 0; i < c; i++)
	{
		sum += x[i][count];
		count--;
	}

	return sum;
}
int majorr(int x[size][size], int c)
{
	int sum = 0;

	for (int i = 0; i < c; i++)
	{
		sum += x[i][i];
	}

	return sum;
}