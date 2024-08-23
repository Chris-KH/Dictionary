#pragma once
#include"Lists.h"

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
    List* listHistory;
    List* listFavorite;

    void saveHelper(TrieNode* root, ofstream& fout);
    TrieNode* removeHelper(TrieNode* root, wstring key, int depth);
    void clearHelper(TrieNode* root);
public:
    Trie();
    TrieNode* getRoot();
    void insert(Word word);
    void remove(wstring key);
    void suggest(TrieNode* node, vector<Word>& list);
    bool search(Word& word, wstring key, vector<Word>& list);
    void save(ofstream& fout);
    void clear();
    void setListHistory(List* list);
    void setListFavorite(List* list);
    void updateDefition(Word word);
};


