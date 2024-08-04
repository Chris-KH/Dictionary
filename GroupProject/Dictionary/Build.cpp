#include"Build.h"

void buildTrie(ifstream& fin, Trie& trie) {
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
    }

    fin.close();
}

void buildAllTrie() {
    for (int i = 0; i <= 4; i++) {
        ifstream fin;
        if (filesystem::exists(dataPath[i])) fin.open(dataPath[i]);
        else fin.open(originDataPath[i]);
        auto start = chrono::high_resolution_clock::now();

        buildTrie(fin, trieLists[i]);

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
    saveAllTrie();
}

void saveTrie(ofstream& fout, Trie& trie) {
    trie.save(fout);
}

void saveAllTrie() {
    for (int i = 0; i <= 4; i++) {
        ofstream fout(dataPath[i]);
        saveTrie(fout, trieLists[i]);
    }
}

void buildList(ifstream& fin, List& list) {
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
            buildList(fin, historyLists[i]);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            ifstream fin(favoritePath[i]);
            buildList(fin, favoriteLists[i]);
        }
    }
}

void saveList(ofstream& fout, List& list) {
    list.save(fout);
}

void saveAllList(bool mode) {
    if (mode == 0) {
        for (int i = 0; i <= 4; i++) {
            ofstream fout(historyPath[i]);
            saveList(fout, historyLists[i]);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            ofstream fout(favoritePath[i]);
            saveList(fout, favoriteLists[i]);
        }
    }
}

void freeMemory() {
    for (int i = 0; i <= 4; i++) trieLists.clear();
}