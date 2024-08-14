#include"VietNamese.h"

QVector<int> mp(10005);
QVector<int> mp_upper(10005);

/*QString utf8_to_utf16(const QString& utf8_str) {
    QString utf16_str;
    utf8::utf8to16(utf8_str.begin(), utf8_str.end(), back_inserter(utf16_str));
    return utf16_str;
}*/

// Chuyển đổi std::QString sang UTF-8 std::string
/*QString utf16_to_utf8(const QString& utf16_str) {
    QString utf8_str;
    utf8::utf16to8(utf16_str.begin(), utf16_str.end(), back_inserter(utf8_str));
    return utf8_str;
}*/


QString utf8_to_utf16(const QString& utf8_str) {
    QString utf16_str;

    // Chuyển đổi QString sang std::string để tương thích với utf8::utf8to16
    std::string utf8_str_std = utf8_str.toStdString();

    // Sử dụng utf8::utf8to16 với std::string
    try {
        utf8::utf8to16(utf8_str_std.begin(), utf8_str_std.end(), back_inserter(utf16_str));
    } catch(const std::exception& e) {
        cerr<<"Error converting UTF-8 to UTF-16"<<e.what()<<std::endl;
    return QString();
    }
    return utf16_str;
}

QString utf16_to_utf8(const QString& utf16_str) {
    QString utf8_str;

    std::string utf16_str_std = utf16_str.toStdString();

    try {
        utf8::utf16to8(utf16_str_std.begin(), utf16_str_std.end(), back_inserter(utf8_str));
    } catch (const std::exception& e) {
        // Xử lý lỗi chuyển đổi
        std::cerr << "Error converting UTF-16 to UTF-8: " << e.what() << std::endl;
        return QString(); // Trả về chuỗi rỗng nếu lỗi
    }

    return utf8_str;
}
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
