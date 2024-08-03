#include"Build.h"
#include"Trie.h"

using namespace std;

//Index 0 for English - Vietnamese
//Index 1 for Vietnamese - English
//Index 2 for English - English
//Index 3 for Slang
//Index 4 for Emoji

int main() {
    setChar();
    
    /*
    wstring s;
    getline(wcin, s);
    wofstream fout("output.txt");
    fout << s;
    fout.close();
    */
    /*wofstream fout("output.txt");
    buildAll();
    Word word;
    if (trieLists[0].search(word, L"a b c")) {
        fout << word.key << L"\n";
        fout << word.type << L"\n";
        fout << word.spelling << L"\n";
        for (int i = 0; i < word.definitions.size(); i++) {
            fout << L"-" << word.definitions[i] << L"\n";
        }
    }*/
    /*
    engEng_Trie.remove(L";-)");
    if (engEng_Trie.search(word, L";-)")) {
        wcout << word.key << L"\n";
        wcout << word.type << L"\n";
        wcout << word.spelling << L"\n";
        for (int i = 0; i < word.definitions.size(); i++) {
            wcout << L"-" << word.definitions[i] << L"\n";
        }
    }
    else cout << "NO";
    */

    //saveAll();
    freeMemory();
	return 0;
}