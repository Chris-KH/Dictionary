#include "slang.h"
#include "ui_slang.h"
#include "mainwindow.h"

Slang::Slang(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::Slang)
    , mainWindow(parent)
{
    ui->setupUi(this);
}

Slang::~Slang()
{
    delete ui;
}


void Slang::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}

