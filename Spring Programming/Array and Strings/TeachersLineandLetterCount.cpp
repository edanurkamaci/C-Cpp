#include <iostream>
#include <fstream>
#include <cctype> //I use it to distinguish between uppercase and lowercase letters
using namespace std;

void initialize(int &lc, int letterCount[]);
void copyTetx(ifstream& intext, ofstream& outtext, char& ch, int list[]);
void characterCount(char& ch, int list[]);
void writeTotal(ofstream& outtext, int list[], int lc);

int main()
{
	ifstream inFile;
	ofstream outFile;

	int letterCount[26];
	int lieCount;
	char ch;

	inFile.open("TextIn.txt");

	if (!inFile)
	{
		cout << "File could not be found!!!" << endl << endl;
		return 1;
	}

	outFile.open("TextOut.out");

	initialize(lieCount, letterCount);

	inFile.get(ch);

	while (inFile)
	{
		copyTetx(inFile, outFile, ch, letterCount);
		lieCount++;
		inFile.get(ch);
	}

	cout << "Operation completed!!!";

	writeTotal(outFile, letterCount, lieCount);

	inFile.close();
	outFile.close();

	cout << endl << endl;

	system("pause");
	return 0;
}
void initialize(int &lc, int letterCount[])
{
	lc = 0;

	for (int i = 0; i < 26; i++)
	{
		letterCount[i] = 0;
	}
}
void copyTetx(ifstream& intext, ofstream& outtext, char& ch, int list[])
{
	while (ch != '\n')
	{
		outtext << ch;
		characterCount(ch, list);
		intext.get(ch);
	}
	outtext << ch;
}
void characterCount(char& ch, int list[])
{
	int index;

	ch = towupper(ch);

	index = static_cast<int>(ch) - static_cast<int>('A');

	if (index >= 0 && index < 26)
	{
		list[index]++;
	}

}
void writeTotal(ofstream& outtext, int list[],int lc)
{
    outtext << "Number of lines: " << lc << endl << endl;

	for (int i = 0; i < 26; i++)
	{
	    outtext << static_cast<char>(static_cast<int>('A') + i) << "count: " << list[i] << endl;
	}

}