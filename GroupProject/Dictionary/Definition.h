#pragma once
#include"Global.h"

double editDistance(wstring a, wstring b);
void getWord(TrieNode* root, wstring def, vector<pair<double, Word>>& defSearch);
vector<pair<double, Word>> defSearch(Trie& trie, wstring def);