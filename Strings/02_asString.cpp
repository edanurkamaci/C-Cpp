#include <iostream>
#include <stdlib.h>
#include <string>
#define size 100
using namespace std;

void main()
{
	string str1, str2;
	int len1, len2, flag = 0;

	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;

	len1 = str1.length();
	len2 = str2.length();

	if (len1 != len2)
		flag = 1;
	else
	{
		for (int i = 0; i < len1; i++)
		{
			str1[i] = toupper(str1[i]);
			str2[i] = toupper(str2[i]);

		}
		if (str1 != str2)
			flag = 1;
	}

	cout << endl << endl;
	if (flag > 0)
		cout << "The words are not same!!";
	else
		cout << "The words are same!!";
	cout << endl << endl;

	system("pause");
}