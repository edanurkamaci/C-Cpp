#include <stdio.h>
#include <stdlib.h>
#define max_size 100

void array(int[],int);
void modify(int);

void main()
{
	srand(time(NULL));

	int size, B[max_size];
	int b = 9;


	printf("Enter number of size: ");
	scanf_s("%d", &size);

	for (int j = 0; j < size; j++)
	{
		B[j] = rand() % 10;
		printf("%d\t", B[j]);
	}

	array(B, size);
	modify(b);

	printf("\n\n");

	for ( int k = 0;  k < size; k++)
	{
		printf("%d\t", B[k]);

	}
	printf("\nb= %d", b);

	printf("\n\n");
	system("pause");

}
void array(int b[],int size)
{

	for (int i = 0; i < size; i++)
	{
		b[i] = 2 * b[i];
	}

}
void modify(int b)
{	
	
	b =  b * 2;

}