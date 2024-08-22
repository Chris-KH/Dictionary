#ifndef SEARCHBYDEFINITION_H
#define SEARCHBYDEFINITION_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

class SearchByDefinition : public QDialog
{
    Q_OBJECT

public:
    explicit SearchByDefinition(QWidget *parent = nullptr);
    QString getDefinition() ;
    void setDefinition( QString &definition);

private:
    QTextEdit *definitionInput;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // SEARCHBYDEFINITION_H
