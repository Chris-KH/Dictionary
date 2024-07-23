#pragma once

class TrieNode {
public:
    TrieNode* childNode[26];

    bool wordEnd;

    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++) {
            childNode[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = nullptr;
    }
};