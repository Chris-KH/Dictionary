#include"VietNamese.h"

int mp[10000];
int mp_upper[10000];

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
	if (index == -1) return c;
	return vietnamese_chars[index];
}

wchar_t upperCase(wchar_t c) {
	int index = mp[c];
	if (index == -1) return c;
	return vietnamese_chars_upper[index];
}