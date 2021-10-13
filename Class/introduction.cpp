#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:

	string name;
	int year;
	string department;
	string college;

	void print()
	{
		cout << name << " started to study " << department << " at " << college << " in " << year << endl;
	}
};

int main()
{
	Person p1;

	p1.name = "Eda Nur";
	p1.year = 2019;
	p1.department = "Computer Engineering";
	p1.college = "ESOGU";

	p1.print();

	printf("\n\n");
	system("pause");
	return 0;
}
