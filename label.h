#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QMouseEvent>

class Label : public QLabel
{
    Q_OBJECT

public:
    explicit Label(QWidget *parent = nullptr);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
#endif // LABEL_H
