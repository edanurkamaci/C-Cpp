#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <fstream> //to create file use that!                        
                                  //Average Test Scroe
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;

	float test1, test2, test3, test4, test5;
	float average;

	string firstname;
	string lastname;
	
	inFile.open("test.txt");  // read from file
	outFile.open("average.out"); // write to file

	outFile << fixed << showpoint;
	outFile << setprecision(2);

	cout << fixed << showpoint;
	cout << setprecision(2);

	cout << "Proccesing data " << endl;

	inFile >> firstname >> lastname;

	outFile << "Student Name: " << firstname <<" "<< lastname<<endl;

	inFile >> test1 >> test2 >> test3 >> test4 >> test5;
	outFile << "Test Scores: " << setw(6) << test1 << setw(6)
		<< test2 << setw(6) << setw(6) <<test3 << setw(6) << test4 << setw(6) << test5 << endl;

	average = (test1 + test2 + test3 + test4 + test5) / 5;

	outFile << "Average of the scores is : " << average;

	cout <<endl<< "Student Name: " << firstname << " " << lastname << endl;
	cout << "Test Scores: " << setw(6) << test1 << setw(6)
		<< test2 << setw(6) << setw(6) << test3 
		<< setw(6) << test4 << setw(6) << test5 << endl;

	cout<<endl<< "Average of the scores is : " << average;

	inFile.close();
	outFile.close();

	
	printf("\n\n");
	system("pause");
	return 0;
}