#ifndef GAMEPLAYOPTION_H
#define GAMEPLAYOPTION_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "mainwindow.h"  // Ensure this is the correct path

class gamePlayOption : public QDialog
{
    Q_OBJECT

public:
    explicit gamePlayOption(MainWindow *parent = nullptr);
    ~gamePlayOption();

signals:
    void guessWordMode();
    void guessDefinitionMode();

private:
    QPushButton *guessWordButton;
    QPushButton *guessDefinitionButton;
    MainWindow *mainWindow;

private slots:
    void onGuessWordButtonClicked();
    void onGuessDefinitionButtonClicked();
};

#endif // GAMEPLAYOPTION_H
