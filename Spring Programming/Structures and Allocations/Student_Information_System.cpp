#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#define size 20
using namespace std;

void add(void);
void del(void);
void list(void);

typedef struct student
{
	string name;
	string address;
	char id[size];

}student;

student Student[size];
int x=0;

int main()
{
	char selection;

	do
	{
		system("cls");
		cout << "\n\n\n\t****MAIN MENU****\n\n\n";
		cout << "\t[A]- New student addition\n";
		cout << "\t[D]- Deletion\n";
		cout << "\t[L]- List\n";
		cout << "\t[Q]- Exit\n";

		cout << "\n\n\tPlease select a option you want!";
		selection = _getch(); //The option won't be seen on screen thanks to _getch() function
		system("cls");

		if (selection == 'A' || selection == 'a')
			add();
		else if (selection == 'D' || selection == 'd')
			del();
		else if (selection == 'L' || selection == 'l')
			list();
		else if (selection == 'Q' || selection == 'q')
			exit(0);
	
	} while (selection != 'Q' || selection != 'q');

	cout << endl << endl;
	system("pause");
	return 0;
}
void add(void)
{
	char id[size];

	cout << "\n\t----Adding Registry---\n\n";

	if (x <= 100)
	{
		cout << "Please enter student informations'!\n";
		cout << "Enter student's name: ";
		getline(cin, Student[x].name);
		cout << "Enter student's id: ";
		cin>> id;
		strcpy_s(Student[x].id, id);
		cout << "Enter student's address: ";
		getline(cin, Student[x].address);
	}
	else
	{
		cout << "The list is full. You can not add more!"<<endl<<endl;
	}
	cout << "Please press a button to go back to main menu!";
	_getch();
}
void del(void)
{
	char del[size];
	int leng;

	cout << "\n\t----Deleting Registry---\n\n";

	cout << "Please enter id of student you wanna delete: ";
	cin >> del;

	leng = strlen(del);

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < leng; j++)
		{
			if(Student[i].id[j]!=del[j])


		}
	}

	cout << "Please press a button to go back to main menu!";
	_getch();
}
void list(void)
{
	cout << "\n\t----Listing---\n\n";

	cout << "Please press a button to go back to main menu!";
	_getch();
}

