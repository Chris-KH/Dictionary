#include"Build.h"
#include"Trie.h"
#include"Definition.h"

using namespace std;


//Index 0 for English - Vietnamese
//Index 1 for Vietnamese - English
//Index 2 for English - English
//Index 3 for Slang
//Index 4 for Emoji

int main(int argc, char *argv[]) {

    QCoreApplication app(argc, argv);

    if (_setmode(_fileno(stdin), _O_U16TEXT) == -1 && _setmode(_fileno(stdout), _O_U8TEXT) == -1) {
        return 0;
    }


    /* vector<pair<double, Word>> v = defSearch(trieLists[0], s);
    for (int i = 0; i < (int)v.size() && i < 5; i++) {
        Word word = v[i].second;
        fout << utf16_to_utf8(word.key) << "\n";
        fout << utf16_to_utf8(word.type) << "\n";
        fout << utf16_to_utf8(word.spelling) << "\n";
        for (int i = 0; i < (int)word.definitions.size(); i++) {
            fout << "-" << utf16_to_utf8(word.definitions[i]) << "|";
        }
        fout << "\n\n";
    } */



    setChar();
    buildAllTrie();


    // Mở file để ghi dữ liệu
    QFile fout("output.txt");
    if (!fout.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening file for writing";
        return 1; // Trả về mã lỗi 1
    }

    QFile inputFile("input.txt"); // Tên tệp đầu vào
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening file for reading";
        return 1;
    }

    QTextStream in(&inputFile);
    QTextStream out(&fout);

    QString input = in.readLine();

    int systemMode = 0;

    // Đọc dữ liệu từ bàn phím
    // Tạo đối tượng `Word` và `QVector<Word>`
    Word word;
    QVector<Word> list;

    // Giả sử `systemMode` đã được thiết lập đúng
    if (trieLists[systemMode].search(word, input, list)) {
        qDebug() << "Search OK";
        out << word.key << "\n";
        out << word.type << "\n";
        out << word.spelling << "\n";
        for (const QString& def : word.definitions) {
            out << "-" << def << "\n";
        }
        historyLists[systemMode].insert(input);
    } else {
        qDebug() << "Search fail.";
    }

    for (const Word& w : list) {
        out << w.key << "\n";
        out << w.type << "\n";
        out << w.spelling << "\n";
        for (const QString& def : w.definitions) {
            out << "-" << def << "\n";
        }
        out << "\n";
    }

    fout.close();

    // Đổi qua lại giữa các kiểu data để test
    // s thì mở dataset ra copy rồi paste khi build xong trie
    /* cout << "Mode: ";
    wcin >> systemMode;
    cin.ignore();
    wcin.ignore();
    int i = 3;
    while (i--) {
        wstring s;
        cout << "Input string: ";
        getline(wcin, s);
        Word word;
        if (trieLists[systemMode].search(word, s)) {
            cout << "Search OK\n";
            fout << utf16_to_utf8(word.key) << "\n";
            fout << utf16_to_utf8(word.type) << "\n";
            fout << utf16_to_utf8(word.spelling) << "\n";
            for (int i = 0; i < (int)word.definitions.size(); i++) {
                fout << "-" << utf16_to_utf8(word.definitions[i]) << "\n";
            }
            historyLists[systemMode].insert(s);
        } else cout << "Search fail.\n";

        Word word_remove;
        cout << "Input string to remove: ";
        getline(wcin, s);
        trieLists[systemMode].remove(s);
        if (trieLists[systemMode].search(word_remove, s)) {
            cout << "Remove fail.\n";
            fout << utf16_to_utf8(word_remove.key) << "\n";
            fout << utf16_to_utf8(word_remove.type) << "\n";
            fout << utf16_to_utf8(word_remove.spelling) << "\n";
            for (int i = 0; i < (int)word_remove.definitions.size(); i++) {
                fout << "-" << utf16_to_utf8(word_remove.definitions[i]) << "\n";
            }
        }
        else cout << "Remove ok\n";
        bool ok;
        cout << "Reset?";
        wcin >> ok;
        wcin.ignore();
        if (ok) resetToOrigin(trieLists[systemMode]);
    } */


    //fout.close();
    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
    return 0;
}
