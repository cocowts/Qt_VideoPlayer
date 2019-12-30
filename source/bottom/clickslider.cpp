#include "clickslider.h"

#include <QApplication>

ClickSlider::ClickSlider(QWidget* parent) : QSlider(parent)
{
    m_displayLabel=new QLabel(this);

    m_displayLabel->setFixedSize(20, 20);
    m_displayLabel->setVisible(false);
    m_displayLabel->move(0,3);
    m_displayLabel->setAlignment(Qt::AlignCenter);
}

void ClickSlider::mousePressEvent(QMouseEvent *event)
{
   double pos = event->pos().x() / static_cast<double>(width());
   setValue(static_cast<int>(pos * (maximum() - minimum()) + minimum()));

   //QEvent evEvent(static_cast<QEvent::Type>(QEvent::User + 1));
   //QCoreApplication::sendEvent(parentWidget(), &evEvent);

    if(!m_displayLabel->isVisible())
    {
       m_displayLabel->setText(QString::number(this->value()*100/this->maximum()));
       m_displayLabel->move((this->width()-m_displayLabel->width())*this->value()/(this->maximum()-this->minimum()),-4);
       m_displayLabel->setVisible(true);
    }

    QSlider::mousePressEvent(event);
}

void ClickSlider::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_displayLabel->isVisible())
    {
        m_displayLabel->setVisible(false);
    }

    QSlider::mouseReleaseEvent(event);
}

void ClickSlider::mouseMoveEvent(QMouseEvent *event)
{
    m_displayLabel->setText(QString::number(this->value()*100/this->maximum()));
    m_displayLabel->move((this->width()-m_displayLabel->width())*this->value()/(this->maximum()-this->minimum()),-4);

    QSlider::mouseMoveEvent(event);
}
