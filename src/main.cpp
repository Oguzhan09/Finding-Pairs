#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile::link("cards.exe", "cards.exe.lnk");

    MainWindow w;
    w.show();
    return a.exec();
}
