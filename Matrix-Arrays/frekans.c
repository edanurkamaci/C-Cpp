#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int main()
{
	srand(time(NULL));

	int freak[size],upper,lower;

	printf("Enter lower and upper numbers: ");
	scanf_s("%d%d", &lower,&upper);

	for (int i = 0; i < size; i++)
	{
		freak[i] = rand() % (upper - lower + 1) + lower;
	}
    
	printf("\n");

	for (int j =0; j < size; j++)
	{
		for (int k = 0; k < freak[j]; k++)
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		printf("\t%d", freak[i]);
	}

	printf("\n\n");
	system("pause");

	return 0;

}