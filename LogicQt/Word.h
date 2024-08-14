#pragma once
#include"VietNamese.h"

class Word {
public:
    QString key; //Ex: dog, cat...
    QString type; // Noun, adj...
    QString spelling; // /ˈap(ə)l/
    QVector<QString> definitions; //Just definitions
	Word();
    Word(QString key, QString type, QString def);
    void addDefinition(QString def);
	void removeDefinition(int idx);
};
