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

Trie buildTrie(wifstream& fin);


vector<Trie> trieLists;
vector<string> dataSetDir = {"../Dataset/Eng_Vie.txt", "../Dataset/Vie_Eng.txt",
        "../Dataset/Eng_Eng.txt", "../Dataset/Slang.txt", "../Dataset/Emoji.txt"
};
vector<string> historyDir = {"../??/English-Vietnamese/history.txt", "../??/Vietnamese-English/history.txt", 
"../??/English-English/history.txt", "../??/Slang/history.txt", "../??/Emoji/history.txt"
};
vector<string> favoriteDir = { "../??/English-Vietnamese/favorite.txt", "../??/Vietnamese-English/favorite.txt",
"../??/English-English/favorite.txt", "../??/Slang/favorite.txt", "../??/Emoji/favorite.txt"
};