#include"Build.h"
#include <QDebug>
#include <QDir>
#include <chrono>
#include <QFile>

void buildTrie(QFile& file, Trie& trie, const int mode) {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream fin(&file);

    while (!fin.atEnd()) {
        Word word;
        QString line;
        for (int i = 0; i <= 4; i++) {
            line = fin.readLine().trimmed();
            if (i == 0) word.key = line;
            if (i == 1 && line != "-") word.type = line;
            if (i == 2 && line != "-") word.spelling = line;
            if (i == 3) {
                QStringList definitions = line.split('|');
                for (QString def : definitions) {
                    word.addDefinition(def.trimmed());
                }
            }
        }

        if (!word.key.isEmpty()) {
            trie.insert(word);
            listWord[mode].push_back(word);
        }
    }

    file.close();
}


void buildAllTrie() {

    for (int i = 0; i <= 4; i++) {
        QFile file(QFile::exists(dataPath[i]) ? dataPath[i] : originDataPath[i]);
        auto start = std::chrono::high_resolution_clock::now();  // Start timing
        buildTrie(file, trieLists[i], i);  // Build the trie
        auto end = std::chrono::high_resolution_clock::now();  // End timing
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
        //qDebug() << duration.count() << "ms";  // Output the duration

        // Create directories if they do not exist
        if (!QDir().exists(storyDir[i])) QDir().mkpath(storyDir[i]);

        // Ensure historyPath and favoritePath files exist and are cleared
        if (!QFile::exists(historyPath[i])) {
            QFile historyFile(historyPath[i]);
            historyFile.open(QIODevice::WriteOnly);
            historyFile.close();
        }
        if (!QFile::exists(favoritePath[i])) {
            QFile favoriteFile(favoritePath[i]);
            favoriteFile.open(QIODevice::WriteOnly);
            favoriteFile.close();
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

void saveTrie(QFile& file, Trie& trie, const int mode) {
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream fout(&file);
        trie.save(fout);
        file.close();
    }
    else{
        qDebug()<<0;
    }
}

void saveAllTrie() {
    for (int i = 0; i <= 4; i++) {
        QFile file(dataPath[i]);

        saveTrie(file, trieLists[i], i);
    }
}


void buildList(QFile& file, List& list, const int mode) {
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QTextStream fin(&file);
    QString line;

    while (!fin.atEnd()) {
        line = fin.readLine().trimmed();
        if (!line.isEmpty()) list.insert(line);
    }
    file.close();
}

void buildAllList(bool mode) {
    if (mode == 0) {
        for (int i = 0; i <= 4; i++) {
            QFile file(historyPath[i]);
            buildList(file, historyLists[i], i);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            QFile file(favoritePath[i]);
            buildList(file, favoriteLists[i], i);
        }
    }
}

void saveList(QFile& file, List& list, const int mode) {
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream fout(&file);
        list.save(fout);
        file.close();
    }
}

void saveAllList(bool mode) {
    if (mode == 0) {
        for (int i = 0; i <= 4; i++) {
            QFile file(historyPath[i]);
            saveList(file, historyLists[i], i);
        }
    }
    else {
        for (int i = 0; i <= 4; i++) {
            QFile file(favoritePath[i]);
            saveList(file, favoriteLists[i], i);
        }
    }
}

void resetToOrigin(Trie& trie) {
    trie.clear();
    listWord[system_Mode].clear();
    historyLists[system_Mode].clear();
    favoriteLists[system_Mode].clear();

    QFile::remove(dataPath[system_Mode]);
    QFile::remove(historyPath[system_Mode]);
    QFile::remove(favoritePath[system_Mode]);

    QFile historyFile(historyPath[system_Mode]);
    historyFile.open(QIODevice::WriteOnly);
    historyFile.close();

    QFile favoriteFile(favoritePath[system_Mode]);
    favoriteFile.open(QIODevice::WriteOnly);
    favoriteFile.close();

    Trie temp;
    QFile file(originDataPath[system_Mode]);
    buildTrie(file, temp, system_Mode);
    QFile file2(dataPath[system_Mode]);
    trie = temp;
    saveTrie(file2,trie,system_Mode);
    trie.setListHistory(&historyLists[system_Mode]);
    trie.setListFavorite(&favoriteLists[system_Mode]);
}


void freeMemory() {
    for (int i = 0; i <= 4; i++) trieLists.clear();
}
