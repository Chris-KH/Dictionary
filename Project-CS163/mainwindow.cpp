#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Populate engVietWords with data


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_engVietButton_clicked()
{
    hide();
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_engEngButton_clicked()
{
    hide();
    engEng = new EngEng(this);
    engEng->show();
}

void MainWindow::on_vietEngButton_clicked()
{
    hide();
    vietEng = new VietEng(this);
    vietEng->show();
}



void MainWindow::on_emoijButton_clicked()
{
    hide();
    emoi = new emoij(this);
    emoi->show();
}


void MainWindow::on_slangButton_clicked()
{
    hide();
    slang = new Slang(this);
    slang->show();
}

