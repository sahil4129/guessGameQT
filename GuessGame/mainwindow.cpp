#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->messageLabel->setText("");
    secretNumber = rand() % 100 + 1;
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_startOverPushButton_clicked(){
    ui->guessButton->setDisabled(false);
    ui->startOverPushButton->setDisabled(true);
    ui->spinBox->setValue(1);
    secretNumber = rand() % 100 + 1;
    ui->messageLabel->setText("");
}

void MainWindow::on_guessButton_clicked()
{
     guessnumber = ui->spinBox->value();
     //qDebug() << QString ::number(secretNumber);
     std::cout<<secretNumber<<std::endl;

     if(guessnumber == secretNumber){
         ui->messageLabel->setText("Congratulations !! You Won");
         ui->guessButton->setDisabled(true);
         ui->startOverPushButton->setDisabled(false);
     }else{
            if(guessnumber  >secretNumber){
                ui->messageLabel->setText("Try Number Lower than that");
            }
            if(guessnumber < secretNumber){
                ui->messageLabel->setText("Try Number Higher than that");
            }
        ui->startOverPushButton->setDisabled(true);
     }
}
