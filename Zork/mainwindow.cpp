#include <iostream>
#include <QTextEdit>
#include <QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Room.h"
#include "ZorkUL.h"
#include "CommandWords.h"
#include "qobject.h"
#define num 0 //Advanced pre-processor directives

using namespace std;

int NorthSignal;
int EastSignal ;
int SouthSignal;
int WestSignal;
int MapCounter = num;
int RoomCounter = 1;
int Rooms [12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; //array

string north = "go north";


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent)
    , ui(new Ui::MainWindow)  //multiple inheritance
{

    ui->setupUi(this);

    redirect = new QDebugStream(std::cout, ui->OutputBox);


}

MainWindow::~MainWindow() //destructors
{
    delete redirect;

}

void MainWindow::on_pushButton_clicked()
{
    if(RoomCounter == 3){
         RoomCounter = 1;
         ui->pushButton->setVisible(false);
         ui->pushButton_2->setVisible(false);
         ui->pushButton_3->setVisible(false);
         ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 6){
        RoomCounter = 3;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 8){
        RoomCounter = 5;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 10){
        RoomCounter = 7;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 12){
        RoomCounter = 11;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }
}

void MainWindow::on_textEdit_textChanged()
{
    string textEditText = ui->textEdit->toPlainText().toStdString();
    cin >> textEditText;
}

void MainWindow::on_MapButton_clicked()
{

    if(MapCounter == 0){
        ui->Map->setVisible(false);
        MapCounter++;
    }else if(MapCounter == 1){
        ui->Map->setVisible(true);
        MapCounter--;
    }
}


void MainWindow::on_playButton_clicked()
{
    ui->playButton->setVisible(false);
    ui->CoverScreen->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->Map->setVisible(false);

}


void MainWindow::on_pushButton_2_clicked()
{
    if(RoomCounter == 2){
        RoomCounter = 3;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 3){
        RoomCounter = 4;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 5){
        RoomCounter = 6;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 6){
        RoomCounter = 7;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 7){
        RoomCounter = 11;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 8){
        RoomCounter = 9;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 9){
        RoomCounter = 10;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(RoomCounter == 3){
        RoomCounter = 2;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 4){
        RoomCounter = 3;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 6){
        RoomCounter = 5;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 7){
        RoomCounter = 6;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 11){
        RoomCounter = 7;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
    }else if(RoomCounter == 9){
        RoomCounter = 8;
        ui->pushButton->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
    }else if(RoomCounter == 10){
        RoomCounter = 9;
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(false);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
 if(RoomCounter == 1){
     RoomCounter = 3;
     ui->pushButton->setVisible(true);
     ui->pushButton_2->setVisible(true);
     ui->pushButton_3->setVisible(true);
     ui->pushButton_4->setVisible(true);
 }else if(RoomCounter == 3){
     RoomCounter = 6;
     ui->pushButton->setVisible(true);
     ui->pushButton_2->setVisible(true);
     ui->pushButton_3->setVisible(true);
     ui->pushButton_4->setVisible(false);
 }else if(RoomCounter == 5){
     RoomCounter = 8;
     ui->pushButton->setVisible(true);
     ui->pushButton_2->setVisible(true);
     ui->pushButton_3->setVisible(false);
     ui->pushButton_4->setVisible(false);
 }else if(RoomCounter == 7){
     RoomCounter = 10;
     ui->pushButton->setVisible(true);
     ui->pushButton_2->setVisible(false);
     ui->pushButton_3->setVisible(true);
     ui->pushButton_4->setVisible(false);
 }else if(RoomCounter == 11){
     RoomCounter = 12;
     ui->pushButton->setVisible(true);
     ui->pushButton_2->setVisible(false);
     ui->pushButton_3->setVisible(false);
     ui->pushButton_4->setVisible(false);
 }


}

