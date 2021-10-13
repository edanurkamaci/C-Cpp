#include<iostream>
#include <stdlib.h>
#include <ctime>
#define size 4

using namespace std;

void create(int list[4][4],int y);
void reverse(int list[4][4], int x);

int main()
{
	int list[4][4];

	create(list, size);
	reverse(list, size);

	system("pause");
	return 0;
}
void create(int list[4][4], int y)
{
	srand(time(0));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < y; j++)
		{
			list[i][j] = rand() % 10;
		}
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << list[i][j] << "\t";
		}
		cout << endl << endl;
	}
}
void reverse(int list[4][4], int x)
{
	int temp1, count1=0,count2=0;

	for (int i = 0; i <x/2 ; i++)
	{
		for (int j = 0; j < x / 2; j++)
		{
			if(i==j)
			{
				temp1 = list[i][j];
				list[i][j] = list[x- i-1][x - j-1];
				list[x - i - 1][x - j - 1] = temp1;
			
			}
			else if ((i == x - 1)&&i==x-1)
			{
				if (j == count2)
				{
					temp1 = list[i][j];
					list[i][j] = list[i - count2][x - count2 - 1];
					list[i - count2][x - count2 - 1]=temp1;
					count2++;
				}
			}
		}
	}

	int i;

	for (i = 0; i < x; i++);
	{
		for (int j = 0; j < x; j++)
		{
			cout << list[i][j] << "\t";
		}
		cout << endl << endl;
	}
}