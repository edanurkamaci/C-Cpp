#include <iostream>
#include <fstream>
#include <cctype>
//#include <cstring>
//#include <string>
#define size 26

using namespace std;
void initialize(int letCount[], int *lc);
void countLetter( char *ch, int letCount[]);
void writeEverything(int letCount[], ofstream& outext, int lc);

int main()
{
	ifstream myInfile;
	ofstream myOutfile;

	int lineCount=0,letterCount[size];
	char ch2;
	//string word;

	myInfile.open("myTextIn.txt");

	if (!myInfile)
	{
		cout << "File could not be found!!!" << endl << endl;
		return 1;
	}
	
	myOutfile.open("myTextOUT.out");

	initialize(letterCount, &lineCount);

	myInfile.get(ch2);
	myOutfile << ch2;

	while (myInfile)
	{
		countLetter( &ch2, letterCount);
		if (ch2 == '\n')
		{
			lineCount++;
		}
		myInfile.get(ch2);
		myOutfile << ch2;
	}

	writeEverything(letterCount, myOutfile, lineCount);

	myInfile.close();
	myOutfile.close();

	system("pause");
	return 0;
}
void initialize(int letCount[], int *lc)
{
	lc = 0;

	for (int i = 0; i < size; i++)
	{
		letCount[i] = 0;
	}
}
void countLetter( char *ch, int letCount[])
{
	//int length = word.length();
	int	index;
	char ch2=*ch;

	/*strncpy(ch, word.c_str(), sizeof(ch));

	for (int i = 0; i < length; i++)
	{
		ch2 = toupper(ch[i]);
		index = static_cast<int>(ch2) - static_cast<int>('A');
		if (index >= 0 && index < 26)
		{
			letCount[index]++;
		}
	}
	for (int i = 0; i < length; i++)
	{
		ch[i] = NULL;
	}*/
	ch2 = toupper(ch2);
	index = static_cast<int>(ch2) - static_cast<int>('A');
	if (index >= 0 && index < 26)
	{
		letCount[index]++;
	}
	
}
void writeEverything(int letCount[], ofstream& outext,int lc)
{
	outext << endl<< endl;

	outext << "The number of lines is: " << lc << endl;

	for (int i = 0; i < size; i++)
	{
		outext << "The number of " << static_cast<char>(i + static_cast<int>('A'))
			   << " is: " << letCount[i] << endl;
	}
}
