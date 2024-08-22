#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "engviet.h"
#include "GameMode.h"
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
#include <QStringListModel>
#include "DictionnaryMode.h"
#include "Lib/Trie.h"
#include "Lib/Build.h"
#include "Lib/Definition.h"
#include "Lib/VietNamese.h"
#include "Lib/Game.h"
#include <QStringList>
#include <QCompleter>
#include <QScrollArea>
#include <random>

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
    DictionaryMode currentMode;
    GameMode currentGameMode;
    QVector<QString> gameWords;
    int index;
public slots:
    void on_engVietButton_clicked();
    void on_engEngButton_clicked();
    void on_vietEngButton_clicked();
    void on_emoijButton_clicked();
    void on_slangButton_clicked();
private:
    Ui::MainWindow *ui;
    EngViet *engViet;


public:
    void updateCompleterModel(QCompleter *completer,  QVector<Word> &currentList);
    void addWordToList(QListWidget *wordListWidget, Word &word,QLabel *definitionLabel);
    void deleteWordFromList(QListWidget *wordListWidget, QListWidgetItem *item);
    void searchWord(QListWidget *wordListWidget,  QString &searchTerm,  QVector<Word> &currentList, QLabel *definitionLabel);
    void showWordDefinition(QString &word, QString &definition);
    void deleteWord( QString word);
    void editWordDefinition(Word &word, QLabel *definitionLabel);
    void addWordToFavouriteList(QString key);
    void searchDefinition(QListWidget *wordListWidget,  QString &searchTerm,  std::vector<word> &words, QLabel *definitionLabel);
    void searchByDefinition(QListWidget *wordListWidget,QLabel *definitionLabel);
    void addNewWord();
    void suggestWord( QVector<Word> &suggestList);
};
#endif // MAINWINDOW_H
