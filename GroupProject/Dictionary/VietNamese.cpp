#include"VietNamese.h"

int mp[10000];
int mp_upper[10000];

wstring utf8_to_utf16(const string& utf8_str) {
	wstring utf16_str;
	utf8::utf8to16(utf8_str.begin(), utf8_str.end(), back_inserter(utf16_str));
	return utf16_str;
}

// Chuyển đổi std::wstring sang UTF-8 std::string
string utf16_to_utf8(const wstring& utf16_str) {
	string utf8_str;
	utf8::utf16to8(utf16_str.begin(), utf16_str.end(), back_inserter(utf8_str));
	return utf8_str;
}

void setChar() {
	for (int i = 0; i < 10000; i++) {
		mp[i] = -1;
		mp_upper[i] = -1;
	}
	int idx = 0;
	for (int x : vietnamese_chars) mp[x] = idx++;
	idx = 0;
	for (int x : vietnamese_chars_upper) mp_upper[x] = idx++;
}

wchar_t lowerCase(wchar_t c) {
	int index = mp_upper[c];
	if (index >= 76 && index < sizeChar) return vietnamese_chars[index];
	return c;
}

wchar_t upperCase(wchar_t c) {
	int index = mp[c];
	if (index >= 76 && index < sizeChar) return vietnamese_chars_upper[index];
	return c;
}