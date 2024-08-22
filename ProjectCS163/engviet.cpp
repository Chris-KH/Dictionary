#include "engviet.h"
#include "ui_engviet.h"
#include "mainwindow.h"
#include "EditDefinitionDialog.h"
#include "searchbydefinition.h"
#include "showlistofwords.h"
#include "gameplaydialog.h"
#include "gameplayoption.h"

EngViet::EngViet(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::EngViet)
    , mainWindow(parent)
{
    ui->setupUi(this);

    setFixedSize(1300,900);
    QStringList wordList;

    QSplitter *splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    splitter->setHandleWidth(0);
    QListWidget *wordListWidget = new QListWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout;

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    QLineEdit *searchInput = new QLineEdit(this);
    searchInput->setCompleter(completer);
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
    definitionLabel->setStyleSheet("margin-top: 100px");


    // Create a scroll area to contain the definition label
  //  QScrollArea *scrollArea = new QScrollArea(this);

  //  scrollArea->setWidget(definitionLabel);
  //  scrollArea->setWidgetResizable(true); // Ensures the label resizes with the scroll area

    // Add the scroll area to the right side of the splitter
  //  splitter->addWidget(scrollArea);
    //splitter->addWidget(definitionLabel);
    splitter->addWidget(definitionLabel);
    splitter->setStretchFactor(0, 4);
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

    if(mainWindow->currentMode==DictionaryMode::VietEng){
        searchInput->setPlaceholderText("Nhập vào từ");
        searchButton->setText("Tìm kiếm");
        definitionLabel->setText("Chọn một từ để xem định nghĩa");
        historyButton->setText("Lịch sử");
        favouristButton->setText("Yêu thích");
        gameButton->setText("Trò chơi");
        addNewWord->setText("Thêm từ");
        searchByDefinition->setText("Tìm định nghĩa");
        ui->backButton->setText("Trở lại");
    }

    addNewWord->setFixedHeight(30);
    searchByDefinition->setFixedHeight(30);
    historyButton->setFixedHeight(30);
    favouristButton->setFixedHeight(30);
    gameButton->setFixedHeight(30);


    connect(addNewWord, &QPushButton::clicked, this,[=](){
        mainWindow->addNewWord();
    });
    historyLists[system_Mode].insert("man");
    connect(historyButton, &QPushButton::clicked, this, &EngViet::on_historyButton_clicked);
    connect(favouristButton, &QPushButton::clicked, this, &EngViet::on_favoriteButton_clicked);
     connect(gameButton, &QPushButton::clicked, this, &EngViet::on_gameButton_clicked);
    connect(searchByDefinition, &QPushButton::clicked, this, [=]() {
        mainWindow->searchByDefinition(wordListWidget,definitionLabel);
    });
    connect(searchButton, &QPushButton::clicked, this, [=]() {
        Word word;
        QVector<Word> currentList;
        qDebug()<<searchInput->text();
       if (trieLists[system_Mode].search(word, searchInput->text(), currentList)==true){
            historyLists[system_Mode].insert(word.key);
            qDebug()<<word.key;
            mainWindow->addWordToList(wordListWidget, word, definitionLabel);
       }
    });
    connect(searchInput, &QLineEdit::textChanged, this, [=]() {
        Word word;
        QVector<Word> currentList;
         if (trieLists[system_Mode].search(word, searchInput->text(), currentList) == false) {
            mainWindow->updateCompleterModel(completer, currentList);
        } else {
           currentList.clear();
           currentList.push_back(word);
           mainWindow->updateCompleterModel(completer, currentList);
       }
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

void MainWindow::updateCompleterModel(QCompleter *completer, QVector<Word> &currentList)
{
    if(!currentList.empty()){
        QStringList filteredWords;
        for (const Word &word : currentList) {
            filteredWords << word.key;
        }
        QAbstractItemModel *model = new QStringListModel(filteredWords, completer);
        completer->setModel(model);
    }
}

void MainWindow::addWordToList(QListWidget *wordListWidget, Word &word,QLabel *definitionLabel)
 {

    QWidget *wordWidget = new QWidget(wordListWidget);

    wordWidget->setObjectName("wordWidget");
    QHBoxLayout *layout = new QHBoxLayout(wordWidget);

    QLabel *wordLabel = new QLabel(word.key, wordWidget);
    wordLabel->setObjectName("word");
    layout->addWidget(wordLabel);

    QPushButton *viewButton = new QPushButton("View", wordWidget);
    viewButton->setObjectName("viewButton");
    layout->addWidget(viewButton);

    QPushButton *deleteButton = new QPushButton("Delete", wordWidget);
    deleteButton->setObjectName("deleteButton");
    layout->addWidget(deleteButton);

    QPushButton *editButton = new QPushButton("Edit", wordWidget);
    editButton->setObjectName("editButton");
    layout->addWidget(editButton);

    QPushButton *add = new QPushButton("Add", wordWidget);
    add->setObjectName("viewButton");
    layout->addWidget(add);

    if(currentMode==DictionaryMode::VietEng){
        viewButton->setText("Xem");
        deleteButton->setText("Xóa");
        editButton->setText("Sửa");
        add->setText("Thêm");
    }
    layout->addStretch();

    QListWidgetItem *item = new QListWidgetItem(wordListWidget);
    wordListWidget->addItem(item);
    item->setSizeHint(wordWidget->sizeHint());
    wordListWidget->setItemWidget(item, wordWidget);

    connect(viewButton, &QPushButton::clicked, this, [=]() {
        QString text="";
        text+= word.key + "\n";
        text+= "Type: " +  word.type+ "\n";
        text+="Spelling: "+ word.spelling + "\n";
        for(auto s: word.definitions){
            text+=s+"\n";
        }
        definitionLabel->setText(text);
    });

    connect(deleteButton, &QPushButton::clicked, this, [=]() {
       deleteWordFromList(wordListWidget, item);
        trieLists[system_Mode].remove(word.key);
    });

    connect(editButton, &QPushButton::clicked, this, [=]() {
         Word editWord = word;
         editWordDefinition(editWord, definitionLabel);
    });

    connect(add, &QPushButton::clicked, this,[=](){
         addWordToFavouriteList(word.key);
    });

}

void MainWindow::deleteWordFromList(QListWidget *wordListWidget, QListWidgetItem *item) {
    wordListWidget->takeItem(wordListWidget->row(item));
    delete item;
}

void MainWindow::searchByDefinition(QListWidget *wordListWidget,QLabel *definitionLabel){
    SearchByDefinition searchByDefinitionDialog(this);
    if(searchByDefinitionDialog.exec()==QDialog::Accepted){
        QString definition = searchByDefinitionDialog.getDefinition();
        if(definition.isEmpty())
            return;
        wordListWidget->clear();
        QVector<QPair<double,Word>> current;
        getWord(trieLists[system_Mode].getRoot(),definition,current);
        for(auto it:current){
            addWordToList(wordListWidget,it.second, definitionLabel);
        }
    }

}

void MainWindow::addNewWord()
 {
    EditDefinitionDialog dialog(this);
    if(currentMode==DictionaryMode::EngViet)
        dialog.setWindowTitle("Thêm từ mới");
    else
        dialog.setWindowTitle("Add new word");

     if (dialog.exec() == QDialog::Accepted) {
        Word newWord;
        QString newKey = dialog.getKey();
        QString newDefinition = dialog.getDefinition();
        QString newType=dialog.getType();
        QString newSpelling = dialog.getSpelling();
        QStringList newDefinitions = newDefinition.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);        // if(!newKey.isEmpty() && !newDefinition.isEmpty()){
        if(!newKey.isEmpty() && !newDefinition.isEmpty() && !newType.isEmpty() && !newSpelling.isEmpty()){
            newWord.key=newKey;
            for(auto str:newDefinitions){
                newWord.definitions.push_back(str);
            }
            newWord.type=newType;
            newWord.spelling=newSpelling;
            trieLists[system_Mode].insert(newWord);
        }
     }
}


void MainWindow::editWordDefinition(Word &word, QLabel *definitionLabel) {
    EditDefinitionDialog dialog(this);

    dialog.setWindowTitle("Edit Definition");
    dialog.setKey(word.key);
    dialog.setIndex("");
    QString definition = "";
    for(auto s:word.definitions){
        definition+=s+"\n";
    }
    dialog.setDefinition(definition);
    if (dialog.exec() == QDialog::Accepted) {
        QString newDefinition = dialog.getDefinition();
        if (!newDefinition.isEmpty()){
            QStringList newDefinitions=newDefinition.split("\n");
            for(QString def:newDefinitions){
                word.definitions.push_back(def);
            }
        }
        QString index= dialog.getIndex();
        bool ok;
        int idx=index.toInt(&ok);
        if(ok){
            word.definitions.erase(word.definitions.begin()+idx);
        }
    }
}

void MainWindow::addWordToFavouriteList(QString key){
    favoriteLists[system_Mode].insert(key);
}

void EngViet::on_historyButton_clicked()
{
    List list;
    ShowListOfWords historyDialog(list, this);
    historyDialog.exec();
}

void EngViet::on_favoriteButton_clicked()
{
    ShowListOfWords favoriteDialog(favoriteLists[system_Mode], this);
    favoriteDialog.exec();
}

void EngViet::on_gameButton_clicked()
{
    gamePlayOption *optionDialog = new gamePlayOption(mainWindow);
    connect(optionDialog, &gamePlayOption::guessWordMode, this, [=]() {
        mainWindow->gameWords = guessWord(system_Mode); //will crash if don't have data
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessWord);
        gameDialog->exec();
    });

    connect(optionDialog, &gamePlayOption::guessDefinitionMode, this, [=]() {
        mainWindow->gameWords = getDefinition(system_Mode);//will crash if don't have data
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessDefinition);
        gameDialog->exec();
    });
    optionDialog->exec();
}


