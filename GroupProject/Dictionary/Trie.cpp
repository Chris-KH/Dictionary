#include"Trie.h"

TrieNode::TrieNode() {
    wordEnd = false;
    for (int i = 0; i < 93; i++) {
        childNode[i] = nullptr;
    }
}

bool TrieNode::isLeaf() const {
    //Leaf has no children
    for (int i = 0; i < 93; i++) {
        if (!childNode[i]) return false;
    }
    return true;
}

TrieNode* Trie::removeHelper(TrieNode* root, wstring key, int depth) {
    if (root == nullptr) return nullptr;

    if (depth == key.size()) {
        root->wordEnd = false;
        
        // If given is not prefix of any other word
        if (root->isLeaf()) {
            delete root;
            root = nullptr;
        }

        return root;
    }

    int idx = mp[key[depth]];
    root->childNode[idx] = removeHelper(root->childNode[idx], key, depth + 1);


    // If root does not have any child (its only child got deleted), and it is not end of another word.
    if (root->isLeaf() && root->wordEnd == false) {
        delete root;
        root = nullptr;
    }

    return root;
}

void Trie::insert(Word word) {
    TrieNode* cur = this->root;
    for (int i = 0; i < (int)word.key.size(); i++) {
        wchar_t c = lowerCase(word.key[i]);
        int idx = mp[c];
        if (idx < 0) continue;
        if (cur->childNode[idx] == nullptr) {
            cur->childNode[idx] = new TrieNode();
        }
        cur = cur->childNode[idx];
    }
    cur->wordEnd = true;
    cur->word = word;
}

void Trie::remove(wstring key) {
    for (int i = 0; i < (int)key.length(); i++) {
        key[i] = lowerCase(key[i]);
    }
    this->root = removeHelper(this->root, key, 0);
}

bool Trie::search(Word& word, wstring key) {
    TrieNode* cur = this->root;

    for (int i = 0; i < (int)key.length(); i++) {
        wchar_t c = lowerCase(key[i]);
        int idx = mp[c];
        if (cur->childNode[idx] == nullptr) return false;
        cur = cur->childNode[idx];
    }

    if (cur->wordEnd) {
        word = cur->word;
        return true;
    }

    return false;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::clearHelper(TrieNode* root) {
    for (int i = 0; i < 93; i++) {
        if (root->childNode[i]) clearHelper(root->childNode[i]);
    }
    delete root;
}

void Trie::clear() {
    if (root == nullptr) return;
    clearHelper(this->root);
    this->root = nullptr;
}


vector<Word*> Trie::getFavoriteList()
{
    vector<Word*> result;
    result.clear();
    for (auto curWord : listWord)
    {
        if (curWord->isFavorite)
            result.push_back(curWord);
    }
    return result;
}

vector<Word*> Trie::getHistoryList()
{
    return listHistory;
}

void Trie::addHistory(Word* word)
{
    //if (listHistory.size() > LIMIT) ???
    //    listHistory.pop_back();
    for (int i = 0; i < (int) listHistory.size(); i++)
        if (listHistory[i] == word)
        {
            listHistory.erase(listHistory.begin() + i);
            break;
        }
    
    listHistory.insert(listHistory.begin(), word);
    
}