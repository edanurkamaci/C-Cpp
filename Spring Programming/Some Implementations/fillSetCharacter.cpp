#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Using setfill - setw functions - left justification 

int main()
{
	int x = 165;
	float y = 1.618;
	int z = 658;

	cout << "123456789012345678901234567890" << endl;

	cout << setfill(' ');
	cout << setw(6) << x << setw(10) << y
		<< setw(6) << z<<endl;
	
	cout << setfill('|');
	cout << setw(6) << x << setw(10) << y
		<< setw(6) << z << endl;
	
	cout << setfill('@')<<setw(6) << x << setfill('&') << setw(10) << y
		<< setfill('$') << setw(6) << z << endl<<endl;

	cout << setfill(' ');
	cout << left;
	cout << setw(6) << x << setw(10) << y
		<< setw(6) << z << endl;

	printf("\n\n");
	system("pause");

	return 0;
}