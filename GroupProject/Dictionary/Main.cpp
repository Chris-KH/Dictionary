#include"Build.h"
#include"Trie.h"

using namespace std;

int main() {
    setChar();
    
    /*
    wstring s;
    getline(wcin, s);
    wofstream fout("output.txt");
    fout << s;
    fout.close();
    */

    buildAll();
    //Word word;
    //if (trieLists[3].search(word, L";-)")) {
    //    wcout << word.key << L"\n";
    //    wcout << word.type << L"\n";
    //    wcout << word.spelling << L"\n";
    //    for (int i = 0; i < word.definitions.size(); i++) {
    //        wcout << L"-" << word.definitions[i] << L"\n";
    //    }
    //}
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
	return 0;
}