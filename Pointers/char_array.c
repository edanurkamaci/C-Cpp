#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

void create(char x[size], int y);

void main()
{
	char squence[size], *p, q;

	create(squence, size);

	for (int j = 0; j < size; j++)
	{
		p = &squence[j];
		q = *p;
		printf(" %d. Location: %x \t %d. Value: %c\n", j + 1, p, j + 1, q);

	}
	printf("\n\n");
	system("pause");
}
void create(char x[size], int y)
{
	srand(time(NULL));

	for (int i = 0; i < y; i++)
	{
		x[i] = 'A'+(rand() % 10);
	}
}