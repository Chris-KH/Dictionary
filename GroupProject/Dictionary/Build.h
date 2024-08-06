#pragma once
#include"Global.h"

void buildTrie(ifstream& fin, Trie& trie, const int mode);
void buildAllTrie();

void saveTrie(ofstream& fout, Trie& trie, const int mode);
void saveAllTrie();

void buildList(ifstream& fin, List& list, const int mode);
void buildAllList(bool mode);

void saveList(ofstream& fout, List& list, const int mode);
void saveAllList(bool mode);


void resetToOrigin(Trie& trie);
void freeMemory();