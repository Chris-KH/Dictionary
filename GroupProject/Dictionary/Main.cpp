#include"Build.h"
#include"Trie.h"

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
    setChar();
    
    /*
    wstring s;
    getline(wcin, s);
    wofstream fout("output.txt");
    fout << s;
    fout.close();
    */

    /*wstring s;
    getline(wcin, s);
    wcout << s << L"\n";
    cout << int(s[0]) << " ";
    cout << "\n";
    cout << (int)L'ị';*/
    ofstream fout("output.txt");
    buildAllTrie();

    wstring s;
    cout << "Input string: ";
    getline(wcin, s);
    Word word;
    // Đổi qua lại giữa các kiểu data để test
    // s thì mở dataset ra copy rồi paste khi build xong trie
    if (trieLists[1].search(word, s)) {
        cout << "OK\n";
        fout << utf16_to_utf8(word.key) << "\n";
        fout << utf16_to_utf8(word.type) << "\n";
        fout << utf16_to_utf8(word.spelling) << "\n";
        for (int i = 0; i < (int)word.definitions.size(); i++) {
            fout << "-" << utf16_to_utf8(word.definitions[i]) << "\n";
        }
        historyLists[1].insert(s);
    }

    /*
    Word word_remove;
    cout << "Input string to remove: ";
    getline(wcin, s);
    trieLists[1].remove(s);
    if (trieLists[1].search(word_remove, s)) {
        fout << utf16_to_utf8(word_remove.key) << "\n";
        fout << utf16_to_utf8(word_remove.type) << "\n";
        fout << utf16_to_utf8(word_remove.spelling) << "\n";
        for (int i = 0; i < (int)word_remove.definitions.size(); i++) {
            fout << "-" << utf16_to_utf8(word_remove.definitions[i]) << "\n";
        }
    }
    else cout << "Not find\n";
    */

    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
	return 0;
}