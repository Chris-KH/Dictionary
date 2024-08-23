#ifndef EDITDEFINITIONDIALOG_H
#define EDITDEFINITIONDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainwindow.h"

class EditDefinitionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefinitionDialog(MainWindow *parent = nullptr,int mode=0);
    ~EditDefinitionDialog();


    QString getKey() ;
    QString getDefinition() ;
    QString getSpelling();
    QString getType();
    void setType(QString &type);
    void setSpelling(QString spelling);
    void setKey(QString &word);
    void setDefinition(QString &definition);
    int mode;


private:
    MainWindow *mainWindow;
    QVector<QString> gamePlayWords;
    QLineEdit *wordInput;
    QTextEdit *definitionInput;
    QLineEdit *typeInput;
    QLineEdit *spellingInput;
    QPushButton *okButton;
    QPushButton *cancelButton;

};

#endif // EDITDEFINITIONDIALOG_H
