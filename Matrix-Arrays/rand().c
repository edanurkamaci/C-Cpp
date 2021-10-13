#include <stdio.h>
#include <stdlib.h>


void main()
{
	int b, i,a;
	srand(time(NULL));

	printf("How many elements are there on your list: ");
	scanf_s("%d", &b);
	
	

	for (i = 0; i < b; i++)
	{
		a = rand() % 9+1;
		printf("a= %d\n", a);

	}


	printf("\n\n");
	system("pause");

}