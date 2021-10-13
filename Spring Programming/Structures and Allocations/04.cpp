#include <iostream>
#include <stdlib.h>
#include <string>
#define size 3
using namespace std;

typedef struct student
{
	string name;
	unsigned int midterm;
	unsigned int final;
	unsigned int ration_mid;
	double grade;
	char letter;

}student;

void readlist(student  a[], double *avrg);
void print_list(student a[], double *avrg);

int main()
{
	double average;
	student z[size];

	cout << "Student's informations: "<<endl<<endl;

	readlist(z, &average);
	print_list(z, &average);

	cout << endl << endl;
	system("pause");

	return 0;
}
void readlist(student a[],double *avrg)
{
	double sum_st = 0;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter student name's: ";
		getline(cin, a[i].name);
		cout << "Enter midterm: ";
		cin>>a[i].midterm;
		cout << "Enter final: ";
		cin>> a[i].final;
		cout << "Enter ration of midterm: ";
		cin>> a[i].ration_mid;

		a[i].grade = (a[i].midterm*a[i].ration_mid)/100 + (a[i].final*(100-a[i].ration_mid))/100;
		sum_st += a[i].grade;

		if ( a[i].grade >= 90 )
			a[i].letter = 'A';
		else if( a[i].grade >= 80 )
			a[i].letter = 'B';
		else if ( a[i].grade >= 70 )
			a[i].letter = 'C';
		else if ( a[i].grade >= 50 )
			a[i].letter = 'D';
		else
			a[i].letter = 'F';

		cin.ignore();
	}
	*avrg = sum_st / size;
}
void print_list(student a[] ,double *avrg)
{
	cout <<endl<< "RESULTS: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << a[i].name << " " << a[i].grade<< " "
			 <<a[i].letter<<endl;
	}
	cout << endl << "The average of grades student's: " << *avrg;
}
