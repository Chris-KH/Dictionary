#pragma once

#include "Word.h"

class List {
private:
	vector<wstring> list;
public:
	int find(wstring key);
	void insert(wstring key);
	void erase(wstring key);
	void save(ofstream& fout);
};

