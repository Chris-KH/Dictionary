#include "gamePlayOption.h"

gamePlayOption::gamePlayOption(MainWindow *parent)
    : QDialog(parent), mainWindow(parent)
{
    setFixedSize(500, 240);
    setObjectName("gamePlayOption");

    QLabel *title = new QLabel("Option", this);
    title->setObjectName("titleGameOption");

    guessWordButton = new QPushButton("Guess the word", this);
    guessWordButton->setObjectName("guessWordButton");

    guessDefinitionButton = new QPushButton("Guess the definition", this);
    guessDefinitionButton->setObjectName("guessDefinitionButton");

    QVBoxLayout *buttonLayout = new QVBoxLayout;
    buttonLayout->addWidget(guessWordButton);
    buttonLayout->addWidget(guessDefinitionButton);

    QWidget *optionWidget = new QWidget(this);
    optionWidget->setLayout(buttonLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(title);
    mainLayout->addWidget(optionWidget);

    setLayout(mainLayout);

    connect(guessWordButton, &QPushButton::clicked, this, &gamePlayOption::onGuessWordButtonClicked);
    connect(guessDefinitionButton, &QPushButton::clicked, this, &gamePlayOption::onGuessDefinitionButtonClicked);
}

gamePlayOption::~gamePlayOption()
{
}

void gamePlayOption::onGuessWordButtonClicked()
{
    if (mainWindow) {
        emit guessWordMode();
        accept();
    }
}

void gamePlayOption::onGuessDefinitionButtonClicked()
{
    if (mainWindow) {
        emit guessDefinitionMode();
        accept();
    }
}
