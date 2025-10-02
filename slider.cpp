#include "slider.h"

slider::slider(QWidget *parent)
    : QSlider(Qt::Horizontal, parent) // Default horizontal slider
{
    setRange(0, 100);
}

void slider::mouseReleaseEvent(QMouseEvent *event)
{
    QSlider::mouseReleaseEvent(event);
    emit valueChangedByUser(value());
}
