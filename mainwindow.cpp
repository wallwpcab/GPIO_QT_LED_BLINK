#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <iostream>// Handles input and output
#include <chrono>// For delay function
#include <thread>// Handles threads of program execution
#include <signal.h>// Signal handling
#include <JetsonGPIO.h>
#include <QLinkedList>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>


  //QMap<QString, int> map;

  QMultiMap<QString, int> map;
  QList<QString> values;
  QLinkedList<QString> List;

  int led_pin = 7; // Pin Definitions
  bool done = false;// Flag to determine when user wants to end program







void write(QString filename){
    QFile file(filename);
    // Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly |  QFile::Text)){
        qDebug() << " Could not open file for writing";
        return;
    }

    // To write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out << "QFile Tutorial";
    file.flush();
    file.close();
}

void read(QString filename){
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString myText = in.readAll();
    qDebug() << myText;
    file.close();
}


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow){
    ui->setupUi(this);
    
    foreach (const QString &str, map.keys())
    qDebug() << str << ':' << map.value(str);

    foreach (const QString &str, map.uniqueKeys()) {
        foreach (int i, map.values(str))
            qDebug() << str << ':' << i;
    }
    foreach (const QString &str, values) {
        if (str.isEmpty())
            break;
        qDebug() << str;
    }



        List << "A" << "B" << "C";
        List.append("D");
        List.append("E");
        List.append("F");

        foreach(QString s, List) qDebug() << s;

        //return a.exec();


        QString filename = "C:/Qt/MyFile.txt";
          write(filename);
          read(filename);




     // signal(SIGINT, signalHandler);// When CTRL+C pressed, signalHandler will be called // to interrupt the programs execution
      GPIO::setmode(GPIO::BOARD); // Pin Definitions
      GPIO::setup(led_pin, GPIO::OUT, GPIO::HIGH);// LED pin gets set to high initially
      std::cout << "Press CTRL+C to stop the LED" << std::endl;

      int curr_value = GPIO::HIGH;


      while(!done) { // Blink LED every 0.5 seconds

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        curr_value = GPIO::HIGH;
        GPIO::output(led_pin, curr_value);
        std::cout << "LED is ON" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        curr_value = GPIO::LOW;
        GPIO::output(led_pin, curr_value);
        std::cout << "LED is OFF" << std::endl;
      }

      GPIO::cleanup();
    //  return 0;
}

MainWindow::~MainWindow(){
    delete ui;
}


















// Function called by Interrupt
void signalHandler (int s){
  done = true;
}

void MainWindow::on_pushButton_clicked(){
    qDebug() << "led is high";

}

void MainWindow::on_pushButton_2_clicked(){
    qDebug() << "led is low";
}


