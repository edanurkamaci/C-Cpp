#include <iostream>
#include <stdlib.h>
using namespace std;

void main()
{
	int *a,n,i;
	int *new_a, m, j;

	cout << "Enter the number of elements: ";
	cin >> n;

	a = new int[n];
	
	if (a == NULL)
		exit(0);
	for (i = 0; i < n; i++)
		a[i] = i * i;
	
	for (i = 0; i < n; i++)
		cout << a[i] << endl;

	cout << "Enter the new number of elements: ";
	cin >> m;
	new_a = new int[m];

	if (new_a == NULL)
		exit(0);

	for (j = 0; j < m; j++)
	{
		if (j < n)
			new_a[j] = a[j];
		else
			new_a[j] = j * j*j;
		
		cout << new_a[j] << endl;
	}

	delete[]a;//free(a)
	delete[]new_a;//free(new_a)

	cout << endl<<endl;
	system("pause");
}