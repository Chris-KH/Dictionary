#include"VietNamese.h"

QVector<int> mp(10005);
QVector<int> mp_upper(10005);


void setChar() {
	for (int i = 0; i < 10000; i++) {
		mp[i] = -1;
		mp_upper[i] = -1;
	}
	int idx = 0;
    for (QChar x : vietnamese_chars) mp[x.unicode()] = idx++;
    idx = 0;
    for (QChar x : vietnamese_chars_upper) mp_upper[x.unicode()] = idx++;
}

QChar lowerCase(QChar c) {
    int index = mp_upper[c.unicode()];
    if (index >= 76 && index < sizeChar)
        return vietnamese_chars[index];
	return c;
}

QChar upperCase(QChar c) {
    int index = mp[c.unicode()];
    if (index >= 76 && index < sizeChar)
        return vietnamese_chars_upper[index];
	return c;
}
