#pragma once
#include<bits/stdc++.h>
#include<io.h>
#include<fcntl.h>
#include<codecvt>

using namespace std;

class Word {
public:
	string key;
	string type;
	vector<string> definitions;
	Word();
	Word(string key, string type, string def);
	void addDefinition(string def);
	void removeDefinition(int idx);
};

const wchar_t vietnamese_chars[] = {
        L'a', L'á', L'à', L'ả', L'ã', L'ạ',
        L'ă', L'ắ', L'ằ', L'ẳ', L'ẵ', L'ặ',
        L'â', L'ấ', L'ầ', L'ẩ', L'ẫ', L'ậ',
        L'e', L'é', L'è', L'ẻ', L'ẽ', L'ẹ',
        L'ê', L'ế', L'ề', L'ể', L'ễ', L'ệ',
        L'i', L'í', L'ì', L'ỉ', L'ĩ', L'ị',
        L'o', L'ó', L'ò', L'ỏ', L'õ', L'ọ',
        L'ô', L'ố', L'ồ', L'ổ', L'ỗ', L'ộ',
        L'ơ', L'ớ', L'ờ', L'ở', L'ỡ', L'ợ',
        L'u', L'ú', L'ù', L'ủ', L'ũ', L'ụ',
        L'ư', L'ứ', L'ừ', L'ử', L'ữ', L'ự',
        L'y', L'ý', L'ỳ', L'ỷ', L'ỹ', L'ỵ',
        L'đ' };