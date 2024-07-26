#pragma once
#include"VietNamese.h"

class Word {
public:
	wstring key;
	wstring type;
	vector<wstring> definitions;
	Word();
	Word(wstring key, wstring type, wstring def);
	void addDefinition(wstring def);
	void removeDefinition(int idx);
};

