#pragma once
#include"Global.h"
#include <QFile>
void buildTrie(QFile& file, Trie& trie, const int mode);
void buildAllTrie();

void saveTrie(QFile& file, Trie& trie, const int mode);
void saveAllTrie();

void buildList(QFile& file, List& list, const int mode);
void buildAllList(bool mode);

void saveList(QFile& file, List& list, const int mode);
void saveAllList(bool mode);

void resetToOrigin(Trie& trie);
void freeMemory();
