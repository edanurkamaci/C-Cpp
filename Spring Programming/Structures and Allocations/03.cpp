#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct student
{
	char name[50];
	unsigned int grade;
}student;

void readlist(student  a[], int size, int *avrg);
void print_list(student *a, int size, int *avrg);

int main()
{
	const int size = 3;
	int average;
	student z[size];

	cout << "Enter the student's informations respectively: ";

	readlist(z, size, &average);
	print_list(z, size, &average);

	cout << endl << endl;
	system("pause");

	return 0;
}
void readlist(student a[], int size,int *avrg)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		cin >> a[i].name >> a[i].grade;
		sum += a[i].grade;
    }
	*avrg = sum / size;
}
void print_list(student *a, int size, int *avrg)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i].name<<" " << a[i].grade<<endl;
	}
	cout << endl << "The average of grades student's: " << *avrg;
}
