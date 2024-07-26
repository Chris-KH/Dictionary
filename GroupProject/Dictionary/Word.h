#pragma once
#include"VietNamese.h"

class Word {
public:
	wstring key; //Ex: dog, cat...
	wstring type; // 0, 1, 2, 3, 4 for Eng-eng, Eng-vie, Vie-eng,...
	vector<wstring> definitions; //Just definitions
	Word();
	Word(wstring key, wstring type, wstring def);
	void addDefinition(wstring def);
	void removeDefinition(int idx);
};

