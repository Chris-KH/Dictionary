#include "Trie.h"
#include <QFile>
#include <QTextStream>
#include "VietNamese.h"

TrieNode::TrieNode() {
    wordEnd = false;
    for (int i = 0; i < sizeChar; i++) {
        childNode[i] = nullptr;
    }
}

bool TrieNode::isLeaf() const {
    for (int i = 0; i < sizeChar; i++) {
        if (childNode[i] != nullptr) return false;
    }
    return true;
}

Trie::Trie() {
    root = new TrieNode();
    listHistory = nullptr;
    listFavorite = nullptr;
}

TrieNode* Trie::getRoot() {
    return this->root;
}

TrieNode* Trie::removeHelper(TrieNode* root, QString key, int depth) {
    if (root == nullptr) return nullptr;
    if (depth == key.size()) {
        root->wordEnd = false;
        listHistory->erase(root->word.key);
        listFavorite->erase(root->word.key);
        if (root->isLeaf()) {
            delete root;
            root = nullptr;
        }
        return root;
    }
    int idx = mp[key[depth].unicode()];
    root->childNode[idx] = removeHelper(root->childNode[idx], key, depth + 1);
    if (root->isLeaf() && root->wordEnd == false) {
        delete root;
        root = nullptr;
    }

    return root;
}

void Trie::remove(QString key) {
    for (int i = 0; i < (int)key.length(); i++) {
        key[i] = lowerCase(key[i]);
    }
    this->root = removeHelper(this->root, key, 0);
}

void Trie::insert(Word word) {
    TrieNode* cur = this->root;
    for (int i = 0; i < (int)word.key.size(); i++) {
        QChar c = lowerCase(word.key[i]);
        int idx = mp[c.unicode()];
        if (idx < 0) continue;
        if (cur->childNode[idx] == nullptr) {
            cur->childNode[idx] = new TrieNode();
        }
        cur = cur->childNode[idx];
    }
    if (cur->wordEnd == false) {
        cur->wordEnd = true;
        cur->word = word;
    }
    else {
        if (!cur->word.type.contains(word.type) && !word.type.isEmpty()) {
            if (cur->word.type.isEmpty()) cur->word.type += word.type;
            else cur->word.type += ", " + word.type;
        }
        if (!cur->word.spelling.contains(word.spelling) && !word.spelling.isEmpty()) {
            if (cur->word.spelling.isEmpty()) cur->word.spelling += word.spelling;
            else cur->word.spelling += ", " + word.spelling;
        }
        for (int i = 0; i < (int)word.definitions.size(); i++) {
            cur->word.addDefinition(word.definitions[i]);
        }
    }
}

void Trie::saveHelper(TrieNode* root, QTextStream& out) {
    if (root->wordEnd) {
        out << root->word.key << "\n";
        if (root->word.type.isEmpty()) out << "-\n";
        else out << root->word.type << "\n";
        if (root->word.spelling.isEmpty()) out << "-\n";
        else out << root->word.spelling << "\n";
        for (int i = 0; i < (int)root->word.definitions.size(); i++) {
            if (i != 0) out << "|";
            out << root->word.definitions[i];
        }
        out << "\n\n";
    }

    for (int i = 0; i < sizeChar; i++) {
        if (root->childNode[i]) saveHelper(root->childNode[i], out);
    }
}

void Trie::save(QTextStream& file) {
    saveHelper(this->root, file);
}

void Trie::suggest(TrieNode* node, QVector<Word>& list) {
    if (node == nullptr) return;
    if (list.size() >= 10) return;

    if (node->wordEnd) {
        list.push_back(node->word);
    }

    for (int i = 0; i < sizeChar; i++) {
        suggest(node->childNode[i], list);
    }
}

bool Trie::search(Word& word, QString key, QVector<Word>& list) {
    TrieNode* cur = this->root;

    for (int i = 0; i < key.length(); i++) {
        QChar c = lowerCase(key[i]);
        int idx = mp[c.unicode()];
        if (cur->childNode[idx] == nullptr) return false;
        cur = cur->childNode[idx];
    }

    suggest(cur, list);

    if (cur->wordEnd) {
        word = cur->word;
        return true;
    }

    return false;
}

void Trie::clearHelper(TrieNode* root) {
    for (int i = 0; i < sizeChar; i++) {
        if (root->childNode[i]) clearHelper(root->childNode[i]);
    }
    delete root;
}

void Trie::clear() {
    if (root == nullptr) return;
    clearHelper(this->root);
    this->root = nullptr;
    this->listFavorite = nullptr;
    this->listHistory = nullptr;
}

void Trie::setListHistory(List* list) {
    this->listHistory = list;
}

void Trie::setListFavorite(List* list) {
    this->listFavorite = list;
}
