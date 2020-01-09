#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

int randomfunc(int j)
{
    return rand() % j;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    std::srand(std::time(0));
    //The following statements distribute letters to buttons randomly.
    random_shuffle(&alphabet[0], &alphabet[25]);
    for(int i = 0; i < 12; i++){
        rndletters[2 * i] = alphabet[i];
        rndletters[2 * i + 1] = alphabet[i];
    }
    random_shuffle(&rndletters[0], &rndletters[23]);
    //The following stores all buttons in an array.
    allButtons[0] = ui->Button01; allButtons[1] = ui->Button02; allButtons[2] = ui->Button03; allButtons[3] = ui->Button04;
    allButtons[4] = ui->Button05; allButtons[5] = ui->Button06; allButtons[6] = ui->Button07; allButtons[7] = ui->Button08;
    allButtons[8] = ui->Button09; allButtons[9] = ui->Button10; allButtons[10] = ui->Button11; allButtons[11] = ui->Button12;
    allButtons[12] = ui->Button13; allButtons[13] = ui->Button14; allButtons[14] = ui->Button15; allButtons[15] = ui->Button16;
    allButtons[16] = ui->Button17; allButtons[17] = ui->Button18; allButtons[18] = ui->Button19; allButtons[19] = ui->Button20;
    allButtons[20] = ui->Button21; allButtons[21] = ui->Button22; allButtons[22] = ui->Button23; allButtons[23] = ui->Button24;
    //The following sets colors of buttons.
    for(int i = 0; i < 24; ++i){
        allButtons[i]->setStyleSheet(":enabled {background-color: rgb(227, 227, 227) } :disabled {color: black; background-color: rgb(227, 227, 227) }");
    }
    ui->pairs->setStyleSheet(":disabled {color: black; background-color: rgb(227, 227, 255) }");
    ui->tries->setStyleSheet(":disabled {color: black; background-color: rgb(227, 227, 255) }");
    ui->reset->setStyleSheet(":enabled {color: black; background-color: rgb(227, 255, 227) }");
    ui->number_of_pairs->setStyleSheet(":disabled {color: black; background-color: rgb(227, 227, 255) }");
    ui->number_of_tries->setStyleSheet(":disabled {color: black; background-color: rgb(227, 227, 255) }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

//This function prevents the user from pressing new button while 2 cards have already opened.
void MainWindow::disable_button(){
    for(int i = 0; i < 24; ++i){
        allButtons[i]->setEnabled(false);
    }
    QTest::qWait(1000);
    for(int i = 0; i < 24; ++i){
        if(allButtons[i]->text() == "X"){
            allButtons[i]->setEnabled(true);
        }
    }
}

//This function is called when a button is pressed, and all actions corresponding to pressing a button is done here.
void MainWindow::button_clicked(QPushButton* button, int a){
    button->setEnabled((false));
    button->setText(QString::fromStdString(rndletters[a]));
    //The following controls whether the button is first or second opened card.
    if(previousButton == nullptr){
        previousButton = button;
    //The following controls whether the letter on the previous button is the same as the current one.
    } else if(previousButton->text() == QString::fromStdString(rndletters[a])){
        disable_button();
        previousButton->setText("");
        button->setText("");
        previousButton = nullptr;
        pairs++;
        tries++;
        ui->number_of_pairs->setText(QString::number(pairs));
        ui->number_of_tries->setText((QString::number(tries)));
        //The following controls whether the game ends.
        if(pairs == 12){
            ui->Button08->setText("YOU"); ui->Button09->setText("FIND"); ui->Button10->setText("ALL"); ui->Button11->setText("THE");
            ui->Button14->setText("PAIRS"); ui->Button15->setText("AFTER"); ui->Button16->setText(QString::number(tries)); ui->Button17->setText("TRIES");
            for(int i = 0; i < 7; ++i){
                allButtons[i]->setStyleSheet(":disabled {background-color: red}");
            }
            for(int i = 11; i < 13; ++i){
                allButtons[i]->setStyleSheet(":disabled {background-color: red}");
            }
            for(int i = 17; i < 24; ++i){
                allButtons[i]->setStyleSheet(":disabled {background-color: red}");
            }
        }
    } else {
        disable_button();
        button->setText("X");
        previousButton->setText("X");
        button->setEnabled(true);
        previousButton->setEnabled(true);
        previousButton = nullptr;
        tries++;
        ui->number_of_tries->setText((QString::number(tries)));
    }
}

//Each of the following functions is for corresponding button on the window.
void MainWindow::on_Button01_clicked()
{
    button_clicked(ui->Button01, 0);
}

void MainWindow::on_Button02_clicked()
{
    button_clicked(ui->Button02, 1);
}

void MainWindow::on_Button03_clicked()
{
    button_clicked(ui->Button03, 2);
}

void MainWindow::on_Button04_clicked()
{
    button_clicked(ui->Button04, 3);
}

void MainWindow::on_Button05_clicked()
{
    button_clicked(ui->Button05, 4);
}

void MainWindow::on_Button06_clicked()
{
    button_clicked(ui->Button06, 5);
}

void MainWindow::on_Button07_clicked()
{
    button_clicked(ui->Button07, 6);
}

void MainWindow::on_Button08_clicked()
{
    button_clicked(ui->Button08, 7);
}

void MainWindow::on_Button09_clicked()
{
    button_clicked(ui->Button09, 8);
}

void MainWindow::on_Button10_clicked()
{
    button_clicked(ui->Button10, 9);
}

void MainWindow::on_Button11_clicked()
{
    button_clicked(ui->Button11, 10);
}

void MainWindow::on_Button12_clicked()
{
    button_clicked(ui->Button12, 11);
}

void MainWindow::on_Button13_clicked()
{
    button_clicked(ui->Button13, 12);
}

void MainWindow::on_Button14_clicked()
{
    button_clicked(ui->Button14, 13);
}

void MainWindow::on_Button15_clicked()
{
    button_clicked(ui->Button15, 14);
}

void MainWindow::on_Button16_clicked()
{
    button_clicked(ui->Button16, 15);
}

void MainWindow::on_Button17_clicked()
{
    button_clicked(ui->Button17, 16);
}

void MainWindow::on_Button18_clicked()
{
    button_clicked(ui->Button18, 17);
}

void MainWindow::on_Button19_clicked()
{
    button_clicked(ui->Button19, 18);
}

void MainWindow::on_Button20_clicked()
{
    button_clicked(ui->Button20, 19);
}

void MainWindow::on_Button21_clicked()
{
    button_clicked(ui->Button21, 20);
}

void MainWindow::on_Button22_clicked()
{
    button_clicked(ui->Button22, 21);
}

void MainWindow::on_Button23_clicked()
{
    button_clicked(ui->Button23, 22);
}

void MainWindow::on_Button24_clicked()
{
    button_clicked(ui->Button24, 23);
}

//This function resets the game when reset button is pressed.
void MainWindow::on_reset_clicked()
{
    tries = 0;
    pairs = 0;
    ui->number_of_pairs->setText(QString::number(pairs));
    ui->number_of_tries->setText((QString::number(tries)));
    for(int i = 0; i < 24; ++i){
        allButtons[i]->setText("X");
    }
    for(int i = 0; i < 24; ++i){
        allButtons[i]->setEnabled(true);
    }
    random_shuffle(&rndletters[0], &rndletters[23]);
}
