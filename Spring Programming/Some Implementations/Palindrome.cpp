#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

int howDigit(int y);
bool isNumPal(int x, int y);

int main()
{
	int number,digit;
	bool desicion;

	cout << "Enter a number to find whether it is palindrome or not: ";
	cin >> number;

	digit = howDigit(number);
	desicion = isNumPal(number, digit);

	if (desicion == true)
	{
		cout << endl << number<<" is a palindrome number." << endl << endl;
	}
	else
	{
		cout << endl << number<<" is not a palindrome number." << endl << endl;
	}

	system("pause");
	return 0;
}
int howDigit(int y)
{
	int digit = 0, numb=y;

	while (numb > 0)
	{
		numb /= 10;
		digit++;
	}
   
	return digit;
}
bool isNumPal(int x, int y)
{
	int new_numb = x,pwr=y;
	int cont_first, cont_last,flag=0;

	while (pwr > 0)
	{
		cont_first=new_numb / pow(10, pwr-1);
		cont_last = new_numb % 10;

		if (cont_first == cont_last)
		{
			new_numb -= cont_first * pow(10, pwr-1);
			new_numb /= 10;
		}
		else
		{
			flag++;

			break;
		}
		pwr-=2;
	}

	if (flag > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}