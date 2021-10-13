#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

int bubble(int x[size], int y[size], int a);
int insert(int y[size], int z[size], int a, int b);
int place_sort(int x[size], int y[size+1], int a);

void main()
{
	srand(time(NULL));

	int normal[size], upper = 40, lower = 1, sort[size], insertt[size+5],insort[size+1];

	for (int i = 0; i < size; i++)
	{
		normal[i] = rand() % (upper - lower + 1) + lower;
	}

	for (int i = 0; i < size; i++)
	{
		printf("\t%d", normal[i]);
	}

	printf("\n\n");

	bubble(normal,sort, size);
	

	for (int i = 0; i < size; i++)
	{
		printf("\t%d",sort[i]);
	}
	printf("\n\n");
	insert(sort, insertt, size, size + 5);

	for (int i = 0; i < size+5; i++)
	{
		printf("\t%d", insertt[i]);
	}
	printf("\n\n");
	
	place_sort(sort,insort, size);
	
	for (int i = 0; i < size + 1; i++)
	{
		printf("\t%d", insort[i]);
	}

	printf("\n\n");
	system("pause");

}

int bubble(int x[size],int y[size], int a )
{
	int temp=0;

	for (int i = 1; i < a ; i++)
	{
		for (int j = 0; j <= a - 2; j++)
		{
			if (x[j] > x[j + 1])
			{
				temp = x[j];
				x[j]= x[j + 1];
				x[j + 1] = temp;
			}
		}	
	}

	for (int j = 0; j < a; j++)
	{
		y[j] = x[j];
	}
   
	return y[size];

}
int insert(int y[size], int z[size], int a, int b)
{
	int numb, place;

	printf("Enter a number to place it somwhere you want: ");
	scanf_s("%d", &numb);

	while (1)
	{
		printf("Which index do you want to place the number to? ");
		scanf_s("%d", &place);

		if (place<0 || place>b)
		{
			printf("Error!!! Invalid index!\n\n");
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < a; i++)
	{
		z[i] = y[i];
	}

	int cont = 0,cont2=0;

	if (place > a - 1)
	{
		z[place] = numb;
	}
	else
	{
		
		for (int i = a; i > place; i--)
		{
			z[i] = z[i - 1];

		}
		z[place] = numb;
	}

	return z[size];

}
int place_sort(int x[size], int y[size+1], int a)
{
	int numb,check=0;

	printf("Enter a number to place it somwhere you want: ");
	scanf_s("%d", &numb);

	for (int i=0;i<size;i++)
	{
		y[i] = x[i];
	}

	for (int i = 0; i < a; i++)
	{
		if (numb <= y[i] && check==0)
		{
			for (int j = a; j > i; j--)
			{
				y[j] = y[j - 1];
			}
			y[i] = numb;
			check++;
			break;
		}
		
		if(i==a-1 && check==0)
		{
			y[i + 1] = numb;
		}
	}

	return y[size+1];
}