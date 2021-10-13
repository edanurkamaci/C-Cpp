#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "Words.h"
#include "Dictionary.h"
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
	string filename;
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
		
		numguesses++;

		if (guess.compare("xxxxx") == 0)
		{
			cout << endl << "Hint: The secret word is: " << secret << endl << endl;
			cheated = 1;
		}
		else
		{
			if (word.IsWordValid(guess) == 0)
			{
				cout << "Dictionary does not include that word!!" << endl << endl;
				numguesses--;
			}
			else if (guess.compare(secret) == 0)
			{
				if (cheated == 0)
					cout << "Congartulations! You won in " << numguesses << " guesses!" << endl;
				else if (cheated == 1)
					cout << "Congartulations! You won using hint in " << numguesses << " guesses!" << endl;

				break;
			}
			else
			{
				cout << "The number of same letters is: " << word.countofMatchLetters(guess) << endl;
				cout << "The number of same letters at true place is: " << word.countofTruePlaceLetters(guess) << endl << endl;
			}
		}
	}
}
Dictionary::Dictionary()
{
	std::set<string>words = {};
	std::vector<string>secrets = {};
}
Dictionary::Dictionary(string filename)
{
	ifstream intext;
	string temp;

	intext.open(filename);

	if (!intext)
	{
		cout << "File was not open!!!" << endl;
		exit(0);
	}
	else
		cout << "File was open successfully!!!" << endl;

	intext >> temp;
	while (intext)
	{
		words.insert(temp);
		
		if (TestLegalSecretWord(temp) == 1)
			secrets.push_back(temp);

		intext >> temp;
	}
}
string Dictionary::BringValidWord()
{
	srand(time(0));

	int len = secrets.size()-1;

	return secrets[rand() % len];
}
bool Dictionary::IsWordValid(string word)
{
	int flag = 0;

	for (set<string>::iterator i = words.begin(); i != words.end(); i++)
	{
		if (word.compare(*i) == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return 1;
	else
		return 0;

}
bool Dictionary::TestLegalSecretWord(string word)
{
	int flag = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 5 ; j++)
		{
			if (word[i] == word[j])
				flag = 1;
		}
		if (flag > 0)
			break;
	}
	if (flag == 1)
		return 0;
	else
		return 1;
}