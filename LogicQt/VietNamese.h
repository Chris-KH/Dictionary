#ifndef VIETNAMESE_H
#define VIETNAMESE_H

#pragma once
#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QPair>
#include <QSet>
#include <QHash>
#include <QLocale>
#include <QTranslator>
#include <QThread>
#include <QMutex>
#include <QDebug>
#include <QChar>
#include <QDir>

#include<bits/stdc++.h>
#include<chrono>
#include<filesystem>
#include <io.h>
#include <fcntl.h>
#include <random>

#include "lib/utf8.h"

using namespace std;
using namespace Qt;


constexpr auto sizeChar = 169;


const QVector<QChar> acsiii= {
        L'\0', L'\x01', L'\x02', L'\x03', L'\x04', L'\x05', L'\x06', L'\a',
        L'\b',  L'\t',  L'\n', L'\v', L'\f',   L'\r',   L'\x0E', L'\x0F',
        L'\x10', L'\x11', L'\x12', L'\x13', L'\x14', L'\x15', L'\x16', L'\x17',
        L'\x18', L'\x19', L'\x1A', L'\x1B', L'\x1C', L'\x1D', L'\x1E', L'\x1F',
        L' ',   L'!',   L'"',   L'#',   L'$',   L'%',   L'&',   L'\'',
        L'(',   L')',   L'*',   L'+',   L',',   L'-',   L'.',   L'/',
        L'0',   L'1',   L'2',   L'3',   L'4',   L'5',   L'6',   L'7',
        L'8',   L'9',   L':',   ';',   L'<',   L'=',   L'>',   L'?',
        L'@',   L'[',   L'\\',  ']',   L'^',   L'_',
        L'`',   L'{',   L'|',   '}',   L'~',   L'\x7F'
};

const QVector<QChar> vietnamese_chars = {
    L'\0', L'\x01', L'\x02', L'\x03', L'\x04', L'\x05', L'\x06', L'\a',
    L'\b', L'\t',  L'\n', L'\v', L'\f', L'\r',   L'\x0E', L'\x0F',
    L'\x10', L'\x11', L'\x12', L'\x13', L'\x14', L'\x15', L'\x16', L'\x17',
    L'\x18', L'\x19', L'\x1A', L'\x1B', L'\x1C', L'\x1D', L'\x1E', L'\x1F',
    L' ', L'!', L'"',   L'#',   L'$',   L'%',   L'&',   L'\'',
    L'(', L')', L'*',   L'+',   L',',   L'-',   L'.',   L'/',
    L'0', L'1', L'2',   L'3',  L'4',   L'5',   L'6',   L'7',
    L'8', L'9', L':',   ';',  L'<',   L'=',   L'>',   L'?',
    L'@', L'[', L'\\',  ']',  L'^',   L'_',
    L'`', L'{', L'|',   '}',  L'~',   L'\x7F',
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

const QVector<QChar> vietnamese_chars_upper = {
    L'\0', L'\x01', L'\x02', L'\x03', L'\x04', L'\x05', L'\x06', L'\a',
    L'\b', L'\t',  L'\n', L'\v', L'\f', L'\r',   L'\x0E', L'\x0F',
    L'\x10', L'\x11', L'\x12', L'\x13', L'\x14', L'\x15', L'\x16', L'\x17',
    L'\x18', L'\x19', L'\x1A', L'\x1B', L'\x1C', L'\x1D', L'\x1E', L'\x1F',
    L' ', L'!', L'"',   L'#',   L'$',   L'%',   L'&',   L'\'',
    L'(', L')', L'*',   L'+',   L',',   L'-',   L'.',   L'/',
    L'0', L'1', L'2',   L'3',  L'4',   L'5',   L'6',   L'7',
    L'8', L'9', L':',   ';',  L'<',   L'=',   L'>',   L'?',
    L'@', L'[', L'\\',  ']',  L'^',   L'_',
    L'`', L'{', L'|',   '}',  L'~',   L'\x7F',
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

extern QVector<int> mp;
extern QVector<int> mp_upper;

QString utf8_to_utf16(const QString& utf8_str);
QString utf16_to_utf8(const QString& utf16_str);
void setChar();
QChar lowerCase(QChar c);
QChar upperCase(QChar c);

#endif // VIETNAMESE_H
