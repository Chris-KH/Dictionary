#ifndef GAMEPLAYDIALOG_H
#define GAMEPLAYDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "mainwindow.h"
#include "GameMode.h"

class gamePlayDialog : public QDialog
{
    Q_OBJECT

public:
    explicit gamePlayDialog(MainWindow *parent = nullptr, GameMode mode = GameMode::GuessWord);
    ~gamePlayDialog();
    QString get();
    void setCorrectKey(QString key);

private:
    QLabel *questionLabel;
    QLabel *resultLabel;
    QLabel *questionWord;
    QPushButton *optionButtons[4];
    MainWindow *mainWindow;
    GameMode gameMode;
    void checkAnswer(const QString& selectedOptionText);
    QString correctKey;

private slots:
    void handleOptionButtonClicked();
};

#endif // GAMEPLAYDIALOG_H
