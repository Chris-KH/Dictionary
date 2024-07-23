#pragma once
#include<bits/stdc++.h>

using namespace std;

class Word {
public:
	string key;
	string type;
	vector<string> definitions;
	Word(string key, string type, string def);
	void addDefinition(string def);
	void removeDefinition(int idx);
};