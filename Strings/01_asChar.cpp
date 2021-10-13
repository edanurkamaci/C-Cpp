#include <iostream>
#include <stdlib.h>
#include <string>
#define size 100
using namespace std;

void main()
{
	char str1[size], str2[size],*p,*q;
	int len1,len2,flag=0;

	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;

	p = str1;
	q = str2;

	len1 = strlen(str1);
	len2 = strlen(str2);

	if (len1 != len2)
		flag = 1;
	else
	{
		/*for (int i = 0; i < len1; i++)
		{
			if (*p != *q)
			{
				flag = 1; break;
			}
			else
			{
				p++;
				q++;
			}
		}*/
		for (int i = 0; i < len1; i++)
		{
			str1[i] = toupper(str1[i]);
			str2[i] = toupper(str2[i]);
		
		}
		for (int j = 0; j < len1; j++)
		{
			if (str1[j] != str2[j])
				flag = 1;
		}

	}
	
	cout << endl << endl;
	if (flag > 0)
		cout << "The words are not same!!";
	else
		cout << "The words are same!!";
	cout << endl << endl;

	system("pause");
}