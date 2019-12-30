#ifndef CLICKSLIDER_H
#define CLICKSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QLabel>

class ClickSlider : public QSlider
{
public:
    ClickSlider(QWidget* parent = Q_NULLPTR);

protected:
    QLabel*	m_displayLabel;

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // CLICKSLIDER_H
