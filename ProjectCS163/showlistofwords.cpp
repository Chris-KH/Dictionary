#include "showlistofwords.h"
#include <QHBoxLayout>
#include <QMessageBox>

ShowListOfWords::ShowListOfWords(int mode, QWidget *parent)
    : QDialog(parent), mode(mode)
{
    setupUI();
}

void ShowListOfWords::setupUI()
{
    setFixedSize(600, 450);
    setStyleSheet("background-color: #BCE1ED;");
    mainLayout = new QVBoxLayout(this);
    wordListWidget = new QListWidget(this);
    wordListWidget->setStyleSheet("background-color: white;");
    mainLayout->addWidget(wordListWidget);
    setLayout(mainLayout);

    if(mode==1){
        for(QString str:historyLists[system_Mode].getAllWords()){
            addWordToList(wordListWidget,str);
        }
    }
    else{
        for(QString str:favoriteLists[system_Mode].getAllWords()){
            addWordToList(wordListWidget,str);
        }
    }
}

void ShowListOfWords::addWordToList(QListWidget *wordListWidget, QString &key){
    QWidget *wordWidget = new QWidget(wordListWidget);
    wordWidget->setStyleSheet("font-size: 20px;");
  //                            "qproperty-alignment: 'AlignCenter';");
    QHBoxLayout *layout = new QHBoxLayout(wordWidget);


    QLabel *wordLabel = new QLabel(key, wordWidget);
    wordLabel->setObjectName("word");
    layout->addWidget(wordLabel);

    QPushButton *deleteButton = new QPushButton("Delete", wordWidget);
    layout->addWidget(deleteButton);
    deleteButton->setObjectName("delButton");
    deleteButton->setStyleSheet("#delButton:hover {"
                                "background-color: #B0F6E1;"
                                "}"
                                "#delButton{"
                                "border-radius: 8px;"
                                "background-color: white;"
                                "font-size: 16px;"
                                "height: 30px;"
                                "width: 40px;"
                                "}");

    QListWidgetItem *item = new QListWidgetItem(wordListWidget);
    wordListWidget->addItem(item);
    item->setSizeHint(wordWidget->sizeHint());
    wordListWidget->setItemWidget(item, wordWidget);

    connect(deleteButton, &QPushButton::clicked, this, [=]() {
        onDeleteButtonClicked(wordListWidget,key, item);
        if(mode==1){
            historyLists[system_Mode].erase(key);
        }
        else{
            favoriteLists[system_Mode].erase(key);
        }
    });
}

void ShowListOfWords::onDeleteButtonClicked(QListWidget *wordListWidget, QString key,QListWidgetItem *item)
{
    wordListWidget->takeItem(wordListWidget->row(item));
    delete item;
}
ShowListOfWords::~ShowListOfWords() {
}

