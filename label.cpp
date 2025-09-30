#include "label.h"



Label::Label(QWidget *parent)
    : QLabel(parent)
{
    setText("Hello from MyLabel!");
    setAlignment(Qt::AlignCenter);
    setStyleSheet("font-size: 18px; color: blue;");
}

void Label::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Label clicked at:" << event->pos();
    QLabel::mousePressEvent(event); // keep default behavior
}
