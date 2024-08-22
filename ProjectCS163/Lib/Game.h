#pragma once
#include"Global.h"

int getRandomNumber(const int mode);

Word getRandomWord(const int mode);

void getFourRandomWord(Word& word1, Word& word2, Word& word3, Word& word4, const int mode);

QVector<QString> guessWord(const int mode);

QVector<QString> getDefinition(const int mode);
