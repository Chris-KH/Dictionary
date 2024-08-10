#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "engviet.h"
#include "engeng.h"
#include "vieteng.h"
#include  "emoij.h"
#include "slang.h"
#include "EditDefinitionDialog.h"
#include <QFile>
#include <QString>
#include <vector>
#include <QDebug>
#include <QSplitter>
#include <QListWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QMessageBox>
#include <QLineEdit>
#include <QInputDialog>
#include <QScrollBar>


using namespace std;
using namespace Qt;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
struct word{
    QString name,definition;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    vector<word> engVietWords,engEngWords,vietEngWords,slangWords,emoijWords,historyWords,favouristWords;
private slots:
    void on_engVietButton_clicked();
    void on_engEngButton_clicked();
    void on_vietEngButton_clicked();
    void on_emoijButton_clicked();
    void on_slangButton_clicked();
private:
    Ui::MainWindow *ui;
    EngViet *engViet;
    EngEng *engEng;
    VietEng *vietEng;
    emoij *emoi;
    Slang *slang;
public:
    void addWordToList(QListWidget *wordListWidget, const QString &word, const QString &definition, QLabel *definitionLabel);
    void deleteWordFromList(QListWidget *wordListWidget, QListWidgetItem *item);
    void searchWord(QListWidget *wordListWidget, const QString &searchTerm, const std::vector<word> &words, QLabel *definitionLabel);
    void showWordDefinition(QString &word, QString &definition);
    void deleteWord(const QString word);
    void editWordDefinition(const QString &word, QLabel *definitionLabel,QString oldDefinition);
};
#endif // MAINWINDOW_H
