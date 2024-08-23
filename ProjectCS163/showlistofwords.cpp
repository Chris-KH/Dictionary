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
    setFixedSize(500, 700);

    mainLayout = new QVBoxLayout(this);
    wordListWidget = new QListWidget(this);
    wordListWidget->setStyleSheet("background-color: white;");
    mainLayout->addWidget(wordListWidget);
    setLayout(mainLayout);

    if(mode==1){
        if(historyLists[system_Mode].getAllWords().size()>0){
           setStyleSheet("background-color: #BCE1ED;");
           for(QString str:historyLists[system_Mode].getAllWords()){
            addWordToList(wordListWidget,str);
           }
        }
        else{
            setStyleSheet("background-color: white");
            delete wordListWidget;
            QLabel *text=new QLabel(this);
            text->setText("No words");
            text->setStyleSheet("font-size: 20px;"
                                "width: 100%;"
                                "height: 100%;");
            mainLayout->addWidget(text, 0, Qt::AlignCenter);

        }
    }
    else{
        if(favoriteLists[system_Mode].getAllWords().size()>0){
            setStyleSheet("background-color: #BCE1ED;");
            for(QString str:favoriteLists[system_Mode].getAllWords()){
                addWordToList(wordListWidget,str);
            }
        }
        else{
            setStyleSheet("background-color: white;");
            delete wordListWidget;
            QLabel *text=new QLabel(this);
            text->setText("No words");
            text->setStyleSheet("font-size: 20px;"
                                "width: 100%;"
                                "height: 100%;");
            mainLayout->addWidget(text, 0, Qt::AlignCenter);

        }
    }
}

void ShowListOfWords::addWordToList(QListWidget *wordListWidget, QString &key){
    QWidget *wordWidget = new QWidget(wordListWidget);
    wordWidget->setStyleSheet("font-size: 20px;");

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

