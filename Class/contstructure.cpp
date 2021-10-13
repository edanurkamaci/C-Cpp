#include <iostream>
#include <string>

using namespace std;

class student
{
private:

	int numb;
	string name;

public:

	student(int number, string namee)
	{
		numb = number;
		name = namee;
	}
	student(int number)
	{
		numb = number;
		name = "KAMACI";
	}

	void printInformations()
	{
		cout << "Name: " << name << endl;
		cout << "No: " << numb << endl << endl;
	}

};

int main()
{
	student s1(894720, "Eda Nur");
	student s2(5179);
	
	s1.printInformations();
	s2.printInformations();
	
	system("pause");
	return 0;
}