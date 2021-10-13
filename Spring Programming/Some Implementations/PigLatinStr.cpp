#include <iostream>
#include <string>

using namespace std;

string rotate(string pStr,int cont);
int isThereVowel(string str);

int main()
{
	string input,neWord;
	int control;

	cout << "Enter a string: ";
	cin >> input;

	control = isThereVowel(input);
	neWord=rotate(input, control);
	
	cout << endl << endl << "The Pig Latin Str form of " << input
		 << " is: " << neWord << endl << endl;

	system("pause");
	return 0;
}
string rotate(string pStr, int cont)
{
	string rStr,adding,remain;
	string::size_type len = pStr.length();
	int start = 0;

	if (cont == -1)
	{
		rStr = pStr;
		rStr += "-way";
	}
	else
	{
		adding = pStr.substr(0, cont);
		remain = pStr.substr(cont, len - 1);
		rStr = remain + "-" + adding+"ay";
	}
	return rStr;
}
int isThereVowel(string str)
{
	char ch;
	int flag=0,i,cont=0;
	string::size_type len = str.length();

	for(i=0;i<len;i++)
	{
		ch = str[i];
		switch (ch)
		{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		{
			if(i==0)
			{
				cont++;
			}
			else
			{
				flag++;
			}
		    break;
		}
		default:
			break;
		}
		if (flag > 0)
			break;
	}
	if (flag > 0 && cont==0)
		return i;
	else
		return -1;
}
