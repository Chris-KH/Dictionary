#include "emoij.h"
#include "ui_emoij.h"
#include "mainwindow.h"

emoij::emoij(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::emoij)
    , mainWindow(parent)
{
    ui->setupUi(this);
}

emoij::~emoij()
{
    delete ui;
}

void emoij::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}

