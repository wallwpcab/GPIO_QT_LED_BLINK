#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <JetsonGPIO.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Pin Definitions
    int led_pin = 7;
    // Flag to determine when user wants to end program
    bool done = false;
    int curr_value = GPIO::HIGH;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
