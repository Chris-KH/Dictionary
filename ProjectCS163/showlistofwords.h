#ifndef SHOWLISTOFWORDS_H
#define SHOWLISTOFWORDS_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include "EditDefinitionDialog.h"
#include "mainwindow.h"



class ShowListOfWords : public QDialog
{
    Q_OBJECT

public:
    ShowListOfWords(List list, QWidget *parent = nullptr);
    ~ShowListOfWords();
    void searchWord(QListWidget *wordListWidget, QString key);

private:
    List list; // Reference to the words vector



    void setupUI();

private slots:

    void onDeleteButtonClicked(QListWidget *wordListWidget,QString key, QListWidgetItem *item);
};


#endif // SHOWLISTOFWORDS_H
