#include"Build.h"

void buildTrie(ifstream& fin, Trie& trie, const int mode) {
    while (!fin.eof()) {
        Word word;
        string line_8;
        wstring line;
        for (int i = 0; i <= 4; i++) {
            getline(fin, line_8);
            line = utf8_to_utf16(line_8);
            while (!line.empty() && line.back() == L' ') line.pop_back();
            if (i == 0) word.key = line;
            if (i == 1 && line != L"-") word.type = line;
            if (i == 2 && line != L"-") word.spelling = line;
            if (i == 3) {
                wstringstream ss(line);
                wstring def;
                while (getline(ss, def, L'|')) {
                    while (!def.empty() && def.back() == L' ') def.pop_back();
                    word.addDefinition(def);
                }
            }
        }
        if (word.key.empty()) continue;
        trie.insert(word);
        listWord[mode].push_back(&word);
    }

    fin.close();
}

void buildAllTrie() {
    for (int i = 0; i <= 4; i++) {
        ifstream fin;
        if (filesystem::exists(dataPath[i])) fin.open(dataPath[i]);
        else fin.open(originDataPath[i]);
        auto start = chrono::high_resolution_clock::now();

        buildTrie(fin, trieLists[i], i);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << "ms\n";

        if (!filesystem::exists(storyDir[i])) filesystem::create_directories(storyDir[i]);
        if (!filesystem::exists(historyPath[i])) {
            ofstream fout(historyPath[i]);
            fout.close();
        }
        if (!filesystem::exists(favoritePath[i])) {
            ofstream fout(favoritePath[i]);
            fout.close();
        }
    }
    buildAllList(0);
    buildAllList(1);
    for (int i = 0; i <= 4; i++) {
        trieLists[i].setListHistory(&historyLists[i]);
        trieLists[i].setListFavorite(&favoriteLists[i]);
    }
    saveAllTrie();
}

void saveTrie(ofstream& fout, Trie& trie, const int mode) {
    trie.save(fout);
}

void saveAllTrie() {
    for (int i = 0; i <= 4; i++) {
        ofstream fout(dataPath[i]);
        saveTrie(fout, trieLists[i], i);
    }
}

void buildList(ifstream& fin, List& list, const int mode) {
    string line;
    while (!fin.eof()) {
        getline(fin, line);
        if (line.empty()) continue;
        list.insert(utf8_to_utf16(line));
    }
    fin.close();
}

void buildAllList(bool mode) {
    if (mode == 0) {
        for (int i = 0; i <= 4; i++) {
            ifstream fin(historyPath[i]);
            buildList(fin, historyLists[i], i);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            ifstream fin(favoritePath[i]);
            buildList(fin, favoriteLists[i], i);
        }
    }
}

void saveList(ofstream& fout, List& list, const int mode) {
    list.save(fout);
}

void saveAllList(bool mode) {
    if (mode == 0) {
        for (int i = 0; i <= 4; i++) {
            ofstream fout(historyPath[i]);
            saveList(fout, historyLists[i], i);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            ofstream fout(favoritePath[i]);
            saveList(fout, favoriteLists[i], i);
        }
    }
}

void resetToOrigin(Trie& trie) {
    trie.clear();
    listWord[system_Mode].clear();
    filesystem::remove(dataPath[system_Mode]);
    filesystem::remove(historyPath[system_Mode]);
    filesystem::remove(favoritePath[system_Mode]);
    ofstream fout(historyPath[system_Mode]);
    fout.close();
    fout.open(favoritePath[system_Mode]);
    fout.close();

    Trie temp;
    ifstream fin(originDataPath[system_Mode]);
    buildTrie(fin, temp, system_Mode);
    trie = temp;
    trie.setListHistory(&historyLists[system_Mode]);
    trie.setListFavorite(&favoriteLists[system_Mode]);
}

void freeMemory() {
    for (int i = 0; i <= 4; i++) trieLists.clear();
}