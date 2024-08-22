#include "mainwindow.h"
#include "EditDefinitionDialog.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    saveAllTrie();
    saveAllList(0);
    saveAllList(1);
    freeMemory();
    delete ui;
}


void MainWindow::on_engVietButton_clicked()
{
    hide();
    index=0;
    system_Mode =0;
    currentMode=DictionaryMode::EngViet;
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_engEngButton_clicked()
{
    hide();
    index=2;
    system_Mode=2;
    currentMode=DictionaryMode::EngEng;
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_vietEngButton_clicked()
{
    hide();
    index=1;
    system_Mode=1;
    currentMode=DictionaryMode::VietEng;
    engViet = new EngViet(this);
    engViet->show();
}



void MainWindow::on_emoijButton_clicked()
{
    hide();
    index=4;
    system_Mode=4;
    currentMode=DictionaryMode::Emoij;
    engViet = new EngViet(this);
    engViet->show();
}

void MainWindow::on_slangButton_clicked()
{
    hide();
    index=3;
    system_Mode=3;
    currentMode=DictionaryMode::Slang;
    engViet = new EngViet(this);
    engViet->show();
}



