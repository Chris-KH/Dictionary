#include"Lists.h"

int List::find(wstring key) {
	for (int i = 0; i < (int)list.size(); i++) {
		if (list[i] == key) return i;
	}
	return -1;
}

void List::insert(wstring key) {
	int pos = find(key);
	if (pos == -1) list.push_back(key);
}

void List::erase(wstring key) {
	int pos = find(key);
	if (pos != -1) list.erase(list.begin() + pos);
}

void List::save(ofstream& fout) {
	for (int i = 0; i < (int)list.size(); i++) {
		fout << utf16_to_utf8(list[i]) << "\n";
	}
	fout.close();
}