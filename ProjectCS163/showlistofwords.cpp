#include "showlistofwords.h"
#include <QHBoxLayout>
#include <QMessageBox>

ShowListOfWords::ShowListOfWords(List list, QWidget *parent)
    : QDialog(parent), list(list)
{
    setupUI();

}

void ShowListOfWords::setupUI()
{
    setFixedSize(600, 450);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
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
    searchWidget->setLayout(searchLayout);

    mainLayout->addWidget(searchWidget);
    mainLayout->addWidget(searchWidget);

    QListWidget *wordListWidget = new QListWidget(this);
    mainLayout->addWidget(wordListWidget);

    setLayout(mainLayout);
    connect(searchButton, &QPushButton::clicked, this, [=]() {
        searchWord(wordListWidget,searchInput->text());
    });
}

void ShowListOfWords::searchWord(QListWidget *wordListWidget, QString key){
    wordListWidget->clear();
    if(list.find(key)){
        QWidget *wordWidget = new QWidget();
        wordWidget->setObjectName("wordWidget");

        QHBoxLayout *layout = new QHBoxLayout(wordWidget);

        QLabel *wordLabel = new QLabel(key, wordWidget);
        wordLabel->setObjectName("word");
        wordLabel->setStyleSheet("padding-left: 20px;");

        QPushButton *deleteButton = new QPushButton("Delete", wordWidget);

        deleteButton->setObjectName("deleteButton");

        layout->addWidget(wordLabel);
        layout->addWidget(deleteButton);

        wordWidget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem(wordListWidget);
        item->setSizeHint(wordWidget->sizeHint());
        wordListWidget->addItem(item);
        wordListWidget->setItemWidget(item, wordWidget);

        connect(deleteButton, &QPushButton::clicked, this, [=]() {
            list.erase(key);
            onDeleteButtonClicked(wordListWidget, key, item);
        });
    }
}

void ShowListOfWords::onDeleteButtonClicked(QListWidget *wordListWidget, QString key,QListWidgetItem *item)
{
    wordListWidget->takeItem(wordListWidget->row(item));
    delete item;
}
ShowListOfWords::~ShowListOfWords() {
}

