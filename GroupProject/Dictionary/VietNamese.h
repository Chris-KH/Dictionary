#pragma once
#include<bits/stdc++.h>
#include<io.h>
#include<fcntl.h>
#include<codecvt>

using namespace std;

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
    L'b', L'c', L'd', L'đ', L'g', L'h', L'k', L'l', L'm', L'n',
    L'p', L'q', L'r', L's', L't', L'v', L'x', L'f', L'j', L'w', L'z'
};

const wchar_t vietnamese_chars_upper[] = {
    L'A', L'Á', L'À', L'Ả', L'Ã', L'Ạ',
    L'Ă', L'Ắ', L'Ằ', L'Ẳ', L'Ẵ', L'Ặ',
    L'Â', L'Ấ', L'Ầ', L'Ẩ', L'Ẫ', L'Ậ',
    L'E', L'É', L'È', L'Ẻ', L'Ẽ', L'Ẹ',
    L'Ê', L'Ế', L'Ề', L'Ể', L'Ễ', L'Ệ',
    L'I', L'Í', L'Ì', L'Ỉ', L'Ĩ', L'Ị',
    L'O', L'Ó', L'Ò', L'Ỏ', L'Õ', L'Ọ',
    L'Ô', L'Ố', L'Ồ', L'Ổ', L'Ỗ', L'Ộ',
    L'Ơ', L'Ớ', L'Ờ', L'Ở', L'Ỡ', L'Ợ',
    L'U', L'Ú', L'Ù', L'Ủ', L'Ũ', L'Ụ',
    L'Ư', L'Ứ', L'Ừ', L'Ử', L'Ữ', L'Ự',
    L'Y', L'Ý', L'Ỳ', L'Ỷ', L'Ỹ', L'Ỵ',
    L'B', L'C', L'D', L'Đ', L'G', L'H', L'K', L'L', L'M', L'N',
    L'P', L'Q', L'R', L'S', L'T', L'V', L'X', L'F', L'J', L'W', L'Z'
};

extern int mp[10000];
extern int mp_upper[10000];

void setChar();
wchar_t lowerCase(wchar_t c);
wchar_t upperCase(wchar_t c);