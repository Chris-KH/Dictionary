#pragma once

#include "Word.h"

class List {
private:
    QVector<QString> list;
public:
    int find(QString key);
    void insert(QString key);
    void erase(QString key);
    void save(QTextStream& fout);
};

