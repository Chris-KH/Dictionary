#include "gamePlayDialog.h"

gamePlayDialog::gamePlayDialog(MainWindow *parent, GameMode mode)
    : QDialog(parent), mainWindow(parent), gameMode(mode)
{
    std::vector<word> gamePlayWords;
    if (mainWindow->currentMode == DictionaryMode::EngViet) {
        gamePlayWords = mainWindow->engVietWords;
    } else if (mainWindow->currentMode == DictionaryMode::EngEng) {
        gamePlayWords = mainWindow->engEngWords;
    } else if (mainWindow->currentMode == DictionaryMode::VietEng) {
        gamePlayWords = mainWindow->vietEngWords;
    } else if (mainWindow->currentMode == DictionaryMode::Slang) {
        gamePlayWords = mainWindow->slangWords;
    } else {
        gamePlayWords = mainWindow->emoijWords;
    }
    setObjectName("gamePlayDialog");
    // setFixedSize(600,480);
    questionLabel = new QLabel(this);
    resultLabel = new QLabel(this);
    questionWord = new QLabel(this);
    questionLabel->setObjectName("questionLabel");
    resultLabel->setObjectName("resultLabel");
    questionWord->setObjectName("wordLabel");
    questionWord->setText("Word: ");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(questionLabel);
    mainLayout->addWidget(questionWord);
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    for (int i = 0; i < 4; ++i) {

        optionButtons[i] = new QPushButton(this);
        optionButtons[i]->setObjectName("optionButtons");
        optionButtons[i]->setText("Option");
        buttonLayout->addWidget(optionButtons[i]);
        connect(optionButtons[i], &QPushButton::clicked, this, &gamePlayDialog::handleOptionButtonClicked);
    }

    if (gameMode == GameMode::GuessWord) {
        questionLabel->setText("Guess the word for the given definition:");
    } else if (gameMode == GameMode::GuessDefinition) {
        questionLabel->setText("Guess the definition for the given word:");
    }

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(resultLabel);

    setLayout(mainLayout);
}

gamePlayDialog::~gamePlayDialog()
{
}

void gamePlayDialog::checkAnswer(int selectedOption)
{
    resultLabel->setText("Your answer is correct!"); // Update based on the actual logic
}

void gamePlayDialog::handleOptionButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    int selectedOption = -1;

    for (int i = 0; i < 4; ++i) {
        if (clickedButton == optionButtons[i]) {
            selectedOption = i;
            break;
        }
    }

    if (selectedOption != -1) {
        checkAnswer(selectedOption);
    }
}
