#include <stdio.h>
#include <stdlib.h>
#define MAX_SÝZE 1000


void main()
{
	srand(time(NULL));

	int a[MAX_SÝZE],b[MAX_SÝZE], i, size, suma = 0,sumb=0;
	double meana,meanb;
	int upper, lower;
	int counta = 0, countb = 0;

	do
	{
		printf("Enter number of elements on the lists: ");
		scanf_s("%d", &size);

		if (size > 1000 || size < 0)
		{
			printf("Error!!! The size you entered is undefined!\n");
		}


	} while (size > 1000 || size < 0);

	printf("Enter the upper limit: ");
	scanf_s("%d", &upper);

	printf("Enter the lower limit: ");
	scanf_s("%d", &lower);

	for (i = 0; i < size; i++)
	{/*
		printf("list[%d]= ",i);
		scanf_s("%d", &list[i]);
	 */
		a[i] = (rand() % (upper - lower + 1)) + lower;
		suma += a[i];

	}
	for (i = 0; i < size; i++)
	{/*
		printf("list[%d]= ",i);
		scanf_s("%d", &list[i]);
	 */
		b[i] = (rand() % (upper - lower + 1)) + lower;
		sumb += b[i];

	}

	printf("\n      ARRAY A     \n");
	printf("------------------------\n\n");

	for (i = 0; i < size; i++)
	{

		printf("A[%d]= %d\n", i, a[i]);

	}


	meana = (double)suma / size;
	meanb = (double)sumb / size;

	printf("\nSum= %d\n", suma);
	printf("Mean: %.2lf\n\n", meana);

	printf("      ARRAY B     \n");
	printf("------------------------\n\n");

	for (i = 0; i < size; i++)
	{

		printf("B[%d]= %d\n", i, b[i]);

	}
	printf("\nSum= %d\n", sumb);
	printf("Mean: %.2lf\n", meanb);

	int mina = a[0], minb = b[0], maxa = a[0], maxb = b[0];

	for (i = 0; i < size; i++)
	{
		if (a[i] > meana)
		{
			counta++;
	    }

		if (a[i] < mina)
		{
			mina = a[i];

		}
		else if (a[i]>maxa)
		{
			maxa = a[i];
		}
		else
		{
			continue;
		}
			
	}

	for (int k = 0; k < size; k++)
	{
		if (b[k] < meanb)
		{
			countb++;
		}
		
		if (b[k] < minb)
		{
			
			minb = b[k];

		}
		else if (b[k] > maxb)
		{
			maxb = b[k];
		}
		else
		{
			continue;
		}

	}
	printf("\nThe number of elements that is greater than mean in array A: %d\n", counta);
	printf("The number of elements that is smaller than mean in array B: %d\n", countb);
	printf("\nMin A: %d\n", mina);
	printf("Max A: %d\n", maxa);
	printf("Min B: %d\n", minb);
	printf("Max B: %d\n", maxb);

	int key;
	printf("\n");
	counta = 0;
	countb = 0;

	while (1)
	{

		printf("Enter a key: ");
		scanf_s("%d", &key);

		if(key!=-1)
		{
			for (i = 0; i < size; i++)
			{
				if (a[i] == key)
				{
					printf("The key is in index %d in A\n", i);
					counta++;
				}
				
			
			}
			for (int j = 0; j < size; j++)
			{
				if (b[j] == key)
				{
					printf("The key is in index %d in B\n", j);
					countb++;
				}
			}
			if (counta == 0 || countb == 0)
			{
				if (counta == 0)
				{
					printf("The key is not exist in A\n");
				}
				if (countb == 0)
				{
					printf("The key is not exist in B\n");
				}
			}
			counta = 0;
			countb = 0;
		
	    }
		else
		{
			break;
		}

		
	}
	int c[MAX_SÝZE*2] , sumc=0;
	double meanc;
	counta = 0;
	countb = 0;

	for (int j = 0; j < 2*size; j++)
	{
		if (j % 2 == 0)
		{
			c[j] = a[counta];
			counta++;
		}
		else
		{
			c[j] = b[countb] ;
			countb++;
		}

	}
	printf("\n      ARRAY C     \n");
	printf("------------------------\n\n");

	for (i = 0; i < 2*size; i++)
	{

		printf("C[%d]= %d\n", i, c[i]);
		sumc += c[i];

	}
	meanc = (double)sumc / (2*size);

	printf("\nSum= %d\n", sumc);
	printf("Mean: %.2lf\n", meanc);

	


	printf("\n\n");
	system("pause");

}