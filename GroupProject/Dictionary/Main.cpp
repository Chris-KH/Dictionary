#include"Build.h"
#include"Trie.h"
#include"Definition.h"

using namespace std;

//Index 0 for English - Vietnamese
//Index 1 for Vietnamese - English
//Index 2 for English - English
//Index 3 for Slang
//Index 4 for Emoji

int main() {
    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1 && _setmode(_fileno(stdout), _O_U8TEXT) == -1) {
        return 0;
    }
    
    
    //ofstream fout("output.txt");
    setChar();
    buildAllTrie();

    /* vector<pair<double, Word>> v = defSearch(trieLists[0], s);
    for (int i = 0; i < (int)v.size() && i < 5; i++) {
        Word word = v[i].second;
        fout << utf16_to_utf8(word.key) << "\n";
        fout << utf16_to_utf8(word.type) << "\n";
        fout << utf16_to_utf8(word.spelling) << "\n";
        for (int i = 0; i < (int)word.definitions.size(); i++) {
            fout << "-" << utf16_to_utf8(word.definitions[i]) << "|";
        }
        fout << "\n\n";
    } */

    /* cout << "Mode: ";
    wcin >> system_Mode;
    cin.ignore();
    wcin.ignore();
    int i = 1;
    while (i--) {
        wstring s;
        cout << "Input string: ";
        getline(wcin, s);
        Word word;
        vector<Word> list;
        if (trieLists[system_Mode].search(word, s, list)) {
            cout << "Search OK\n";
            fout << utf16_to_utf8(word.key) << "\n";
            fout << utf16_to_utf8(word.type) << "\n";
            fout << utf16_to_utf8(word.spelling) << "\n";
            for (int i = 0; i < (int)word.definitions.size(); i++) {
                fout << "-" << utf16_to_utf8(word.definitions[i]) << "\n";
            }
            historyLists[system_Mode].insert(s);
        } else cout << "Search fail.\n";

        for (int j = 0; j < (int)list.size(); j++) {
            fout << utf16_to_utf8(list[j].key) << "\n";
            fout << utf16_to_utf8(list[j].type) << "\n";
            fout << utf16_to_utf8(list[j].spelling) << "\n";
            for (int k = 0; k < (int)list[j].definitions.size(); k++) {
                fout << "-" << utf16_to_utf8(list[j].definitions[k]) << "\n";
            }
            fout << "\n";
        }
    } */

    // Đổi qua lại giữa các kiểu data để test
    // s thì mở dataset ra copy rồi paste khi build xong trie
    /* cout << "Mode: ";
    wcin >> system_Mode;
    cin.ignore();
    wcin.ignore();
    int i = 3;
    while (i--) {
        wstring s;
        cout << "Input string: ";
        getline(wcin, s);
        Word word;
        if (trieLists[system_Mode].search(word, s)) {
            cout << "Search OK\n";
            fout << utf16_to_utf8(word.key) << "\n";
            fout << utf16_to_utf8(word.type) << "\n";
            fout << utf16_to_utf8(word.spelling) << "\n";
            for (int i = 0; i < (int)word.definitions.size(); i++) {
                fout << "-" << utf16_to_utf8(word.definitions[i]) << "\n";
            }
            historyLists[system_Mode].insert(s);
        } else cout << "Search fail.\n";

        Word word_remove;
        cout << "Input string to remove: ";
        getline(wcin, s);
        trieLists[system_Mode].remove(s);
        if (trieLists[system_Mode].search(word_remove, s)) {
            cout << "Remove fail.\n";
            fout << utf16_to_utf8(word_remove.key) << "\n";
            fout << utf16_to_utf8(word_remove.type) << "\n";
            fout << utf16_to_utf8(word_remove.spelling) << "\n";
            for (int i = 0; i < (int)word_remove.definitions.size(); i++) {
                fout << "-" << utf16_to_utf8(word_remove.definitions[i]) << "\n";
            }
        }
        else cout << "Remove ok\n";
        bool ok;
        cout << "Reset?";
        wcin >> ok;
        wcin.ignore();
        if (ok) resetToOrigin(trieLists[system_Mode]);
    } */
   

    //fout.close();
    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
	return 0;
}