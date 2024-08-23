#include "EditDefinitionDialog.h"

EditDefinitionDialog::EditDefinitionDialog(MainWindow *parent) :
    QDialog(parent), mainWindow(parent)
{
    setWindowTitle("Edit Definition");

    wordInput = new QLineEdit(this);
    wordInput->setObjectName("wordInputDialog");
    wordInput->setPlaceholderText("Enter the word");

    typeInput = new QLineEdit(this);
    typeInput->setObjectName("definitionInputDialog");
    typeInput->setPlaceholderText("Enter the type");

    spellingInput = new QLineEdit(this);
    spellingInput->setObjectName("definitionInputDialog");
    spellingInput->setPlaceholderText("Enter the spelling");

    definitionInput = new QTextEdit(this);
    definitionInput->setObjectName("definitionInputDialog");
    definitionInput->setPlaceholderText("Enter the definition");



    okButton = new QPushButton("OK", this);
    cancelButton = new QPushButton("Cancel", this);

    okButton->setObjectName("okButtonDialog");
    okButton->setStyleSheet("#okButtonDialog:hover { background-color: #B0F6E1 ; }");

    cancelButton->setObjectName("cancelButtonDialog");
    cancelButton->setStyleSheet("#cancelButtonDialog:hover { background-color: #B0F6E1 ; }");

    setStyleSheet("background-color: #BCE1ED; margin: 10px 10px 0px 10px;");
    definitionInput->setStyleSheet("background-color: white;" "width: 300px;" "height: 100px;");
    wordInput->setStyleSheet("background-color: white; margin-bottom: 10px;" "width: 300px;");
    typeInput->setStyleSheet("background-color: white; margin-bottom: 10px;" "width: 300px;");
    spellingInput->setStyleSheet("background-color: white; margin-bottom: 10px;" "width: 300px;");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addStretch();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addWidget(wordInput);
    mainLayout->addWidget(typeInput);
    mainLayout->addWidget(spellingInput);
    mainLayout->addWidget(definitionInput);
    mainLayout->addLayout(buttonLayout);

    if(mainWindow->currentMode==DictionaryMode::VietEng){
        wordInput->setPlaceholderText("Nhập từ");
        definitionInput->setPlaceholderText("Nhập định nghĩa");
        typeInput->setPlaceholderText("Nhập loại từ");
        spellingInput->setPlaceholderText("Nhập phát âm");
    }

    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}
EditDefinitionDialog::~EditDefinitionDialog(){

}

QString EditDefinitionDialog::getKey() {
    return wordInput->text();
}

QString EditDefinitionDialog::getType(){
    return typeInput->text();
}

QString EditDefinitionDialog::getDefinition() {
    return definitionInput->toPlainText();
}

QString EditDefinitionDialog::getSpelling(){
    return spellingInput->text();
}


void EditDefinitionDialog::setKey(QString &word) {
    wordInput->setText(word);
}

void EditDefinitionDialog::setDefinition(QString &definition) {
    definitionInput->setText(definition);
}

void EditDefinitionDialog::setType(QString &type){
    typeInput->setText(type);
}

void EditDefinitionDialog::setSpelling(QString spelling){
    spellingInput->setText(spelling);
}

