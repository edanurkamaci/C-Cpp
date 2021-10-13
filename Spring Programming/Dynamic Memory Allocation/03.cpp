#include <iostream>
#include <stdlib.h>
#define size 5
using namespace std;

void stringcopy(char *s1, char *s2);

void main()
{
	char *s[size];
	char s2[100];
	int len;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter product name: ";
		cin.getline(s2, 100);

		len = strlen(s2);
		cout << "Size of the product name: " << len;

		s[i] = new char[len+1];
		
		if (s[i] == NULL)
			exit(0);
		
		stringcopy(s[i], s2);
		cin.ignore();
	}

	for (int j = 0; j < size; j++)
		cout << s[j] << endl;

	cout << endl << endl;
	system("pause");
}
void stringcopy(char *s1, char *s2)
{
	char *p=s1;

	while (*s2)
	{
		*p++ = *s2++;
	}
	*p = '\0';
}
