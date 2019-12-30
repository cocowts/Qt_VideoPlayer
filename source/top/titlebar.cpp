#include "titlebar.h"
#include <QApplication>
#include <QDebug>

TitleBar::TitleBar(QWidget* parent) : QFrame(parent)
{
    initUi();
    setMouseTracking(true);
    initSlot();
}

void TitleBar::initUi()
{
    QLabel* title_icon_lbl = new QLabel(this);
    QLabel* null_lbl       = new QLabel(this);

    m_layout      = new QHBoxLayout;
    m_skin_btn    = new QPushButton(this);
    m_about_btn   = new QPushButton(this);
    m_minimum_btn = new QPushButton(this);
    m_maximum_btn = new QPushButton(this);
    m_close_btn   = new QPushButton(this);

    title_icon_lbl->setFixedSize(32, 32);
    title_icon_lbl->setCursor(Qt::PointingHandCursor);
    title_icon_lbl->setPixmap(QPixmap(":/pic/top/pic/titleIcon.png"));

    m_skin_btn->setCursor(Qt::PointingHandCursor);
    m_skin_btn->setToolTip("换肤");
    m_skin_btn->setFixedSize(16, 14);
    m_skin_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/skin.png);}\
                               QPushButton::hover{border-image:url(:/pic/top/pic/skin_hover.png);}");

    m_about_btn->setCursor(Qt::PointingHandCursor);
    m_about_btn->setToolTip("关于");
    m_about_btn->setFixedSize(14, 14);
    m_about_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/about.png);}\
                               QPushButton::hover{border-image:url(:/pic/top/pic/about_hover.png);}");


    null_lbl->setPixmap(QPixmap(":/pic/top/pic/line.png"));

    m_minimum_btn->setCursor(Qt::PointingHandCursor);
    m_minimum_btn->setToolTip("最小化");
    m_minimum_btn->setFixedSize(14, 18);
    m_minimum_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/minimum.png);}\
                                 QPushButton::hover{border-image:url(:/pic/top/pic/minimum_hover.png);}");

    m_maximum_btn->setCursor(Qt::PointingHandCursor);
    m_maximum_btn->setToolTip("最大化");
    m_maximum_btn->setFixedSize(14, 11);
    m_maximum_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/maximum.png);}\
                                 QPushButton::hover{border-image:url(:/pic/top/pic/maximum_hover.png);}");

    m_close_btn->setCursor(Qt::PointingHandCursor);
    m_close_btn->setFixedSize(12, 11);
    m_close_btn->setToolTip("关闭");
    m_close_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/close.png);}\
                               QPushButton::hover{border-image:url(:/pic/top/pic/close_hover.png);}");

   m_layout->setSpacing(0);
   m_layout->addWidget(title_icon_lbl);
   m_layout->addStretch();
   m_layout->addWidget(m_skin_btn);
   m_layout->addSpacing(20);
   m_layout->addWidget(m_about_btn);
   m_layout->addSpacing(20);
   m_layout->addWidget(null_lbl);
   m_layout->addSpacing(20);
   m_layout->addWidget(m_minimum_btn);
   m_layout->addSpacing(20);
   m_layout->addWidget(m_maximum_btn);
   m_layout->addSpacing(20);
   m_layout->addWidget(m_close_btn);

   setLayout(m_layout);
   setFixedHeight(50);
   setStyleSheet("QFrame{Background:rgb(102,183,255);}");
}

void TitleBar::initSlot()
{
    connect(m_skin_btn, SIGNAL(clicked()), this, SLOT(slot_skinBtnClicked()));
    connect(m_about_btn, SIGNAL(clicked()), this, SLOT(slot_aboutBtnClicked()));
    connect(m_maximum_btn, SIGNAL(clicked()), this, SLOT(slot_maximumBtnClicked()));

    connect(m_minimum_btn, SIGNAL(clicked()), this, SIGNAL(sig_minimumBtnClicked()));
    connect(m_close_btn, SIGNAL(clicked()), this, SIGNAL(sig_closeBtnClicked()));
}

void TitleBar::setColor(QString rgb)
{
    setStyleSheet("QFrame{Background:" + rgb + ";}");
}

QPoint TitleBar::getSkinBtnPos()
{
    return m_skin_btn->pos();
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        slot_maximumBtnClicked();
    else
        QWidget::mouseDoubleClickEvent(event);
}

void TitleBar::slot_skinBtnClicked()
{
    emit sig_skinBtnClicked();
}

void TitleBar::slot_aboutBtnClicked()
{
    emit sig_aboutBtnClicked();
}

void TitleBar::slot_maximumBtnClicked()
{
    static bool is_max = false;

    if (is_max)
    {
        m_maximum_btn->setToolTip("最大化");
        m_maximum_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/maximum.png);}\
                                     QPushButton::hover{border-image:url(:/pic/top/pic/maximum_hover.png);}");
    }
    else
    {
       m_maximum_btn->setToolTip("向下还原");
       m_maximum_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/top/pic/maximum_cancel.png);}\
                                    QPushButton::hover{border-image:url(:/pic/top/pic/maximum_cancel_hover.png);}");
    }
    is_max = !is_max;

    emit sig_maximumBtnClicked();
}
