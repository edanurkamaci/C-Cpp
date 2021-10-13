#include <iostream>
#include <stdlib.h>
#define size 5
using namespace std;

void main()
{
	char *s[size];
	int str_size;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter string size: ";
		cin >> str_size;
		
		s[i] = new char[str_size];
		
		if (s[i] == NULL)
			exit(0);

		cin.ignore();
		cout << "Enter product name: ";
		cin.getline(s[i], str_size);
	}

	for (int j = 0; j < size; j++)
		cout << s[j] << endl;

	cout << endl << endl;
	system("pause");
}