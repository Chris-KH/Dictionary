#include "vieteng.h"
#include "ui_vieteng.h"
#include "mainwindow.h"

VietEng::VietEng(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::VietEng)
    , mainWindow(parent)
{
    ui->setupUi(this);
}

VietEng::~VietEng()
{
    delete ui;
}

void VietEng::on_backButton_clicked()
{
    hide();
    mainWindow->show();
}

