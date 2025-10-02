#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QVBoxLayout"
#include "QLabel"
#include "QDialog"
#include "QFileDialog"
#include "QFileInfoList"
#include "QDir"
#include "button.h"
//#include "label.h"
#include "QCalendarWidget"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    ui->listView->setModel(model);

    // Create a QFont object
    QFont fontLBL;
    // Set the point size
    fontLBL.setPointSize(14);
    // Set the font weight to bold
    fontLBL.setWeight(QFont::Bold);

    //  **  IN FOLDER  section **
    // create frame
    QFrame *frameInFolder = new QFrame;
    frameInFolder->setFrameShape(QFrame::Box);      // Box, Panel, StyledPanel, HLine, VLine, etc.
    frameInFolder->setFrameShadow(QFrame::Raised);  // Plain, Raised, Sunken

    // create frame layout
    QVBoxLayout *frameInFolderLayout = new QVBoxLayout(frameInFolder);

    // create title
    QLabel *lblTitle = new QLabel("Choose Folder of Images:");
    lblTitle->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    lblTitle->setFont(fontLBL);
    frameInFolderLayout->addWidget(lblTitle);

    Button *btn = new Button("Image Folder");
    frameInFolderLayout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, &MainWindow::openFolderDialogIn);

    lblFolderIn = new QLabel("No Folder Chosen");
    frameInFolderLayout->addWidget(lblFolderIn);

    ui->vl1->addWidget(frameInFolder);


    //  **  Out FOLDER  section **
    // create frame
    QFrame *frameOutFolder = new QFrame;
    frameOutFolder->setFrameShape(QFrame::Box);      // Box, Panel, StyledPanel, HLine, VLine, etc.
    frameOutFolder->setFrameShadow(QFrame::Raised);  // Plain, Raised, Sunken

    // create frame layout
    QVBoxLayout *frameOutFolderLayout = new QVBoxLayout(frameOutFolder);

    QLabel *lblTitleOut = new QLabel("Choose Folder to Send Images:");
    lblTitleOut->setAlignment(Qt::AlignCenter | Qt::AlignCenter);
    lblTitleOut->setFont(fontLBL);
    frameOutFolderLayout->addWidget(lblTitleOut);

    Button *btnOut = new Button("Image Out Folder");
    frameOutFolderLayout->addWidget(btnOut);

    connect(btnOut, &QPushButton::clicked, this, &MainWindow::openFolderDialogOut);

    lblFolderOut = new QLabel("No Folder Chosen");
    frameOutFolderLayout->addWidget(lblFolderOut);

    ui->vl1->addWidget(frameOutFolder);


    // add calendar
    QCalendarWidget *cal = new QCalendarWidget(parent);
    //cal->setFixedWidth(250);
    //cal->setFixedHeight(200);
//    cal->resize(100,100);
    ui->vl3->addWidget(cal);
    //cal->show();


}


void MainWindow::openFolderDialogIn()
{
    QString dirPath = QFileDialog::getExistingDirectory(
        this,
        "Select Folder",
        QString(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dirPath.isEmpty()) {
        qDebug() << "Chosen folder:" << dirPath;
        lblFolderIn->setText(dirPath);


        QDir dir(dirPath);
         QStringList fileNames = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
        model->setStringList(fileNames);


    }
}


void MainWindow::openFolderDialogOut()
{
    QString dir = QFileDialog::getExistingDirectory(
        this,
        "Select Folder",
        QString(),
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        qDebug() << "Chosen folder:" << dir;
        lblFolderOut->setText(dir);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
