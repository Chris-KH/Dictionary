#include"Trie.h"

using namespace std;

int main() {
    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1 || _setmode(_fileno(stdout), _O_U16TEXT) == -1) {
        cerr << "Error setting mode for stdin" << "\n";
        return 1;
    }
    setChar();
    //wcout << lowerCase(L'Ạ');
	return 0;
}