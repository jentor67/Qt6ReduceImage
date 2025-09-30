#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.setWindowTitle("Image Reduce");

    //QVBoxLayout *layout = new QVBoxLayout(&w);
    //QVBoxLayout *layout = new QVBoxLayout(ui);
    // QLabel *lbl = new QLabel("Click the custom button:");
    // layout->addWidget(lbl);

    // Button *btn = new Button("Click me");
    // btn->setAccentColor(QColor(46, 125, 50)); // a green
    // btn->setMinimumHeight(36);
    // btn->setCursor(Qt::PointingHandCursor);
    // layout->addWidget(btn);

    // QLabel *out = new QLabel("No clicks yet.");
    // layout->addWidget(out);

    // QObject::connect(btn, &Button::clickedWithText, [&out](const QString &t){
    //     out->setText(QString("Button clicked: %1").arg(t));
    // });

    w.resize(1100,650);
    w.show();

    return a.exec();
}
