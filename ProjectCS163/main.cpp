#include "mainwindow.h"
#include "Lib/Global.h"
#include <fstream>
#include <QApplication>
#include <QDebug>

using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QFile file(":/styles/styles.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        a.setStyleSheet(styleSheet);
        file.close();

    } else {
        qWarning("Unable to open stylesheet file.");
    }

    setChar();
    buildAllTrie();
    MainWindow w;
    w.show();
    // saveAllTrie();
    // saveAllList(0);
    // saveAllList(1);
    // freeMemory();



    return a.exec();

}
