#include "button.h"

#include <QPainter>
#include <QPaintEvent>


Button::Button(QWidget *parent)
    : QPushButton(parent),
    m_accentColor(Qt::blue)
{
    // forward standard clicked() to clickedWithText(text)
    connect(this, &QPushButton::clicked, this, [this]() {
        emit clickedWithText(this->text());
    });

    // use a small default stylesheet that uses the accent color (keeps it simple)
    setStyleSheet(QStringLiteral("MyButton { }")); // placeholder, real styling below
}

Button::Button(const QString &text, QWidget *parent)
    : QPushButton(text, parent),
    m_accentColor(Qt::blue)
{
    connect(this, &QPushButton::clicked, this, [this]() {
        emit clickedWithText(this->text());
    });
}

void Button::setAccentColor(const QColor &c)
{
    if (c == m_accentColor) return;
    m_accentColor = c;
    emit accentColorChanged(m_accentColor);

    // Update a simple stylesheet so the background uses accent color (supports hover/pressed)
    // We use rgba so we can set transparency if desired.
    QString style = QString(
                        "QPushButton {"
                        "  background-color: rgba(%1,%2,%3,%4);"
                        "  border: none;"
                        "  color: white;"
                        "  padding: 8px 14px;"
                        "  border-radius: 8px;"
                        "}"
                        "QPushButton:hover {"
                        "  filter: brightness(1.08);"
                        "}"
                        "QPushButton:pressed {"
                        "  transform: translateY(1px);"
                        "}"
                        ).arg(m_accentColor.red())
                        .arg(m_accentColor.green())
                        .arg(m_accentColor.blue())
                        .arg(m_accentColor.alpha());

    setStyleSheet(style);
    update();
}

void Button::paintEvent(QPaintEvent *event)
{
    // For now call base implementation (we set stylesheet for look).
    // If you want fully custom painting, replace this method with QPainter calls.
    QPushButton::paintEvent(event);
}
