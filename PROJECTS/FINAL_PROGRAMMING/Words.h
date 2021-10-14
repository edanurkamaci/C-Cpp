#ifndef WORDS_H
#define WORDS_H
#include "Dictionary.h"

class Words : public Dictionary
{
private:
	int countofMatchLetters(std::string);
	int countofTruePlaceLetters(std::string);
	int numguesses;
	bool cheated;
	std::string secret;
public:
	Words();
	~Words() {};
	void playgame(Words &);
};

#endif // !WORDS_H
