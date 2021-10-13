#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int binary(int x[], int a,int b);

void main()
{
	srand(time(NULL));

	int binar[size], upper=40, lower=1,number,times=0,fake;

	number =rand() % ((upper - lower + 1) + lower);

	fake = number;

	while (fake > 0)
	{
		fake = fake / 2;
		times++;
	}

	binary(binar, number,times);

	printf("\nNumber: %d\n", number);
	if (times <= 4)
	{
		for (int i = 0; i < 4; i++)
		{
			printf("\t%d", binar[i]);
		}
	}
	else
	{
		for (int i = 0; i < times; i++)
		{
			printf("\t%d", binar[i]);
		}
	}
	printf("\n\n");
	system("pause");

}

int binary(int x[], int a, int b)
{
	int new_numb= a;

	while (new_numb > 0)
	{
		if (b <= 4)
		{
			for (int i = 3; i >= 0; i--)
			{
				if (new_numb % 2 == 0)
					x[i] = 0;
				else
					x[i] = 1;

				new_numb = new_numb / 2;
			}
		}
		else
		{
			for (int i = b-1; i >= 0; i--)
			{
				if (new_numb % 2 == 0)
					x[i] = 0;
				else
					x[i] = 1;

				new_numb = new_numb / 2;
			}
		}
	}

	return x[size];
}