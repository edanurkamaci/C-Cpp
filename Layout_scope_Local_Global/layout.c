#include <stdio.h>
#include <stdlib.h>

int x = 0;
int factorial(int n);

void main()
{
	int n,facto;
	x = 2;

	printf("Enter the number: ");
	scanf_s("%d", &n);

	facto = factorial(n);

	printf("%d!= %d\n", n, facto);
	printf("x= %d", x);

	printf("\n\n");
	system("pause");

}

int factorial(int n)
{
	int prod = 1, i;

	for (i = 1; i <= n; i++)
	{
		prod *= i;
	}

	x = 3;

	return prod;
}

