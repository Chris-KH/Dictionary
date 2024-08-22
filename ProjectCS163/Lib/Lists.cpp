#include"Lists.h"
#include <QDebug>
int List::find(QString key) {
	for (int i = 0; i < (int)list.size(); i++) {
		if (list[i] == key) return i;
	}
	return -1;
}

void List::insert(QString key) {
	int pos = find(key);
	if (pos == -1) list.push_back(key);
}

void List::erase(QString key) {
	int pos = find(key);
    if (pos != -1)
        list.erase(list.constBegin() + pos);
}

void List::save(QTextStream& fout) {
    for (const auto& item : list) {
        fout << item << "\n";
    }
}

void List::showWords(){
    for(QString s:list){
        qDebug()<<s;
    }
}

QVector<QString> List::getAllWords(){
    return list;
}

