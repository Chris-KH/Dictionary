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

    setFixedSize(1300, 750);
    QStringList wordList;

    QSplitter *splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Horizontal);
    splitter->setHandleWidth(0);

    QListWidget *wordListWidget = new QListWidget(this);

    QWidget *leftWidget = new QWidget(this);
    QWidget *rightWidget = new QWidget(this);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    QVBoxLayout *rightLayout = new QVBoxLayout;

    QCompleter *completer = new QCompleter(wordList, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);

    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    completer->popup()->setItemDelegate(delegate);
    completer->popup()->setStyleSheet("font-size: 14pt;");

    QLineEdit *searchInput = new QLineEdit(this);
    searchInput->setCompleter(completer);
    searchInput->setObjectName("searchInput");
    searchInput->setFixedHeight(30);
    searchInput->setPlaceholderText("Enter word to search");

    QPushButton *searchButton = new QPushButton("Search", this);
    searchButton->setObjectName("searchButton");
    searchButton->setFixedSize(80, 30);

    QWidget *searchWidget = new QWidget(this);
    QHBoxLayout *searchLayout = new QHBoxLayout(searchWidget);

    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchButton);
    leftLayout->addWidget(searchWidget);
    leftLayout->addWidget(wordListWidget);

    leftWidget->setLayout(leftLayout);
    splitter->addWidget(leftWidget);

    QLabel *definitionLabel = new QLabel("<span style='font-size: 20pt;'>Select a word to view its definition.</span>\n", this);
    definitionLabel->setObjectName("rightWidget");
    definitionLabel->setWordWrap(true);
    definitionLabel->setStyleSheet("font-size: 15pt; padding: 20px;");
    definitionLabel->adjustSize();

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFixedHeight(660);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidget(definitionLabel);

    rightLayout->addWidget(scrollArea);
    leftLayout->addWidget(scrollArea);
    rightLayout->setContentsMargins(10, 0, 0, 140);
    rightLayout->setSpacing(0);
    leftLayout->setContentsMargins(0, 5, 0, 150);
    leftLayout->setSpacing(0);
    rightWidget->setLayout(rightLayout);

    splitter->addWidget(rightWidget);

    splitter->setStretchFactor(0, 4);
    splitter->setStretchFactor(1, 9);

    QWidget *splitterPlaceholder = ui->splitterPlaceholder;
    QVBoxLayout *layout = new QVBoxLayout(splitterPlaceholder);
    splitterPlaceholder->setLayout(layout);
    splitterPlaceholder->layout()->addWidget(splitter);

    QHBoxLayout *listButtonLayout=new QHBoxLayout(ui->buttonWidget);
    QPushButton *resetButton = new QPushButton("Reset",this);
    QPushButton *historyButton = new QPushButton("History",this);
    QPushButton *favouristButton = new QPushButton("Favourite words",this);
    QPushButton *gameButton = new QPushButton("Play game",this);
    QPushButton *addNewWord = new QPushButton("Add word",this);
    QPushButton *searchByDefinition = new QPushButton("Search by definition",this);
    QPushButton *randomAWordButton = new QPushButton("Random Word",this);
    ui->backButton->setText("Back");


    listButtonLayout->addWidget(resetButton);
    listButtonLayout->addWidget(searchByDefinition);
    listButtonLayout->addWidget(addNewWord);
    listButtonLayout->addWidget(randomAWordButton);
    listButtonLayout->addWidget(historyButton);
    listButtonLayout->addWidget(favouristButton);
    listButtonLayout->addWidget(gameButton);

    ui->buttonWidget->setLayout(listButtonLayout);
    resetButton->setObjectName("gameButton");
    historyButton->setObjectName("historyButton");
    favouristButton->setObjectName("favouriteButton");
    gameButton->setObjectName("gameButton");
    addNewWord->setObjectName("addNewWordButton");
    randomAWordButton->setObjectName("gameButton");
    searchByDefinition->setObjectName("searchByDefinitionButton");


    if(mainWindow->currentMode==DictionaryMode::VietEng){
        resetButton->setText("Cài đặt lại");
        searchInput->setPlaceholderText("Nhập vào từ");
        searchButton->setText("Tìm kiếm");
        definitionLabel->setText("<span style='font-size: 20pt;'>Chọn một từ để xem định nghĩa.</span>\n");
        historyButton->setText("Lịch sử");
        favouristButton->setText("Yêu thích");
        gameButton->setText("Trò chơi");
        addNewWord->setText("Thêm từ");
        randomAWordButton->setText("Từ ngẫu nhiên");
        searchByDefinition->setText("Tìm định nghĩa");
        ui->backButton->setText("Trở lại");
    }

    resetButton->setFixedHeight(30);
    addNewWord->setFixedHeight(30);
    searchByDefinition->setFixedHeight(30);
    historyButton->setFixedHeight(30);
    favouristButton->setFixedHeight(30);
    gameButton->setFixedHeight(30);
    randomAWordButton->setFixedHeight(30);

    connect(resetButton,&QPushButton::clicked,this,[=](){
        resetToOrigin(trieLists[system_Mode]);

        if(mainWindow->currentMode==DictionaryMode::VietEng)
            definitionLabel->setText("<span style='font-size: 20pt;'>Chọn một từ để xem định nghĩa.</span>\n");
        else definitionLabel->setText("<span style='font-size: 20pt;'>Select a word to view its definition.</span>\n");
        searchInput->clear();
        wordListWidget->clear();

        QWidget *notificationWidget = new QWidget(this);
        notificationWidget->setAttribute(Qt::WA_TranslucentBackground);

        QLabel *notificationLabel;
         if(mainWindow->currentMode==DictionaryMode::VietEng)
            notificationLabel = new QLabel("Cài đặt lại thành công", notificationWidget);
        else notificationLabel = new QLabel("Reset successfully", notificationWidget);

        notificationLabel->setAlignment(Qt::AlignCenter);
        notificationLabel->setStyleSheet(
            "QLabel {"
            "    font-size: 40px;"
            "    color: #000000;"
            "    padding: 20px;"
            "    background-color: #BCE1ED;"
            "    border: none;"
            "    border-radius: 20px;"
            "    font-weight: 400; }"
            );


        QVBoxLayout *layout = new QVBoxLayout(notificationWidget);
        layout->addWidget(notificationLabel);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setAlignment(Qt::AlignCenter);
        notificationWidget->setLayout(layout);

        QSize sizeHint = notificationLabel->sizeHint() + QSize(300, 100);
        notificationWidget->resize(sizeHint);
        notificationWidget->setFixedSize(sizeHint);

        QScreen *screen = QApplication::primaryScreen();
        QRect screenGeometry = screen->availableGeometry();
        notificationWidget->move((screenGeometry.width() - notificationWidget->width()) / 2 - 200,
                                 (screenGeometry.height() - notificationWidget->height()) / 2);
        notificationWidget->show();
        QTimer::singleShot(1000, notificationWidget, &QWidget::close);
        connect(notificationWidget, &QWidget::destroyed, [notificationWidget]() {
            delete notificationWidget;
        });
    });

    connect(addNewWord, &QPushButton::clicked, this,[=](){
        mainWindow->addNewWord();
    });
    connect(historyButton, &QPushButton::clicked, this, &EngViet::on_historyButton_clicked);
    connect(favouristButton, &QPushButton::clicked, this, &EngViet::on_favoriteButton_clicked);
    connect(gameButton, &QPushButton::clicked, this, &EngViet::on_gameButton_clicked);
    connect(searchByDefinition, &QPushButton::clicked, this, [=]() {
        mainWindow->searchByDefinition(wordListWidget,definitionLabel);
    });
    connect(searchButton, &QPushButton::clicked, this, [=]() {
        auto start = std::chrono::high_resolution_clock::now();  // Start timing

        Word word;
        QVector<Word> currentList;
       if (trieLists[system_Mode].search(word, searchInput->text(), currentList)==true){
           definitionLabel->setText("");
            mainWindow->addWordToList(wordListWidget, word, definitionLabel, 1);
       }
       else{
           if (mainWindow->currentMode == DictionaryMode::VietEng) {
               definitionLabel->setText("<b>Từ này không tồn tại!</b>");
               definitionLabel->setStyleSheet("font-size: 20pt; padding: 10px;");
           } else {
               definitionLabel->setText("<b>This word doesn't exist!</b>");
               definitionLabel->setStyleSheet("font-size: 20pt; padding: 10px;");
           }
       }
       if(!word.key.isEmpty()){
        historyLists[system_Mode].insert(word.key);
       }
       auto end = std::chrono::high_resolution_clock::now();  // End timing
       auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
       qDebug() << "Searching Time: "<< duration.count() << "ms";  // Output the duration

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

    connect(randomAWordButton, &QPushButton::clicked, this, [=](){
        Word word=getRandomWord(system_Mode);
        definitionLabel->setText("");
        mainWindow->addWordToList(wordListWidget, word, definitionLabel, 1);

        QString text;
        text += "<p><span style='font-size: 33px; font-weight: bold;'>" + word.key + "</span></p>";

        if (!word.type.isEmpty()) {
            text += "<p style='font-size: 22px;'>&emsp;";  // Thụt đầu dòng và cố định kích thước font
            if (system_Mode == 1) {
                text += "<b>Loại từ</b>: " + word.type + "</p>";
            } else {
                text += "<b>Type</b>: " + word.type + "</p>";
            }
        }

        if (!word.spelling.isEmpty()) {
            text += "<p style='font-size: 22px;'>&emsp;";
            if (system_Mode == 1) {
                text += "<b>Cách đọc</b>: " + word.spelling + "</p>";
            } else {
                text += "<b>Spelling</b>: " + word.spelling + "</p>";
            }
        }

        text += "<p style='font-size: 22px;'><b>Definitions</b>:</p>";
        int i = 0;
        for (const auto &s : word.definitions) {
            i++;
            QString idx = QString::number(i);
            text += "<p style='font-size: 22px;'>&emsp;" + idx + ". " + s + "</p>";
        }

        definitionLabel->setText(text);
    });
}

EngViet::~EngViet()
{
    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
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

void MainWindow::addWordToList(QListWidget *wordListWidget, Word &word,QLabel *definitionLabel, bool check)
{
    if (check)
    wordListWidget->clear();
    definitionLabel->setWordWrap(true);
    definitionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

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

    QPushButton *add = new QPushButton("Add to favorite list", wordWidget);
    add->setObjectName("viewButton");
    layout->addWidget(add);

    if(currentMode==DictionaryMode::VietEng){
        viewButton->setText("Xem");
        deleteButton->setText("Xóa");
        editButton->setText("Sửa");
        add->setText("Thêm vào danh sách yêu thích");
    }
    layout->addStretch();

    QListWidgetItem *item = new QListWidgetItem(wordListWidget);
    wordListWidget->addItem(item);
    item->setSizeHint(wordWidget->sizeHint());
    wordListWidget->setItemWidget(item, wordWidget);

    connect(viewButton, &QPushButton::clicked, this, [=]() {
        QString text;
        text += "<p><span style='font-size: 33px; font-weight: bold;'>" + word.key + "</span></p>";

        if(!word.key.isEmpty()){
            historyLists[system_Mode].insert(word.key);
        }
        if (!word.type.isEmpty()) {
            text += "<p style='font-size: 22px;'>&emsp;";  // Thụt đầu dòng và cố định kích thước font
            if (system_Mode == 1) {
                text += "<b>Loại từ</b>: " + word.type + "</p>";
            } else {
                text += "<b>Type</b>: " + word.type + "</p>";
            }
        }

        if (!word.spelling.isEmpty()) {
            text += "<p style='font-size: 22px;'>&emsp;";
            if (system_Mode == 1) {
                text += "<b>Cách đọc</b>: " + word.spelling + "</p>";
            } else {
                text += "<b>Spelling</b>: " + word.spelling + "</p>";
            }
        }

        text += "<p style='font-size: 22px;'><b>Definitions</b>:</p>";
        int i = 0;
        for (const auto &s : word.definitions) {
            i++;
            QString idx = QString::number(i);
            text += "<p style='font-size: 22px;'>&emsp;" + idx + ". " + s + "</p>";
        }

        definitionLabel->setText(text);
    });



    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        QMessageBox::StandardButton reply;
        if (system_Mode == 1) {
            reply = QMessageBox::question(this, "Xác nhận xóa từ", "Bạn có chắc chắn muốn xóa từ này không?",
                                          QMessageBox::Yes | QMessageBox::No);
        } else {
            reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this word?",
                                          QMessageBox::Yes | QMessageBox::No);
        }

        if (reply == QMessageBox::Yes) {
            auto start = std::chrono::high_resolution_clock::now();  // Start timing

            deleteWordFromList(wordListWidget, item);
            trieLists[system_Mode].remove(word.key);
            if (system_Mode == 1) {
                definitionLabel->setText("<span style='font-size: 20pt;'>Chọn một từ để xem định nghĩa.</span>\n");
            } else {
                definitionLabel->setText("<span style='font-size: 20pt;'>Select a word to view its definition.</span>\n");
            }

            auto end = std::chrono::high_resolution_clock::now();  // End timing
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
            qDebug() << "Deleting time: " << duration.count() << "ms";  // Output the duration
        }
    });
    connect(editButton, &QPushButton::clicked, this, [=]() {
         Word editWord = word;
         editWordDefinition(editWord, definitionLabel);
    });

    connect(add, &QPushButton::clicked, this,[=](){
        favoriteLists[system_Mode].insert(word.key);
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
        sort(current.begin(), current.end(), [](QPair<double, Word> a, QPair<double, Word> b) {return a.first < b.first; });
        for(auto it:current){
            addWordToList(wordListWidget,it.second, definitionLabel, 0);
        }
    }

}

void MainWindow::addNewWord()
{
    auto start = std::chrono::high_resolution_clock::now();  // Start timing

    EditDefinitionDialog dialog(this, 1);
    if(currentMode == DictionaryMode::VietEng)
        dialog.setWindowTitle("Thêm từ mới");
    else
        dialog.setWindowTitle("Add new word");

    while (true) {
        if (dialog.exec() != QDialog::Accepted) {
            break;
        }

        Word newWord;
        QString newKey = dialog.getKey();
        QString newDefinition = dialog.getDefinition();
        QString newType = dialog.getType();
        QString newSpelling = dialog.getSpelling();
        QStringList newDefinitions=newDefinition.split("\n");

        if (!newKey.isEmpty() && !newDefinition.isEmpty()) {
            newWord.key = newKey;
            for (auto str : newDefinitions)
                if (str!="")
            {
                newWord.definitions.push_back(str);
            }
            newWord.type = newType;
            newWord.spelling = newSpelling;
            trieLists[system_Mode].insert(newWord);

            if(currentMode == DictionaryMode::VietEng)
                QMessageBox::information(this, "Thành công", "Từ mới đã được thêm thành công.");
            else
                QMessageBox::information(this, "Success", "The new word has been added successfully.");

            break; // Thoát khỏi vòng lặp sau khi thêm từ mới thành công
        } else {
            if(currentMode == DictionaryMode::VietEng)
                QMessageBox::warning(this, "Lỗi nhập dữ liệu", "Vui lòng nhập từ và định nghĩa");
            else
                QMessageBox::warning(this, "Input Error", "Please enter key and its definitions");
        }
    }
    auto end = std::chrono::high_resolution_clock::now();  // End timing
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
    qDebug() << "Adding New Word Time: " << duration.count() << "ms";  // Output the duration

}


void MainWindow::editWordDefinition(Word &word, QLabel *definitionLabel) {
    auto start = std::chrono::high_resolution_clock::now();  // Start timing

    EditDefinitionDialog dialog(this,0);
    if(currentMode == DictionaryMode::VietEng)
        dialog.setWindowTitle("Chỉnh sửa định nghĩa");
    else
        dialog.setWindowTitle("Edit Definition");
    dialog.setKey(word.key);


    while (true)
    {
        if (dialog.exec() != QDialog::Accepted) {
            break;
        }

        QString newDefinition = dialog.getDefinition();
        if (!newDefinition.isEmpty()){
            word.definitions.clear();
            QStringList newDefinitions=newDefinition.split("\n");
            for(QString def:newDefinitions){
                word.definitions.push_back(def);
            }
            QString text="";
            text+= word.key + ":\n";
            text+= "Type: " +  word.type+ "\n";
            text+="Spelling: "+ word.spelling + "\n";
            int i=0;
            for(auto s: word.definitions){
                i++;
                QString idx=QString::number(i);
                text+=idx + ". "+ s + "\n";
            }
            definitionLabel->setText(text);
            trieLists[system_Mode].updateDefinition(word);
            if(currentMode == DictionaryMode::VietEng)
                QMessageBox::information(this, "Thành công", "Chỉnh sửa định nghĩa thành công.");
            else
                QMessageBox::information(this, "Success", "Editing definitions is successful.");
            break;
        }
        else
        {
            if(currentMode == DictionaryMode::VietEng)
                QMessageBox::warning(this, "Lỗi nhập dữ liệu", "Vui lòng nhập định nghĩa mới");
            else
                QMessageBox::warning(this, "Input Error", "Please enter new definitions");
        }
    }
    auto end = std::chrono::high_resolution_clock::now();  // End timing
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);  // Calculate duration
    qDebug() << "Edit Definition Time: "<< duration.count() << "ms";  // Output the duration

}

void EngViet::on_historyButton_clicked()
{
    ShowListOfWords historyDialog(1 , this);
    historyDialog.exec();
}

void EngViet::on_favoriteButton_clicked()
{
    ShowListOfWords favoriteDialog(2, this);
    favoriteDialog.exec();
}

void EngViet::on_gameButton_clicked()
{

    gamePlayOption *optionDialog = new gamePlayOption(mainWindow);
    connect(optionDialog, &gamePlayOption::guessWordMode, this, [=]() {
        mainWindow->gameWords = guessWord(system_Mode);
        mainWindow->currentGameMode=GameMode::GuessWord;
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessWord);
        gameDialog->exec();
    });

    connect(optionDialog, &gamePlayOption::guessDefinitionMode, this, [=]() {
        mainWindow->gameWords = getDefinition(system_Mode);
        mainWindow->currentGameMode=GameMode::GuessDefinition;
        gamePlayDialog *gameDialog = new gamePlayDialog(mainWindow, GameMode::GuessDefinition);
        gameDialog->exec();
    });
    optionDialog->exec();
}


void EngViet::closeEvent(QCloseEvent *event){
    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
     event->accept();
}

