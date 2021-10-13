#include <iostream>
#include <stdlib.h>
#include <string>
#include "Dictionary.h"
#include "Words.h"
using namespace std;

Words::Words()
{
	numguesses = 0;
	cheated = 0;
}
int Words::countofMatchLetters(std::string x)
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (secret[i] == x[j])
			{
				count++;
				for (int k = 0; k < j; k++)
				{
					if (x[k] == x[j])
						count--;
				}
			}
		}
	}
	return count;
}
int Words::countofTruePlaceLetters(std::string y)
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		if (secret[i] == y[i])
			count++;
	}
	return count;
}
void Words::playgame(Words &word)
{
	char filename[30];
	string guess;

	cout << "Enter a file name: ";
	cin >> filename;

	word.Dictionary::Dictionary(filename);
	system("CLS");

	cout << "WELCOME TO GUESS GAME" << endl
		<< "I kept a 5 letter word in my mind" << endl << endl;
	secret = Dictionary::BringValidWord();

	while (1)
	{
		cout << "What is your guess? ";
		cin >> guess;
		//cout << secret << endl;
		numguesses++;

		if (guess.compare("xxxxx") == 0)
		{
			cout <<endl<< "Hint: The secret word is: " << secret << endl<<endl;
			cheated = 1;
		}
		else
		{
			if (word.IsWordValid(guess) == 0)
			{
				cout << "Dictionary does not include that word!!" << endl<<endl;
				numguesses--;
			}
			else if(guess.compare(secret) == 0)
			{
				if(cheated==0)
				    cout << "Congartulations! You won in " << numguesses << " guesses!" << endl;
				else if(cheated==1)
					cout << "Congartulations! You won using hint in " << numguesses << " guesses!" << endl;

				break;
			}
			else
			{
				cout << "The number of same letters is: " << word.countofMatchLetters(guess) << endl;
				cout << "The number of same letters at true place is: " << word.countofTruePlaceLetters(guess) << endl<<endl;
			}
		}
	}
	//cout << word.BringValidWord() << endl;
}