#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void main()
{
	string str;
	char ch;

	ch = cin.get();

	while (ch != '.')
	{
		str += ch;

		if (ch == '\n')
		{
			cout << str;
			str.clear();
		}
		ch = cin.get();
	}

	cout << endl << endl;

	system("pause");
}