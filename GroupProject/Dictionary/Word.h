#pragma once
#include"VietNamese.h"

class Word {
public:
	string key;
	string type;
	vector<string> definitions;
	Word();
	Word(string key, string type, string def);
	void addDefinition(string def);
	void removeDefinition(int idx);
};

