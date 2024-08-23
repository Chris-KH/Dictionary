#include "gamePlayDialog.h"


gamePlayDialog::gamePlayDialog(MainWindow *parent, GameMode mode)
    : QDialog(parent), mainWindow(parent), gameMode(mode)
{
    setup();
}

gamePlayDialog::~gamePlayDialog()
{
}

void gamePlayDialog::setup(){
    setObjectName("gamePlayDialog");
    setStyleSheet("background-color: #BCE1ED");

    setCorrectKey(mainWindow->gameWords[1]);
    QVector<QString> ramdomWords(mainWindow->gameWords.begin()+1,mainWindow->gameWords.end());

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(ramdomWords.begin(), ramdomWords.end(), rng);

    createNewGameButton = new QPushButton(this);
    questionLabel = new QLabel(this);
    resultLabel = new QLabel(this);
    questionWord = new QLabel(this);

    if(mainWindow->currentGameMode==GameMode::GuessWord){
        questionLabel->setText("Choose the correct definition in the following word: ");
    }
    else{
        questionLabel->setText("Choose the correct word in the following definition: ");
    }
    questionLabel->setObjectName("questionLabel");
    resultLabel->setObjectName("resultLabel");
    questionWord->setObjectName("wordLabel");
    questionWord->setText(mainWindow->gameWords[0]);
    questionWord->setStyleSheet("background-color: white;"
                                "border-radius: 12px;"
                                "border: 0.1px solid black;"
                                "padding: 5px 20px;"
                                "max-width: 400px;");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(createNewGameButton);
    mainLayout->addWidget(questionLabel);
    mainLayout->addWidget(questionWord, 0, Qt::AlignCenter);
    createNewGameButton->setGeometry(500, 50, 0, 0);
    createNewGameButton->setObjectName("createNewGameButton");
    createNewGameButton->setStyleSheet("#createNewGameButton{"
                                       "background-color: white;"
                                       "border-radius: 8px;"
                                       "font-size: 18px;"
                                       "margin-top: 30px;"
                                       "margin-bottom: 30px;"
                                       "padding: 5px 5px;"
                                       "max-width: 100px;"
                                       "}"
                                       "#createNewGameButton:hover{"
                                       "background-color: #B0F6E1;"
                                       "}");
    createNewGameButton->setText("New game");
    QVBoxLayout *buttonLayout = new QVBoxLayout;
    questionLabel->setFocus();
    for (int i = 0; i < 4; ++i) {
        optionButtons[i] = new QPushButton(this);
        optionButtons[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        optionButtons[i]->setFixedWidth(800);
        optionButtons[i]->setObjectName("optionButton");
        QString order;
        if(i == 0)
            order='A';
        else if(i == 1)
            order='B';
        else if(i == 2)
            order='C';
        else
            order='D';
        optionButtons[i]->setText(order +". " + ramdomWords[i]);
        optionButtons[i]->setStyleSheet(
            "#optionButton {"
            "    padding: 6px 0;"
            "    font-size: 18px;"
            "    margin: 10px 80px;"
            "    background-color: white;"
            "    border-radius: 12px;"
            "    padding-left: 120px;"
            "    padding-right: 100px;"
            "    text-align: left;"
            "} "
            "#optionButton:focus {"
            "    background-color: #B0F6E1;"
            "} "
            "#optionButton:hover {"
            "    background-color: #B0F6E1;"
            "}"
            );
        buttonLayout->addWidget(optionButtons[i]);
        connect(optionButtons[i], &QPushButton::clicked, this, &gamePlayDialog::handleOptionButtonClicked);
    }
    connect(createNewGameButton,&QPushButton::clicked, this,[=](){
        if(mainWindow->currentGameMode==GameMode::GuessWord){
            mainWindow->gameWords=guessWord(system_Mode);
            newGame();
        }
        else{
            mainWindow->gameWords=getDefinition(system_Mode);
            newGame();
        }
    });
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(resultLabel);
    setLayout(mainLayout);
}
void gamePlayDialog::newGame(){
    setCorrectKey(mainWindow->gameWords[1]);
    QVector<QString> ramdomWords(mainWindow->gameWords.begin()+1,mainWindow->gameWords.end());
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(ramdomWords.begin(), ramdomWords.end(), rng);
    questionWord->setText(mainWindow->gameWords[0]);
    for(int i=0;i<4;++i){
        QString order;
        if(i == 0)
            order='A';
        else if(i == 1)
            order='B';
        else if(i == 2)
            order='C';
        else
            order='D';
        optionButtons[i]->setText(order +". " + ramdomWords[i]);
    }
    resultLabel->setText("");
}

void gamePlayDialog::checkAnswer(const QString& selectedOptionText)
{
    if (selectedOptionText == correctKey) {
        resultLabel->setText("Your answer is correct!");
        resultLabel->setStyleSheet("color: #42AD48;");
    } else {
        resultLabel->setText("Your answer is not correct.");
        resultLabel->setStyleSheet("color: #E83736;");
    }
}

void gamePlayDialog::handleOptionButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString selectedOptionText = clickedButton->text();
        selectedOptionText=selectedOptionText.mid(3,selectedOptionText.length()-3);
        checkAnswer(selectedOptionText);
    }
}

QString gamePlayDialog::get(){
    return correctKey;
}

void gamePlayDialog::setCorrectKey(QString key){
    correctKey=key;
}
