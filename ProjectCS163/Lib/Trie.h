#pragma once
#include"Lists.h"
#include "Word.h"
#include "VietNamese.h"
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
    void saveHelper(TrieNode* root, QTextStream& out);
    TrieNode* removeHelper(TrieNode* root, QString key, int depth);
    void clearHelper(TrieNode* root);
public:
    Trie();
    TrieNode* getRoot();
    void insert(Word word);
    void remove(QString key);
    void suggest(TrieNode* node, QVector<Word>& list);
    bool search(Word& word, QString key, QVector<Word>& list);
    void save(QTextStream& file);
    void clear();
    void setListHistory(List* list);
    void setListFavorite(List* list);

};


