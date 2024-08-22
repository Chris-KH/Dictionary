#include "gamePlayDialog.h"


gamePlayDialog::gamePlayDialog(MainWindow *parent, GameMode mode)
    : QDialog(parent), mainWindow(parent), gameMode(mode)
{
    setObjectName("gamePlayDialog");
    setStyleSheet("background-color: #BCE1ED");

    setCorrectKey(mainWindow->gameWords[1]);
    QVector<QString> ramdomWords(mainWindow->gameWords.begin()+1,mainWindow->gameWords.end());

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(ramdomWords.begin(), ramdomWords.end(), rng);

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
        optionButtons[i]->setText(ramdomWords[i]);
        optionButtons[i]->setStyleSheet(
            "#optionButtons {"
            "    padding: 6px 0;"
            "    width: 160px;"
            "    font-size: 18px;"
            "    margin: 5px 80px;"
            "    background-color: white;"
            "} "
            "#optionButtons:hover {"
            "    background-color: #B0F6E1;"
            "} "
            );
        buttonLayout->addWidget(optionButtons[i]);
        connect(optionButtons[i], &QPushButton::clicked, this, &gamePlayDialog::handleOptionButtonClicked);
    }


    questionLabel->setText(mainWindow->gameWords[0]);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(resultLabel);

    setLayout(mainLayout);
}

gamePlayDialog::~gamePlayDialog()
{
}

void gamePlayDialog::checkAnswer(const QString& selectedOptionText)
{
    if (selectedOptionText == correctKey) {
        resultLabel->setText("Your answer is correct!");
    } else {
        resultLabel->setText("Your answer is not correct.");
    }
}

void gamePlayDialog::handleOptionButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString selectedOptionText = clickedButton->text();
        checkAnswer(selectedOptionText);
    }
}

QString gamePlayDialog::get(){
    return correctKey;
}

void gamePlayDialog::setCorrectKey(QString key){
    correctKey=key;
}
