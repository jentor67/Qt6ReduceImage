#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "QListWidget"
#include "QStringListModel"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFolderDialogIn();
    void openFolderDialogOut();

    void on_sliderQuality_valueChanged(int value);

    void on_sliderResolution_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QLabel *lblFolderIn;
    QLabel *lblFolderOut;
    QListWidget *fileListWidget;
    QStringListModel *model;
    int qualitySet;
};
#endif // MAINWINDOW_H
