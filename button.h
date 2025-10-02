#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QColor>


class Button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)

public:
    //explicit Button(QWidget *parent = nullptr);
    explicit Button(const QString &text, QWidget *parent = nullptr);

    QColor accentColor() const { return m_accentColor; }
    void setAccentColor(const QColor &c);

signals:
    // Additional signal that forwards clicked() but carries the button text.
    void clickedWithText(const QString &text);

    void accentColorChanged(const QColor &newColor);

protected:
    // Optional: override paintEvent for a custom look (we use base QPushButton styling here
    // but show how to override if you want to customize drawing).
    void paintEvent(QPaintEvent *event) override;

private:
    QColor m_accentColor;

};

#endif // BUTTON_H
