#include"Build.h"

void buildTrie(wifstream& fin, Trie& trie) {
    while (!fin.eof()) {
        Word word;
        wstring line;
        for (int i = 0; i <= 4; i++) {
            getline(fin, line);
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
        trie.insert(word);
    }

    fin.close();
}

void buildAll() {
    for (int i = 0; i <= 4; i++) {
        wifstream fin(dataSetDir[i]);
        auto start = chrono::high_resolution_clock::now();

        buildTrie(fin, trieLists[i]);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << duration.count() << "ms\n";

        if (!filesystem::exists(storyDir[i])) filesystem::create_directories(storyDir[i]);
        if (!filesystem::exists(historyDir[i])) {
            ofstream fout(historyDir[i]);
            fout.close();
        }
        if (!filesystem::exists(favoriteDir[i])) {
            ofstream fout(favoriteDir[i]);
            fout.close();
        }
    }
}