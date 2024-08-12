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
    okButton->setStyleSheet("#okButtonDialog:hover { background-color: #B0F6E1 ; }");
    cancelButton->setObjectName("cancelButtonDialog");
    cancelButton->setStyleSheet("#cancelButtonDialog:hover { background-color: #B0F6E1 ; }");

    setStyleSheet("background-color: #BCE1ED; margin: 5px 10px 0px 10px;");
    definitionInput->setStyleSheet("background-color: white;");
    wordInput->setStyleSheet("background-color: white; margin-bottom: 10px;");
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
