#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <iostream>// Handles input and output
#include <chrono> // For delay function
#include <thread>// Handles threads of program execution
#include <signal.h>// Signal handling
#include <JetsonGPIO.h>


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Object initializing";
    GPIO::setmode(GPIO::BOARD);
    GPIO::setup(led_pin, GPIO::OUT, GPIO::LOW);

}

MainWindow::~MainWindow()
{
    GPIO::cleanup();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  qDebug() << "Led is on";
  curr_value = GPIO::HIGH;
  GPIO::output(led_pin, curr_value);
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Led is off";
    curr_value = GPIO::LOW;
    GPIO::output(led_pin, curr_value);
}




