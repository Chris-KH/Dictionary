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
    ShowListOfWords(std::vector<word> &words, QWidget *parent = nullptr);
    ~ShowListOfWords();

private:
    std::vector<word> &words; // Reference to the words vector
    QListWidget *wordListWidget;
    QLabel *definitionLabel;

    void setupUI();
    void populateList();
    void connectSignals();

private slots:
    void onViewButtonClicked(const QString &word, const QString &definition);
    void onDeleteButtonClicked(const QString &word, QListWidgetItem *item);
};


#endif // SHOWLISTOFWORDS_H
