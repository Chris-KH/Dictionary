#pragma once
#include"Word.h"

class TrieNode {
public:
    TrieNode* childNode[sizeChar];
    bool wordEnd;
    Word word;

    TrieNode();
    bool isLeaf() const;
};

class Trie {
private:
    TrieNode* root;
    vector<Word*> listWord, listHistory;

    TrieNode* removeHelper(TrieNode* root, wstring key, int depth);
    void clearHelper(TrieNode* root);
public:
    Trie();
    void insert(Word word);
    void remove(wstring key);
    bool search(Word& word, wstring key);
    void clear();

    void addHistory(Word* word);
    vector<Word*> getFavoriteList();
    vector<Word*> getHistoryList();
    
};


