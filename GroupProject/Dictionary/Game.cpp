#include"Game.h"

int getRandomNumber(const int mode) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution dis(0, (int)listWord[mode].size() - 1);
	return dis(gen);
}

Word getRandomWord(const int mode) {
	int randomNum = getRandomNumber(mode);
	return *listWord[mode][randomNum];
}

void getFourRandomWord(Word& word1, Word& word2, Word& word3, Word& word4, const int mode) {
	int random1, random2, random3, random4;
	random1 = getRandomNumber(mode);
	
	word1 = *listWord[mode][random1];

	while (word1.definitions.size() == 0) {
		random1 = getRandomNumber(mode);
		word1 = *listWord[mode][random1];
	}

	random2 = getRandomNumber(mode);
	while (word2.definitions.size() == 0 || random2 == random1) random2 = getRandomNumber(mode);

	random3 = getRandomNumber(mode);
	while (word3.definitions.size() == 0 || random3 == random1 || random3 == random2) random3 = getRandomNumber(mode);

	random4 = getRandomNumber(mode);
	while (word4.definitions.size() == 0 || random4 == random1 || random4 == random2 || random4 == random3) random4 = getRandomNumber(mode);

	word2 = *listWord[mode][random2];
	word3 = *listWord[mode][random3];
	word4 = *listWord[mode][random4];
}

vector<wstring> guessWord(const int mode) {
	Word word1, word2, word3, word4;
	getFourRandomWord(word1, word2, word3, word4, mode);

	//Index 0 is key word
	//Index 1 is correct of key word definition
	//Index 2,3,4 are wrong definition
	vector<wstring> a;

	a.push_back(word1.key);

	a.push_back(word1.definitions[0]);

	if (word2.definitions.size() != 0) a.push_back(word2.definitions[0]);
	else a.push_back(L".");

	if (word3.definitions.size() != 0) a.push_back(word3.definitions[0]);
	else a.push_back(L".");

	if (word4.definitions.size() != 0) a.push_back(word4.definitions[0]);
	else a.push_back(L".");

	return a;
}

vector<wstring> getDefinition(const int mode) {
	Word word1, word2, word3, word4;
	getFourRandomWord(word1, word2, word3, word4, mode);

	//Index 0 is definition
	//Index 1 is correct key word
	//Index 2,3,4 are wrong key word
	vector<wstring> a;

	a.push_back(word1.definitions[0]);

	a.push_back(word1.key);
	a.push_back(word2.key);
	a.push_back(word3.key);
	a.push_back(word4.key);

	return a;
}
