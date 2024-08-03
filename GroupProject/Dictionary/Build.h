#pragma once
#include"Global.h"

void buildTrie(wifstream& fin, Trie& trie);
void buildAll();

void saveTrie(wofstream& fout, Trie& trie);
void saveAll();

void resetToOrigin();
void freeMemory();