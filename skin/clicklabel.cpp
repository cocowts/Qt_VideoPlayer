#include "clicklabel.h"
#include <QMouseEvent>

ClickLabel::ClickLabel(QWidget *parent) : QLabel(parent)
{

}

void ClickLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        emit clicked();

    QWidget::mousePressEvent(e);
}
