#include "engeng.h"
#include "ui_engeng.h"
#include "mainwindow.h"

EngEng::EngEng(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::EngEng)
    , mainWindow(parent)
{
    ui->setupUi(this);
}

EngEng::~EngEng()
{
    delete ui;
}

void EngEng::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}

