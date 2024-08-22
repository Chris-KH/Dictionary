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
    ShowListOfWords(int mode , QWidget *parent = nullptr);
    ~ShowListOfWords();
    void addWordToList(QListWidget *wordListWidget, QString &key);

private:
// Reference to the words vector
    int mode;
    void setupUI();
    QVBoxLayout *mainLayout;
    QListWidget *wordListWidget;

private slots:

    void onDeleteButtonClicked(QListWidget *wordListWidget,QString key, QListWidgetItem *item);
};


#endif // SHOWLISTOFWORDS_H
