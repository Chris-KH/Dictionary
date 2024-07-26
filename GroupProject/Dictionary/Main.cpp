#include"Trie.h"

using namespace std;

int main() {
    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1 || _setmode(_fileno(stdout), _O_U16TEXT) == -1) {
        std::cerr << "Error setting mode for stdin" << std::endl;
        return 1;
    }
    setChar();

    wcout << mp[L'à'];
	return 0;
}