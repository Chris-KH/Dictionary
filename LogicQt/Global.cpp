#include"Global.h"

int system_Mode;

QVector<Trie> trieLists(5);
QVector<List> historyLists(5);
QVector<List> favoriteLists(5);

QVector<QString> originDataPath = { "../Dataset/Eng_Vie.txt", "../Dataset/Vie_Eng.txt",
        "../Dataset/Eng_Eng.txt", "../Dataset/Slang.txt", "../Dataset/Emoji.txt"
};

QVector<QString> storyDir = { "../story/English-Vietnamese", "../story/Vietnamese-English",
"../story/English-English", "../story/Slang", "../story/Emoji"
};

QVector<QString> dataPath = { "../story/English-Vietnamese/Eng_Vie.txt", "../story/Vietnamese-English/Vie_Eng.txt",
"../story/English-English/Eng_Eng.txt", "../story/Slang/Slang.txt", "../story/Emoji/Emoji.txt"
};
 
QVector<QString> historyPath = { "../story/English-Vietnamese/history.txt", "../story/Vietnamese-English/history.txt",
"../story/English-English/history.txt", "../story/Slang/history.txt", "../story/Emoji/history.txt"
};

QVector<QString> favoritePath = { "../story/English-Vietnamese/favorite.txt", "../story/Vietnamese-English/favorite.txt",
"../story/English-English/favorite.txt", "../story/Slang/favorite.txt", "../story/Emoji/favorite.txt"
};

QVector<QVector<Word*>> listWord(5);

Trie currentTrie;
List currentHistory;
List currentFavorite;
