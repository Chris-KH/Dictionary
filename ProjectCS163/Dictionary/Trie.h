#pragma once
#include"Word.h"

class TrieNode {
public:
    TrieNode* childNode[26];
    bool wordEnd;
    Word word;
    TrieNode();

    bool isLeaf() const;
};

class Trie {
private:
    TrieNode* root;
    TrieNode* removeHelper(TrieNode* root, string key, int depth = 0);
    void clearHelper(TrieNode* root);
public:
    Trie();
    void remove(string key);
    void clear();
};