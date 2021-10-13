#include <stdio.h>
#include <stdlib.h>
#define MAX_SÝZE 1000

void main()
{
	srand(time(NULL));

	int list[MAX_SÝZE], i, size,sum=0;
	double mean;
	
	do
	{
		printf("Enter number of elements on the list: ");
		scanf_s("%d", &size);

		if (size > 1000 || size < 0)
		{
			printf("Error!!! The size you entered is undefined!\n");
		}


	} while (size>1000 || size<0);
	

	for (i = 0; i < size; i++)
	{/*
		printf("list[%d]= ",i);
		scanf_s("%d", &list[i]);
	 */
		list[i] = rand() % 10 + 2;
		sum += list[i];

	}

	printf ("\n      ARRAY      \n");
	printf("--------------------\n\n");

	for (i = 0; i < size; i++)
	{

		printf("list[%d]= %d\n", i, list[i]);

	}

	mean = (double)sum / size;

	printf("\nSum= %d\n", sum);
	printf("Average: %.2lf\n", mean);


	printf("\n\n");
	system("pause");

}