#pragma once
#include"Global.h"

void buildTrie(ifstream& fin, Trie& trie);
void buildAllTrie();

void saveTrie(ofstream& fout, Trie& trie);
void saveAllTrie();

void buildList(ifstream& fin, List& list);
void buildAllList(bool mode);

void saveList(ofstream& fout, List& list);
void saveAllList(bool mode);


void resetToOrigin(Trie& trie);
void freeMemory();