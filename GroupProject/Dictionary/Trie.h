#pragma once
#include"Word.h"

class TrieNode {
public:
    TrieNode* childNode[93];
    bool wordEnd;
    Word word;

    TrieNode();
    bool isLeaf() const;
};

class Trie {
private:
    TrieNode* root;
    TrieNode* removeHelper(TrieNode* root, wstring key, int depth);
    void clearHelper(TrieNode* root);
public:
    Trie();
    void insert(Word word);
    void remove(wstring key);
    void clear();
};