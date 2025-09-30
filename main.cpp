#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.setWindowTitle("Image Reduce");

    w.resize(1100,650);

    w.show();

    return a.exec();
}
