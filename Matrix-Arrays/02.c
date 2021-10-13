#include <stdio.h>
#include <stdlib.h>
#define MAX_SÝZE 1000

void main()
{
	srand(time(NULL));

	int a[MAX_SÝZE], i,size;

	printf("Enter the number of elements on the list: ");
	scanf_s("%d", &size);

	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 6 + 3;

		printf("a[%d]= %d\n", i, a[i]);

	}


	printf("\n\n");
	system("pause");

}