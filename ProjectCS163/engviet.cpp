#include "engviet.h"
#include "ui_engviet.h"
#include "mainwindow.h"  // Include mainwindow.h here
#include "EditDefinitionDialog.h"
#include "searchbydefinition.h"
#include "showlistofwords.h"
#include "gameplaydialog.h"
#include "gameplayoption.h"

EngViet::EngViet(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::EngViet)
    , mainWindow(parent)  // Initialize the mainWindow pointer
{
    ui->setupUi(this);
    setFixedSize(1200, 900);
    QSplitter *splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    splitter->setHandleWidth(0);

    QListWidget *wordListWidget = new QListWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout;
    QLineEdit *searchInput = new QLineEdit(this);

    searchInput->setObjectName("searchInput");
    searchInput->setFixedHeight(30);
    searchInput->setPlaceholderText("Enter word to search");

    QPushButton *searchButton = new QPushButton("Search", this);
    searchButton->setObjectName("searchButton");
    searchButton->setFixedSize(80,30);

    QWidget *searchWidget = new QWidget(this);
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);

    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchButton);
    leftLayout->addWidget(searchWidget);
    leftLayout->addWidget(wordListWidget);

    QWidget *leftWidget = new QWidget(this);
    leftWidget->setLayout(leftLayout);

    splitter->addWidget(leftWidget);

    QLabel *definitionLabel = new QLabel("Select a word to view its definition.\n", this);
    definitionLabel->setObjectName("rightWidget");

    splitter->addWidget(definitionLabel);
    splitter->setStretchFactor(0, 6);
    splitter->setStretchFactor(1, 6);

    QWidget *splitterPlaceholder = ui->splitterPlaceholder;
    QVBoxLayout *layout = new QVBoxLayout(splitterPlaceholder);
    splitterPlaceholder->setLayout(layout);
    splitterPlaceholder->layout()->addWidget(splitter);

    QHBoxLayout *listButtonLayout=new QHBoxLayout(ui->buttonWidget);
    QPushButton *historyButton = new QPushButton("History",this);
    QPushButton *favouristButton = new QPushButton("Favourite words",this);
    QPushButton *gameButton = new QPushButton("Play game",this);
    QPushButton *addNewWord = new QPushButton("Add word",this);
    QPushButton *searchByDefinition = new QPushButton("Search by definition",this);

    listButtonLayout->addWidget(searchByDefinition);
    listButtonLayout->addWidget(addNewWord);
    listButtonLayout->addWidget(historyButton);
    listButtonLayout->addWidget(favouristButton);
    listButtonLayout->addWidget(gameButton);

    ui->buttonWidget->setLayout(listButtonLayout);
    historyButton->setObjectName("historyButton");
    favouristButton->setObjectName("favouriteButton");
    gameButton->setObjectName("gameButton");
    addNewWord->setObjectName("addNewWordButton");
    searchByDefinition->setObjectName("searchByDefinitionButton");
    addNewWord->setFixedHeight(30);
    searchByDefinition->setFixedHeight(30);
    historyButton->setFixedHeight(30);
    favouristButton->setFixedHeight(30);
    gameButton->setFixedHeight(30);

    connect(searchButton, &QPushButton::clicked, this, [=]() {
        mainWindow->searchWord(wordListWidget, searchInput->text(), mainWindow->engVietWords, definitionLabel);
    });
    connect(addNewWord , &QPushButton::clicked, this, &EngViet::addNewWord);
    connect(historyButton, &QPushButton::clicked, this, &EngViet::on_historyButton_clicked);
    connect(favouristButton, &QPushButton::clicked, this, &EngViet::on_favouristButton_clicked);
    connect(gameButton, &QPushButton::clicked, this, &EngViet::on_gameButton_clicked);
    connect(searchByDefinition, &QPushButton::clicked, this, [=]() {
        mainWindow->searchByDefinition(wordListWidget, mainWindow->engVietWords, definitionLabel);
    });

}

EngViet::~EngViet()
{
    delete ui;
}

void EngViet::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}


void MainWindow::addWordToList(QListWidget *wordListWidget, const QString &word, const QString &definition, QLabel *definitionLabel) {

    // Create a widget to hold the word, view button, and delete button
    QWidget *wordWidget = new QWidget(wordListWidget);

    wordWidget->setObjectName("wordWidget");
    QHBoxLayout *layout = new QHBoxLayout(wordWidget);

    // Create the label for the word
    QLabel *wordLabel = new QLabel(word, wordWidget);
    wordLabel->setObjectName("word");
    layout->addWidget(wordLabel);

    // Create the view button
    QPushButton *viewButton = new QPushButton("View", wordWidget);
    viewButton->setObjectName("viewButton");
    layout->addWidget(viewButton);

    // Create the delete button
    QPushButton *deleteButton = new QPushButton("Delete", wordWidget);
    deleteButton->setObjectName("deleteButton");
    layout->addWidget(deleteButton);

    // Create the edit button
    QPushButton *editButton = new QPushButton("Edit", wordWidget);
    editButton->setObjectName("editButton");
    layout->addWidget(editButton);

    // Create the add word to favourist list button
    QPushButton *add = new QPushButton("Add", wordWidget);
    add->setObjectName("viewButton");
    layout->addWidget(add);

    layout->addStretch();  // Add stretch to push the buttons to the right

    // Add the widget to the QListWidget as a QListWidgetItem
    QListWidgetItem *item = new QListWidgetItem(wordListWidget);
    wordListWidget->addItem(item);
    item->setSizeHint(wordWidget->sizeHint());
    wordListWidget->setItemWidget(item, wordWidget);

    connect(viewButton, &QPushButton::clicked, this, [=]() {
        definitionLabel->setText(definition);
    });

    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        deleteWordFromList(wordListWidget, item);
        deleteWord(word);
    });

    connect(editButton, &QPushButton::clicked, this, [=]() {
        editWordDefinition(word, definitionLabel,definition);
    });

    connect(add, &QPushButton::clicked, this,[=](){
        addWordToFavouriteList(word,definition);
    });

}

void MainWindow::deleteWordFromList(QListWidget *wordListWidget, QListWidgetItem *item) {
    wordListWidget->takeItem(wordListWidget->row(item));
    delete item;
}

void MainWindow::searchWord(QListWidget *wordListWidget, const QString &searchTerm, const std::vector<word> &words, QLabel *definitionLabel) {
    wordListWidget->clear();
    for (const auto &word : words) {
        if (word.name.startsWith(searchTerm, Qt::CaseInsensitive)) {
            addWordToList(wordListWidget, word.name, word.definition, definitionLabel);
        }
    }
}

void MainWindow::searchDefinition(QListWidget *wordListWidget, const QString &searchTerm, const std::vector<word> &words, QLabel *definitionLabel){
    // Clear the current list
    wordListWidget->clear();
    // Search and add matching words to the list
    for (const auto &word : words) {
        if (word.definition.startsWith(searchTerm, Qt::CaseInsensitive)) {
            addWordToList(wordListWidget, word.name, word.definition, definitionLabel);
        }
    }
}

void MainWindow::deleteWord(const QString word){
    for (auto it = engVietWords.begin(); it != engVietWords.end(); ++it) {
        if (it->name == word) {
            engVietWords.erase(it);
            return;
        }
    }
}

void EngViet::addNewWord() {
    EditDefinitionDialog dialog(this);
    dialog.setWindowTitle("Add New Word");
    if (dialog.exec() == QDialog::Accepted) {
        QString word = dialog.getWord();
        QString definition = dialog.getDefinition();
        if (!word.isEmpty() && !definition.isEmpty()) {
            mainWindow->engVietWords.push_back({word, definition});
        }
    }
}

void  MainWindow::searchByDefinition(QListWidget *wordListWidget, const std::vector<word> &words, QLabel *definitionLabel){
    SearchByDefinition searchDefDialog(this);
    searchDefDialog.setWindowTitle("Search by definition");
    if(searchDefDialog.exec()== QDialog::Accepted){
        QString definition = searchDefDialog.getDefinition();
        if(!definition.isEmpty()){
            searchDefinition(wordListWidget,definition,words,definitionLabel);
        }
    }
}


void MainWindow::editWordDefinition(const QString &word, QLabel *definitionLabel,QString oldDefinition) {
    EditDefinitionDialog dialog(this);
    dialog.setWindowTitle("Edit Definition");
    dialog.setWord(word);
    dialog.setDefinition(oldDefinition);
    if (dialog.exec() == QDialog::Accepted) {
        QString newDefinition = dialog.getDefinition();
        if (!newDefinition.isEmpty()) {
            for (auto &w : engVietWords) {
                if (w.name == word) {
                    w.definition = newDefinition;
                    definitionLabel->setText(newDefinition);
                    break;
                }
            }
        }
    }
}

void MainWindow::addWordToFavouriteList(const QString wd,const QString definition){
    for(auto w:favouriteWords){
        if(w.name==wd)
            return;
    }
    word newWord;
    newWord.name= wd;
    newWord.definition= definition;
    favouriteWords.push_back(newWord);
}

void EngViet::on_historyButton_clicked()
{
    ShowListOfWords historyDialog(mainWindow->historyWords, this);
    historyDialog.exec();
}

void EngViet::on_favouristButton_clicked()
{
    ShowListOfWords favouristDialog(mainWindow->favouriteWords, this);
    favouristDialog.exec();
}


// In your EngViet or MainWindow class, open the gamePlayOption dialog


void EngViet::on_gameButton_clicked()
{
    // Ensure you're passing `mainWindow`, which is a `MainWindow*`
    gamePlayOption *optionDialog = new gamePlayOption(mainWindow);

    connect(optionDialog, &gamePlayOption::guessWordMode, this, [=]() {
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessWord);
        gameDialog->exec();
    });

    connect(optionDialog, &gamePlayOption::guessDefinitionMode, this, [=]() {
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessDefinition);
        gameDialog->exec();
    });

    optionDialog->exec();
}


