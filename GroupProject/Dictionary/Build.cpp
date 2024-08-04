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

void buildAll() {
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
    saveAll();
}

void saveTrie(ofstream& fout, Trie& trie) {
    trie.save(fout);
}

void saveAll() {
    for (int i = 0; i <= 4; i++) {
        ofstream fout(dataPath[i]);
        saveTrie(fout, trieLists[i]);
    }
}

void freeMemory() {
    for (int i = 0; i <= 4; i++) trieLists.clear();
}