#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTest>
#include <QPushButton>
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::string alphabet[25] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
                                "P", "Q", "R", "S", "T", "U", "V", "W", "Y", "Z"};
    std::string rndletters[24];
    QPushButton *allButtons[24];
    QPushButton *previousButton = nullptr;
    int tries = 0;
    int pairs = 0;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void disable_button();

    void button_clicked(QPushButton* button, int a);

    void on_Button01_clicked();

    void on_Button02_clicked();

    void on_Button03_clicked();

    void on_Button04_clicked();

    void on_Button05_clicked();

    void on_Button06_clicked();

    void on_Button07_clicked();

    void on_Button08_clicked();

    void on_Button09_clicked();

    void on_Button10_clicked();

    void on_Button11_clicked();

    void on_Button12_clicked();

    void on_Button13_clicked();

    void on_Button14_clicked();

    void on_Button15_clicked();

    void on_Button16_clicked();

    void on_Button17_clicked();

    void on_Button18_clicked();

    void on_Button19_clicked();

    void on_Button20_clicked();

    void on_Button21_clicked();

    void on_Button22_clicked();

    void on_Button23_clicked();

    void on_Button24_clicked();

    void on_reset_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
