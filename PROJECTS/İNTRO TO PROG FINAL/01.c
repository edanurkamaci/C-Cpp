#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 50

void line(char x[SIZE][SIZE], int z[SIZE], int q[SIZE], int a, int b);
void parabola(char y[SIZE][SIZE], int z[SIZE], int q[SIZE], int a, int b, int c );
void circle(char Q[SIZE][SIZE], int x[SIZE], int x2[SIZE], int y[SIZE], int a, int b, int r);

void main()
{
	int option,z[SIZE],q[SIZE], k[SIZE], l[SIZE], m[SIZE], n[SIZE], p[SIZE];
	char linee[SIZE][SIZE],parabolaa[SIZE][SIZE], circlee[SIZE][SIZE];
	
	while (1)
	{
		while (1)
		{  
			printf("\n********** OPTIONS **********\n");
			printf("1. Line\n");
			printf("2. Parabola\n");
			printf("3. Circle\n");
			printf("4. Exit\n\n");

			printf("Which shape would you like to draw? ---> ");
			scanf_s("%d", &option);

			if (option > 0 && option < 5)
			{
				break;
			}
			else
			{
				printf("!You entered the wrong number!!! Please make sure you've entered correct number for the figure drawing you want!\n");
				
			}
		}

		printf("\n");

		if (option == 4)
		{
			break;
		}
		else
		{
			switch (option)
			{
			    case 1:
			    {
				   int a, b;

				   printf("** Line formula is y= ax+b **\n");

				   while (1)
				   {
					   int x_, y_;

					   printf("-> Please enter the coefficients a and b to draw a line --> ");
					   scanf_s("%d%d", &a, &b);
					   if (a != 0)
					   {
						   x_ =-b/a ;
					   }
					   else
					   {
						   x_ = 0;
					   }
					   y_ = b;

					   if ((y_ >= -20 && y_ <= 20) && (x_ >= -20 && x_ <= 20 ))
					   {
						   if (b == 0 && (a > 20 || a < -20))
							   printf("\n!The point that intersecting the axis is not exist in [-20,20]! Try lower numbers.\n\n");
						   else
						       break;
					   }
					   else
					   {
						   printf("\n!The point that intersecting the axis is not exist in [-20,20]! Try lower numbers.\n\n");
					   }
				   }
				   printf("\n\n");

				   line(linee, z, q, a, b);

				   for (int i = 0; i <41; i++)
				   {
					   printf("\t");
					   for (int j = 0; j <41; j++)
					   {
						   printf("%c", linee[i][j]);

					   }
					   printf("\n");
				   }
				   break;
			    }
				case 2:
				{
					int a, b,c;
					
					printf("** Parabola formula is y = ax^2+bx+c **\n");
					
					while (1)
					{
						int k,r;
						
						while (1)
						{
							printf("-> Please enter the coefficients a, b and c to draw a parabola --> ");
							scanf_s("%d%d%d", &a, &b, &c);
							if (a != 0)
							{
								break;
							}
							else
							{
								printf("\n!If a is zero, we can not say that equation is parabola! Try another number.\n\n");
							}
						}
						r = -(b / (2*a));
						k = (a*r * r) + (r * b) + c;
						if ((k >= -20 && k <= 20) && (r >= -20 && r <= 20))
						{
							break;
						}
						else
						{
							printf("\n!The point of the parabola peak must be in [-20,20]! Try again.\n\n");
						}

					}
					printf("\n\n");

					parabola(parabolaa,k,l, a, b, c);

					for (int i = 0; i < 41; i++)
					{
						printf("\t");
						for (int j = 0; j < 41; j++)
						{
							printf("%c", parabolaa[i][j]);

						}
						printf("\n");
					}
					break;
				}
				case 3:
				{
					int a, b, r;

					printf("** Circle formula is (x-a)^2+(y-b)^2=r^2 **\n");
					while (1)
					{
						int cont1, cont2, cont3, cont4;
						while (1)
						{
							printf("-> Please enter center's coordinates (a,b) and radius(r) --> ");
							scanf_s("%d%d%d", &a, &b, &r);
							if (r != 0 && r>0)
							{
								break;
							}
							else
							{
								printf("\n!There is no way to draw circle if radius is zero or less than zero!!!\n\n");
							}
						}
						cont1 = a + r; cont2 = b + r; cont3 = a - r; cont4 = b - r;
						if (cont1 >= -20 && cont1 <= 20 && cont2 >= -20 && cont2 <= 20 && cont3 >= -20 && cont3 <= 20 && cont4 >= -20 && cont4 <= 20)
						{
							break;
						}
						else
						{
							printf("\n!The boundary points of the circle exceed the interval designated of the coordinate system! Enter lower numbers.\n\n ");
						}
					}
					printf("\n\n");

				    circle(circlee, m, n,p, a, b, r);

					for (int i = 0; i < 41; i++)
					{
						printf("\t");
						for (int j = 0; j < 41; j++)
						{
							printf("%c", circlee[i][j]);

						}
						printf("\n");
					}
					break;
				}
				default:
				{
					continue;
				}
				
			}
		}
	}
	
	printf("\n\n");
	system("pause");
}
void line(char x[SIZE][SIZE], int z[SIZE], int q[SIZE], int a, int b)
{
	int  x1 = -20, y1, count = 0;

	for (int j = 0; j < 41; j++)
	{
		y1 = a*x1 + b ;

		if (y1 <= 20 || y1 >= -20)
		{
			z[count] = 20 - y1;
			q[count] = 20 + x1;
			count++;
		}
		x1++;
	}

	for (int i = 0; i < 41; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (i == z[j])
			{
				if (j == q[j])
					x[i][j] = '*';

			}
			else
			{
				if (i == 20)
				{
					if (j != 20)
						x[i][j] = '-';
					else
						x[i][j] = '|';
				}
				else
				{
					if (j != 20)
						x[i][j] = ' ';
					else
						x[i][j] = '|';
				}
			}
		}
	}
}
void parabola(char y[SIZE][SIZE],int z[SIZE],int q[SIZE], int a, int b,int c)
{
	int  x1=-20, y1,count=0;
	
	for (int j = 0; j < 41; j++)
	{
		y1 = a * pow(x1, 2) + b * x1 + c;

		if (y1 <= 20 || y1 >= -20)
		{
			z[count] = 20 - y1;
			q[count] = 20 + x1;
			count++;
		}
		x1++;
	}

	for (int i = 0; i < 41; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (i == z[j])
			{
				if(j==q[j])
				    y[i][j] = '*';
				
			}
			else
			{
				if (i == 20)
				{
					if (j != 20)
						y[i][j] = '-';
					else
						y[i][j] = '|';
				}
				else
				{
					if (j != 20)
						y[i][j] = ' ';
					else
						y[i][j] = '|';
				}
			}
		}
	}
}
void circle(char Q[SIZE][SIZE], int x[SIZE], int x2[SIZE], int y[SIZE], int a, int b, int r)
{
	double root, roottt;
	int count = 0;
	for (int i = b+r; i >= b-r; i--)
	{
		root = sqrt(r*r - pow((i - b), 2))+a;
		roottt = -sqrt(r*r - pow((i - b), 2)) + a;

		if (root - (int)root == 0)
		{
			x[count] = (int)roottt;
			x2[count] = (int)root;
			y[count] = i;
			count++;
		}

	}

	count = 0;
	int flag=0;

	for (int j = 0; j < 41; j++)
	{
		for (int k =0; k < 41; k++)
		{
			if (j == 20-y[count])
			{
				if ( k == 20 + x[count])
				{
					Q[j][k] = '*';
					flag++;
					
				}
				else if (k == 20 + x2[count])
				{
					Q[j][k] = '*';
					
				}
				else if (j == 20)
				{
					if (k == 20)
						Q[j][k] = '|';
					else
					{
						Q[j][k] = '-';
					}
				}
				else
				{
					if (k == 20)
						Q[j][k] = '|';
					else
						Q[j][k] = ' ';
				}
				
			}
			else
			{
				if (j == 20)
				{
					if (k == 20)
						Q[j][k] = '|';
					else
						Q[j][k] = '-';
				}
				else
				{
					if (k == 20)
						Q[j][k] = '|';
					else
						Q[j][k] = ' ';
				}
				

			}
		}
		if (flag > 0)
		{
			count++;
			flag = 0;
		}
	}
}