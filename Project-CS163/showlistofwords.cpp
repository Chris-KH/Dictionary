#include "showlistofwords.h"
#include <QHBoxLayout>
#include <QMessageBox>

ShowListOfWords::ShowListOfWords(const std::vector<word> &words, QWidget *parent)
    : QDialog(parent), words(words)
{
    setupUI();
    populateList();
    connectSignals();
}

void ShowListOfWords::setupUI()
{
    setWindowTitle("List of Words");
    setFixedSize(1200, 900);
    // setStyleSheet("background-color: #BCE1ED");
    // Create a horizontal layout for the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    // Create a vertical layout for the left side (list widget)
    QVBoxLayout *leftLayout = new QVBoxLayout();
    wordListWidget = new QListWidget(this);
    leftLayout->addWidget(wordListWidget);

    QScrollBar *scrollBar = new QScrollBar(Qt::Vertical, this);
    scrollBar->setPageStep(10);  // Number of items to scroll by
    scrollBar->setSingleStep(1); // Number of items to scroll by on arrow click

    // Set up the scrolling for QListWidget
    connect(scrollBar, &QScrollBar::valueChanged, [this](int value) {
        wordListWidget->verticalScrollBar()->setValue(value);
    });

    // Connect the QListWidget's vertical scrollbar to the custom scrollbar
    connect(wordListWidget->verticalScrollBar(), &QScrollBar::valueChanged, scrollBar, &QScrollBar::setValue);

    // Create a vertical layout for the right side (definition label)
    QVBoxLayout *rightLayout = new QVBoxLayout();
    definitionLabel = new QLabel("Select a word to view its definition.", this);
    definitionLabel->setWordWrap(true); // Allow text to wrap in the label
    rightLayout->addWidget(definitionLabel);

    // Create widgets to hold the layouts
    QWidget *leftWidget = new QWidget(this);
    QWidget *rightWidget = new QWidget(this);

    // Set object name for leftWidget to apply QSS styling
    rightWidget->setStyleSheet("font-size: 24px;"
                               "padding-left: 100px;");

    // Set the layouts to the widgets
    leftWidget->setLayout(leftLayout);
    rightWidget->setLayout(rightLayout);

    // Add the widgets to the main layout
    mainLayout->addWidget(leftWidget);
    mainLayout->addWidget(rightWidget);

    // Set stretch factors to achieve the 3/7 ratio
    mainLayout->setStretchFactor(leftWidget, 3);
    mainLayout->setStretchFactor(rightWidget, 7);

    // Set the main layout for the dialog
    setLayout(mainLayout);
}



void ShowListOfWords::populateList()
{
    wordListWidget->clear();

    for (const auto &w : words) {
        QWidget *wordWidget = new QWidget();
        // wordWidget->setStyleSheet("background-color: white;");
        QHBoxLayout *layout = new QHBoxLayout(wordWidget);

        QLabel *wordLabel = new QLabel(w.name, wordWidget);
        wordLabel->setObjectName("word");
        layout->addWidget(wordLabel);

        QPushButton *viewButton = new QPushButton("View", wordWidget);
        viewButton->setObjectName("viewButton");
        layout->addWidget(viewButton);

        QPushButton *deleteButton = new QPushButton("Delete", wordWidget);
        deleteButton->setObjectName("deleteButton");
        layout->addWidget(deleteButton);

        layout->addStretch();
        wordWidget->setLayout(layout);

        QListWidgetItem *item = new QListWidgetItem(wordListWidget);
        wordListWidget->addItem(item);
        item->setSizeHint(wordWidget->sizeHint());
        wordListWidget->setItemWidget(item, wordWidget);

        connect(viewButton, &QPushButton::clicked, this, [=]() {
            onViewButtonClicked(w.name, w.definition);
        });

        connect(deleteButton, &QPushButton::clicked, this, [=]() {
            onDeleteButtonClicked(w.name,item);
        });
    }
}

void ShowListOfWords::connectSignals()
{
    // Any additional signal connections if needed
}

void ShowListOfWords::onViewButtonClicked(const QString &word, const QString &definition)
{
    definitionLabel->setText(definition);
}

void ShowListOfWords::onDeleteButtonClicked(const QString &word,QListWidgetItem *item)
{
    for(auto it = words.begin();it!=words.end();++it){
        if(it->name==word){
            words.erase(it);
            break;
        }
    }
    wordListWidget->takeItem(wordListWidget->row(item));
    delete item;
}

