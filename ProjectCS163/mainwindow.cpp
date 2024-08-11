#include "mainwindow.h"
#include "EditDefinitionDialog.h"

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
    currentMode=DictionaryMode::EngViet;
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_engEngButton_clicked()
{
    hide();
    currentMode=DictionaryMode::EngEng;
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_vietEngButton_clicked()
{
    hide();
    currentMode=DictionaryMode::VietEng;
    engViet = new EngViet(this);
    engViet->show();
}



void MainWindow::on_emoijButton_clicked()
{
    hide();
    currentMode=DictionaryMode::Emoij;
    engViet = new EngViet(this);
    engViet->show();
}


void MainWindow::on_slangButton_clicked()
{
    hide();
    currentMode=DictionaryMode::Slang;
    engViet = new EngViet(this);
    engViet->show();
}



