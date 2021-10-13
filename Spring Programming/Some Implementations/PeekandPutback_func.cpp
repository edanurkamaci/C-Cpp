#include <iostream>
#include <stdlib.h>

using namespace std;

//Peek and Putback Functions

int main()
{
	char ch;

	cout << "Enter a word: ";
	cin.get(ch);

	cout <<"After first get: "<<ch<<endl;

	cin.get(ch);
	cout << "After second get: " << ch<<endl;

	cin.putback(ch);
	cout <<"After putback function: "<< ch<<endl;

	cin.get(ch);
	cout << "After third get: " << ch << endl;

	cin.peek();
	cout<< "After peek function: " << ch << endl;

	cin.get(ch);
	cout << "After forth get: " << ch << endl;

	printf("\n\n");
	system("pause");

	return 0;
}