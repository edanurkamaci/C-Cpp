#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <string>
#include <set>
#include <vector>

class Dictionary
{
private:
	std::set <std::string> words;
	std::vector<std::string> secrets;
	
	bool TestLegalSecretWord(std::string word);
public:
	Dictionary();
	Dictionary(std::string filename);
	~Dictionary() {};
	std::string BringValidWord();
	bool IsWordValid(std::string word);
};
#endif // !1
