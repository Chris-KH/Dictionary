#include "searchbydefinition.h"
#include "ui_searchbydefinition.h"

SearchByDefinition::SearchByDefinition(QWidget *parent)
    : QDialog(parent)

{
    setWindowTitle("Edit Definition");
    setFixedSize(800, 600);



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

    mainLayout->addWidget(definitionInput);
    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}



QString SearchByDefinition::getDefinition() const {
    return definitionInput->toPlainText();
}


void SearchByDefinition::setDefinition(const QString &definition) {
    definitionInput->setText(definition);
}

