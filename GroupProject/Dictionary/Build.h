#pragma once
#include"Global.h"

void buildTrie(ifstream& fin, Trie& trie);
void buildAll();

void saveTrie(ofstream& fout, Trie& trie);
void saveAll();

void resetToOrigin();
void freeMemory();