#pragma once

#include "Trie.h"

class List {
private:
	vector<wstring> list;
public:
	int find(wstring key);
	void insert(wstring key);
	void erase(wstring key);
	void save(ofstream& fout);
};

