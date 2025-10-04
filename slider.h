#ifndef SLIDER_H
#define SLIDER_H

#include "QSlider"

class slider : public QSlider
{
    Q_OBJECT

public:
    explicit slider(QWidget *parent = nullptr);

signals:
    void valueChangedByUser(int value);

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // SLIDER_H
