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
    //auto start = std::chrono::high_resolution_clock::now();  // Start timing

    setChar();
    buildAllTrie();

    //auto end = std::chrono::high_resolution_clock::now();  // End timing
    //auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
    //qDebug() <<"Loading data time: " << duration.count() << "ms";  // Output the duration

    MainWindow w;
    w.show();



    return a.exec();

}
