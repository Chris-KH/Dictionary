#include"Word.h"

Word::Word() {
	this->key = L"";
	this->type = L"";
	this->isFavorite = false;
}

Word::Word(wstring key, wstring type, wstring def) {
	this->key = key;
	this->type = type;
	this->isFavorite = false;
	if (def.size() > 0) definitions.push_back(def);
}

void Word::addDefinition(wstring def) {
	if (def.size() == 0) return;
	for (int i = 0; i < (int)definitions.size(); i++) {
		if (definitions[i] == def) return;
	}
	definitions.push_back(def);
}

void Word::removeDefinition(int idx) {
	if (idx < definitions.size()) {
		definitions.erase(definitions.begin() + idx);
	}
}

void Word::addFavorite(Word* word)
{
	word->isFavorite = true;
}

void Word::removeFavorite(Word* word)
{
	word->isFavorite = false;
}