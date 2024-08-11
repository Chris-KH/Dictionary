#include "EditDefinitionDialog.h"

EditDefinitionDialog::EditDefinitionDialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("Edit Definition");
    setFixedSize(800, 600);

    wordInput = new QLineEdit(this);
    wordInput->setObjectName("wordInputDialog");
    wordInput->setPlaceholderText("Enter word");

    definitionInput = new QTextEdit(this);
    definitionInput->setObjectName("definitionInputDialog");
    definitionInput->setPlaceholderText("Enter definition");

    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);
    okButton->setObjectName("okButtonDialog");
    cancelButton->setObjectName("cancelButtonDialog");
    // setStyleSheet("background-color: #BCE1ED;");
    // definitionInput->setStyleSheet("background-color: white;");
    // wordInput->setStyleSheet("background-color: white;");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addWidget(wordInput);
    mainLayout->addWidget(definitionInput);
    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString EditDefinitionDialog::getWord() const {
    return wordInput->text();
}

QString EditDefinitionDialog::getDefinition() const {
    return definitionInput->toPlainText();
}

void EditDefinitionDialog::setWord(const QString &word) {
    wordInput->setText(word);
}

void EditDefinitionDialog::setDefinition(const QString &definition) {
    definitionInput->setText(definition);
}