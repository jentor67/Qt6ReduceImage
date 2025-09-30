#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QVBoxLayout"
#include "QLabel"
#include "button.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QLabel *lbl = new QLabel("Choose Folder of Images:");
    ui->vl1->addWidget(lbl);

    Button *btn = new Button("Click me");
    btn->setAccentColor(QColor(46, 125, 50)); // a green
    btn->setMinimumHeight(36);
    btn->setCursor(Qt::PointingHandCursor);
    ui->vl1->addWidget(btn);

}

MainWindow::~MainWindow()
{
    delete ui;
}
