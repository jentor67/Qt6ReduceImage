#include "slider.h"

slider::slider(
    int startPoint,
    int endPoint,
    int StartValue,
    QWidget *parent)
    : QSlider(Qt::Horizontal, parent) // Default horizontal slider
{
    setRange(startPoint, endPoint);
    setValue(StartValue);
}

void slider::mouseReleaseEvent(QMouseEvent *event)
{
    QSlider::mouseReleaseEvent(event);
    emit valueChangedByUser(value());
}
