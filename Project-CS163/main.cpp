#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QFile file(":/styles/styles.qss"); // Use relative or absolute path
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        a.setStyleSheet(styleSheet);
        file.close();

    } else {
        qWarning("Unable to open stylesheet file.");
    }

    MainWindow w;
    word wd;
    wd.name = "application"; wd.definition = "đơn xin\nsự chuyên cần\nthuốc mỡ";
    w.engVietWords.push_back(wd);
    wd.name = "capable"; wd.definition = "có năng lực\ncó khả năng";
    w.engVietWords.push_back(wd);
    wd.name = "gorgeous"; wd.definition = "lộng lẫy\ntuyệt vời";
    w.engVietWords.push_back(wd);
    w.show();
    return a.exec();
}
