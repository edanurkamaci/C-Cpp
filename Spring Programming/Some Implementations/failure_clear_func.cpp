#include <iostream>
#include <stdlib.h>

using namespace std;

// input failure and clear function

int main()
{
	int a = 15;
	int b = 22;

	cout << "Enter the values of a and b again: ";
	cin >> a >> b;

	cout << "New values are a: " << a << "  b: " << b<<endl;

	cin.clear();
	cin.ignore(250,'\n');

	cout << "Enter again: ";
	cin >> a >> b;

	cout << "New values are a: " << a << "  b: " << b << endl;

	printf("\n\n");
	system("pause");

	return 0;
}