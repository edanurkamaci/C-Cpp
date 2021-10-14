#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10

void creat_array(int x[SIZE][SIZE], int y[SIZE][SIZE], int a, int b);
int path_array(int y[SIZE][SIZE], int x[SIZE][SIZE], int z[SIZE], int q[SIZE], int a, int b, int m);

void main()
{
	int first[SIZE][SIZE], second[SIZE][SIZE], pathh[SIZE], place2[SIZE], row, col;
	

	while (1)
	{
		printf("Enter the number of rows(0 to exit): ");
		scanf_s("%d", &row);
		if(row!=0)
		{
			printf("Enter the number of columns: ");
			scanf_s("%d", &col);
		}
		else
		{
			break;
		}

		if ((row < 1 || row>10) || (col < 2 || col>10))
		{
			printf("ERROR!!! INVALID RANGE! Try again!");
			printf("\n\n");

		}
		else
		{
			creat_array(first, second, row, col);

			int mini, value = 0;

			for (int j = 0; j < col; j++)
			{
				if (j == 0)
				{
					mini = second[row - 1][j];
				}
				else
				{
					if (mini > second[row - 1][j])
					{
						mini = second[row - 1][j];
						value = j;
					}
				}
			}
			path_array(second, first, pathh, place2, row, col, value);

			int count = 0, sum = 0;

			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < col; l++)
				{
					if (pathh[count] == l)
					{
						printf("\t[%d]", first[k][l]);
						sum += first[k][l];
					}
					else
					{
						printf("\t%d", first[k][l]);
					}

				}
				printf("\n\n");
				count++;
			}
			printf("\n");
			printf("\tSum of weights is: %d", sum);

			printf("\n\n\n");

			for (int k = 0; k < row; k++)
			{
				for (int l = 0; l < col; l++)
				{
					printf("\t%d", second[k][l]);
				}
				printf("\n\n");
				count++;
			}

			/*printf("\n\n\n");
			for (int g = 0; g < row; g++)
			{
				printf("\t%d", pathh[g]);
			}*/

			/*printf("\n\n\n");
			for (int q = 0; q < row; q++)
			{
				printf("\t%d", place2[q]);
			}*/
			
		}
	}

	printf("\n\n\n");
	system("pause");
}
void creat_array(int x[SIZE][SIZE], int y[SIZE][SIZE], int a, int b)
{
	srand(time(NULL));

	int mini;

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			x[i][j] = rand() % 10;
		}
	}

	for (int k = 0; k < a; k++)
	{
		for (int l = 0; l < b; l++)
		{

			if (k == 0)
			{
				y[k][l] = x[k][l];

			}
			else if (k == 1)
			{
				if (l == 0)
				{
					y[k][l] = min((x[k - 1][l] + x[k][l]), (x[k - 1][l + 1] + x[k][l]));
				}
				else if (l == b - 1)
				{
					y[k][l] = min((x[k - 1][l] + x[k][l]), (x[k - 1][l - 1] + x[k][l]));
				}
				else
				{
					int mini = min((x[k - 1][l - 1]), (x[k - 1][l]));

					if (mini > x[k - 1][l + 1])
					{
						mini = x[k - 1][l + 1];
					}

					y[k][l] = x[k][l] + mini;

				}
			}
			else
			{
				if (l == 0)
				{
					y[k][l] = min((y[k - 1][l] + x[k][l]), (y[k - 1][l + 1] + x[k][l]));
				}
				else if (l == b - 1)
				{
					y[k][l] = min((y[k - 1][l] + x[k][l]), (y[k - 1][l - 1] + x[k][l]));
				}
				else
				{
					int mini = min((y[k - 1][l - 1]), (y[k - 1][l]));

					if (mini > y[k - 1][l + 1])
					{
						mini = y[k - 1][l + 1];
					}

					y[k][l] = x[k][l] + mini;
				}
			}
		}
	}
	printf("\n\n");
}
int path_array(int y[SIZE][SIZE], int x[SIZE][SIZE], int z[SIZE], int q[SIZE], int c, int d, int m)
{
	int k ,val=m;

	if (c == 1)
	{
		int mini, value=0;

		for (int j = 0; j < d; j++)
		{
			if (j == 0)
			{
				mini = x[0][j];
			}
			else
			{
				if (mini > x[0][j])
				{
					mini = x[0][j];
					value = j;
				}
			}
		}
		z[0] = value;
	}
	else
	{
		for (int i = c - 1; i > 0; i--)
		{
			k = y[i][val] - x[i][val];
			if (i == c - 1)
			{
				z[i] = val;
				if ((y[i - 1][val - 1] == k && val != 0) || (y[i - 1][val + 1] == k && val != d - 1) || y[i - 1][val] == k)
				{
					if (y[i - 1][val - 1] == k && val != 0)
					{
						z[i - 1] = val - 1;
						val = val - 1;
					}
					else if (y[i - 1][val + 1] == k && val != d - 1)
					{
						z[i - 1] = val + 1;
						val = val + 1;
					}
					else if (y[i - 1][val] == k)
					{
						z[i - 1] = val;
					}
				}
			}
			else
			{
				if ((y[i - 1][val - 1] == k && val != 0) || (y[i - 1][val + 1] == k && val != d - 1) || y[i - 1][val] == k)
				{
					if (y[i - 1][val - 1] == k && val != 0)
					{
						z[i - 1] = val - 1;
						val = val - 1;
					}
					else if (y[i - 1][val + 1] == k && val != d - 1)
					{
						z[i - 1] = val + 1;
						val = val + 1;
					}
					else if (y[i - 1][val] == k)
					{
						z[i - 1] = val;
					}
				}
			}
		}
	}
	
	for(int j=0 ; j < c ; j++)
	{
		q[j] = z[j] + 1;
	}

	return q[SIZE];
}
