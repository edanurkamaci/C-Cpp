#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(0));

	int i, j, row, col;

	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "Enter the number of columns: ";
	cin >> col;

	int **matrix = new int*[row];

	for (i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			matrix[i][j] = rand() % 10;
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	delete[]matrix;// I am not sure that we use delete after create matrix?

	cout << endl << endl;
	system("pause");
}