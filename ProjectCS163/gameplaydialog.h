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
    explicit gamePlayDialog(MainWindow *parent = nullptr,GameMode mode = GameMode::GuessWord);
    ~gamePlayDialog();
    QString get();
    void setCorrectKey(QString key);
    void newGame();
    void onBackButtonClicked();

private:
     QPushButton *previousButton = nullptr;
    QLabel *questionLabel;
    QLabel *resultLabel;
    QLabel *questionWord;
    QPushButton *createNewGameButton;
    QPushButton *backButton;
    QPushButton *optionButtons[4];
    MainWindow *mainWindow;
    GameMode gameMode;
    void checkAnswer(QPushButton* clickedButton);
    QString correctKey;
    void setup();
private slots:
    void handleOptionButtonClicked();
};

#endif // GAMEPLAYDIALOG_H