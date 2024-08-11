#ifndef EDITDEFINITIONDIALOG_H
#define EDITDEFINITIONDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class EditDefinitionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDefinitionDialog(QWidget *parent = nullptr);
    QString getWord() const;
    QString getDefinition() const;
    void setWord(const QString &word);
    void setDefinition(const QString &definition);

private:
    QLineEdit *wordInput;
    QTextEdit *definitionInput;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // EDITDEFINITIONDIALOG_H
