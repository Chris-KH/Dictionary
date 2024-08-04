#include"Global.h"

vector<Trie> trieLists(5);
vector<List> historyLists(5);
vector<List> favoriteLists(5);

vector<string> originDataPath = { "../Dataset/Eng_Vie.txt", "../Dataset/Vie_Eng.txt",
        "../Dataset/Eng_Eng.txt", "../Dataset/Slang.txt", "../Dataset/Emoji.txt"
};

vector<string> storyDir = { "../story/English-Vietnamese", "../story/Vietnamese-English",
"../story/English-English", "../story/Slang", "../story/Emoji"
};

vector<string> dataPath = { "../story/English-Vietnamese/Eng_Vie.txt", "../story/Vietnamese-English/Vie_Eng.txt",
"../story/English-English/Eng_Eng.txt", "../story/Slang/Slang.txt", "../story/Emoji/Emoji.txt"
};
 
vector<string> historyPath = { "../story/English-Vietnamese/history.txt", "../story/Vietnamese-English/history.txt",
"../story/English-English/history.txt", "../story/Slang/history.txt", "../story/Emoji/history.txt"
};

vector<string> favoritePath = { "../story/English-Vietnamese/favorite.txt", "../story/Vietnamese-English/favorite.txt",
"../story/English-English/favorite.txt", "../story/Slang/favorite.txt", "../story/Emoji/favorite.txt"
};

Trie currentTrie;
List currentHistory;
List currentFavorite;
