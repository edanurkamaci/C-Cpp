#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prime_test(int x);

void main()
{
	srand(time(NULL));

	int number,divider,control;
	int prime_divider[20];
	int count = 0,flag=0;


	printf("Enter a number: ");
	scanf_s("%d", &number);

	//number = rand() % 100;

	for (int i = number ; i > 1; i--)
	{
		control = number % i;
		if (control == 0)
		{
			divider = i;

			if (prime_test(divider) == 1)
			{
				prime_divider[count] = divider;
				count++;
				flag++;
			}
			
		}
		
	}
	if (flag == 0)
	{
		printf("\nTHERE IS NO DIVIDER THAT IS PRIME!!!");
	}
	else
	{
		printf("\nPrime divider of %d is : ", number);

		for (int j = count - 1; j >= 0; j--)
		{
		    printf("%d  ", prime_divider[j]);
		
		}
	}
	

	printf("\n\n");
	system("pause");

}
int prime_test(int x)
{
	int cont,b=0;

	for (int j = x - 1; j > 1; j--)
	{
		cont = x % j;
		if (cont == 0)
		{
			b++;
			break;
		}
	}

	if (b > 0)
		return -1;
	else if(b==0)
		return 1;
}