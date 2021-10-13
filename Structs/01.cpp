#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct student
{
	int number;
	string name, surname, department;
	char gender;
};

int main()
{
	int numb1,numb2,numb3;

	ofstream outfile;

	outfile.open("identify.out");

	numb1 = (rand() + time(0)) % 1000;
	numb2 = (rand() + time(0)) % 1000;
	numb3 = (rand() + time(0)) % 1000;

	student s1 = { numb1,"EDA NUR","KAMACI","COMPUTER ENGINEERING",'W' };
	student s2 = { numb2,"JENNIFER","ANNISTON","ACTOR",'W' };
	student s3;
 
	cout<< "Enter name of third student: ";
	cin >> s3.name;
	cout << "Enter surname of third student: ";
	cin >> s3.surname;
	cout << "Enter departmant of third student: ";
	cin >> s3.department;
	/*cout << "Enter student no of third student: ";
	cin >> s3.number;*/
	cout << "Enter gender of third student: ";
	cin >> s3.gender;
	s3.number = numb3;

	cout << "----------PERSON-1-------------" << endl << endl;
	cout << "Name= " << s1.name << endl;
	cout << "Surname= " << s1.surname << endl;
	cout << "Department= " << s1.department << endl;
	cout << "Student NO: " << s1.number << endl;
	cout << "Gender= " << s1.gender << endl<<endl;

	cout << "----------PERSON-2-------------" << endl << endl;
	cout << "Name= " << s2.name << endl;
	cout << "Surname= " << s2.surname << endl;
	cout << "Department= " << s2.department << endl;
	cout << "Student NO: " << s2.number << endl;
	cout << "Gender= " << s2.gender << endl << endl;

	cout << "----------PERSON-3-------------" << endl << endl;
	cout << "Name= " << s3.name << endl;
	cout << "Surname= " << s3.surname << endl;
	cout << "Department= " << s3.department << endl;
	cout << "Student NO: " << s3.number << endl;
	cout << "Gender= " << s3.gender << endl << endl;

    outfile << "----------PERSON-1-------------" << endl << endl;
	outfile << "Name= " << s1.name << endl;
	outfile << "Surname= " << s1.surname << endl;
	outfile << "Department= " << s1.department << endl;
	outfile << "Student NO: " << s1.number << endl;
	outfile << "Gender= " << s1.gender << endl << endl;

	outfile << "----------PERSON-2-------------" << endl << endl;
	outfile << "Name= " << s2.name << endl;
	outfile << "Surname= " << s2.surname << endl;
	outfile << "Department= " << s2.department << endl;
	outfile << "Student NO: " << s2.number << endl;
	outfile << "Gender= " << s2.gender << endl << endl;

	outfile << "----------PERSON-3-------------" << endl << endl;
	outfile << "Name= " << s3.name << endl;
	outfile << "Surname= " << s3.surname << endl;
	outfile << "Department= " << s3.department << endl;
	outfile << "Student NO: " << s3.number << endl;
	outfile << "Gender= " << s3.gender << endl << endl;

	outfile.close();

	system("pause");
	return 0;
}