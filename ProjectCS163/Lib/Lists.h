#pragma once

#include <QTextStream>
#include <QVector>
#include <QString>
class List {
private:
    QVector<QString> list;
public:
    int find(QString key);
    void insert(QString key);
    void erase(QString key);
    void save(QTextStream& fout);
    void showWords();
    void clear();
    QVector<QString> getAllWords();
};

