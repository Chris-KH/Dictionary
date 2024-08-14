#pragma once
#include"Global.h"

double editDistance(QString a, QString b);
void getWord(TrieNode* root, QString def, QVector<pair<double, Word>>& defSearch);
QVector<pair<double, Word>> defSearch(Trie& trie, QString def);
