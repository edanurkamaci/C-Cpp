#include <iostream>
#include <stdlib.h>

using namespace std;

void initialize(int& zeros, int& evens, int& odds);
void getNum(int& num);
void classify(int& zeros, int& evens, int& odds, int num);
void printResults(int zeros, int evens, int odds);

int main()
{
	int even, zero, odd,number;

	initialize(even, zero, odd);

	cout << "Enter 10 numbers: ";

	for (int i = 1; i <= 10; i++)
	{
		getNum(number);
		classify(zero, even,odd, number);
	}

	printResults(zero, even, odd);

	system("pause");
	return 0;
}
void initialize(int& zeros, int& evens, int& odds)
{
	zeros = 0;
	evens = 0;
	odds = 0;
}
void getNum(int& num)
{
	cin >> num;
}
void classify(int& zeros, int& evens, int& odds, int num)
{
	switch (num % 2)
	{
	    case 0:
		{
			if (num == 0)
				zeros++;
			else
				evens++;
			break;
		}
		case -1:
		case 1:
		{
			odds++; break;
		}
		default:
			break;
	}
}
void printResults(int zeros, int evens, int odds)
{
	cout << "Number of zeros: " << zeros<<endl;
	cout << "Number of evens: " << evens << endl;
	cout << "Number of odds: " << odds << endl<<endl;
}