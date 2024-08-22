#include "searchbydefinition.h"
#include "ui_searchbydefinition.h"

SearchByDefinition::SearchByDefinition(QWidget *parent)
    : QDialog(parent)

{
    setWindowTitle("Edit Definition");
    setFixedSize(800, 600);
    setStyleSheet("background-color: #BCE1ED; margin: 10px 10px 0px 10px;");


    definitionInput = new QTextEdit(this);
    definitionInput->setObjectName("definitionInputDialog");
    definitionInput->setStyleSheet("background-color: white");
    definitionInput->setPlaceholderText("Enter definition");

    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);

    okButton->setObjectName("okButtonDialog");
    okButton->setStyleSheet("#okButtonDialog:hover { background-color: #B0F6E1 ; }");

    cancelButton->setObjectName("cancelButtonDialog");
    cancelButton->setStyleSheet("#cancelButtonDialog:hover { background-color: #B0F6E1 ; }");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addWidget(definitionInput);
    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}



QString SearchByDefinition::getDefinition()  {
    return definitionInput->toPlainText();
}


void SearchByDefinition::setDefinition( QString &definition) {
    definitionInput->setText(definition);
}

