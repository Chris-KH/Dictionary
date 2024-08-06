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
	random2 = getRandomNumber(mode);
	while (random2 == random1) random2 = getRandomNumber(mode);
	random3 = getRandomNumber(mode);
	while (random3 == random1 || random3 == random2) random3 = getRandomNumber(mode);
	random4 = getRandomNumber(mode);
	while (random4 == random1 || random4 == random2 || random4 == random3) random4 = getRandomNumber(mode);

	Word word1 = *listWord[mode][random1];
	Word word2 = *listWord[mode][random2];
	Word word3 = *listWord[mode][random3];
	Word word4 = *listWord[mode][random4];
}

//vector<wstring> guessWord(const int mode) {
//	Word word1, word2, word3, word4;
//	getFourRandomWord(word1, word2, word3, word4, mode);
//}
//
//vector<wstring> getDefinition(const int mode) {
//	Word word1, word2, word3, word4;
//	getFourRandomWord(word1, word2, word3, word4, mode);
//
//}