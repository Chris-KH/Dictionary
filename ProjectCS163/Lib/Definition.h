#pragma once
#include"Global.h"
#include <QPair>

double editDistance(QString a, QString b);
void getWord(TrieNode* root, QString def, QVector<QPair<double, Word>>& defSearch);
QVector<QPair<double, Word>> defSearch(Trie& trie, QString def);
