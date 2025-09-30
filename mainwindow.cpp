#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QVBoxLayout"
#include "QLabel"
#include "QDialog"
#include "QFileDialog"
#include "QFileInfoList"
#include "QDir"
#include "button.h"
#include "label.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);
    ui->listView->setModel(model);


    //  **  IN FOLDER  section **
    // create frame
    QFrame *frameInFolder = new QFrame;
    frameInFolder->setFrameShape(QFrame::Box);      // Box, Panel, StyledPanel, HLine, VLine, etc.
    frameInFolder->setFrameShadow(QFrame::Raised);  // Plain, Raised, Sunken

    // create frame layout
    QVBoxLayout *frameInFolderLayout = new QVBoxLayout(frameInFolder);

    QLabel *lblTitle = new QLabel("Choose Folder of Images:");
    frameInFolderLayout->addWidget(lblTitle);

    Button *btn = new Button("Image Folder");
    btn->setAccentColor(QColor(46, 125, 50)); // a green
    btn->setMinimumHeight(36);
    btn->setCursor(Qt::PointingHandCursor);
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
    frameInFolderLayout->addWidget(lblTitleOut);

    Button *btnOut = new Button("Image Out Folder");
    btnOut->setAccentColor(QColor(46, 125, 50)); // a green
    btnOut->setMinimumHeight(36);
    btnOut->setCursor(Qt::PointingHandCursor);
    frameOutFolderLayout->addWidget(btnOut);

    connect(btnOut, &QPushButton::clicked, this, &MainWindow::openFolderDialogOut);

    lblFolderOut = new QLabel("No Folder Chosen");
    frameOutFolderLayout->addWidget(lblFolderOut);

    ui->vl1->addWidget(frameOutFolder);


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

        //fileListWidget->clear();  // Clear previous file list

        QDir dir(dirPath);
     //   QFileInfoList fileList = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        QStringList fileNames = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
        model->setStringList(fileNames);

        // for (const QFileInfo &fileInfo : fileList) {
        //     qDebug() << fileInfo.fileName();
        //     ui->listView
        //     //fileListWidget->addItem(fileInfo.fileName());
        // }

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
