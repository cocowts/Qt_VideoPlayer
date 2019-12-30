#include "skinwidget.h"
#include <QDebug>

SkinWidget::SkinWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
    initSlot();
}

void SkinWidget::initUi()
{
    this->setFixedSize(260, 160);
    this->hide();

    QVBoxLayout* main_layout  = new QVBoxLayout;
    QHBoxLayout* line1_layout = new QHBoxLayout;
    QHBoxLayout* line2_layout = new QHBoxLayout;

    m_textlbl = new QLabel("纯色皮肤", this);

    m_color_lbl1 = new ClickLabel(this);
    m_color_lbl1->setCursor(Qt::PointingHandCursor);
    m_color_lbl1->setStyleSheet("QLabel{background-color:rgb(255, 102, 102);}");

    m_color_lbl2 = new ClickLabel(this);
    m_color_lbl2->setCursor(Qt::PointingHandCursor);
    m_color_lbl2->setStyleSheet("QLabel{background-color:rgb(255, 153, 153)}");

    m_color_lbl3 = new ClickLabel(this);
    m_color_lbl3->setCursor(Qt::PointingHandCursor);
    m_color_lbl3->setStyleSheet("QLabel{background-color:rgb(255, 153, 220)}");

    m_color_lbl4 = new ClickLabel(this);
    m_color_lbl4->setCursor(Qt::PointingHandCursor);
    m_color_lbl4->setStyleSheet("QLabel{background-color:rgb(102, 139, 255)}");

    m_color_lbl5 = new ClickLabel(this);
    m_color_lbl5->setCursor(Qt::PointingHandCursor);
    m_color_lbl5->setStyleSheet("QLabel{background-color:rgb(102, 163, 255)}");

    m_color_lbl6 = new ClickLabel(this);
    m_color_lbl6->setCursor(Qt::PointingHandCursor);
    m_color_lbl6->setStyleSheet("QLabel{background-color:rgb(102, 194, 255)}");
    //
    m_color_lbl7 = new ClickLabel(this);
    m_color_lbl7->setCursor(Qt::PointingHandCursor);
    m_color_lbl7->setStyleSheet("QLabel{background-color:rgb(0, 179, 89)}");

    m_color_lbl8 = new ClickLabel(this);
    m_color_lbl8->setCursor(Qt::PointingHandCursor);
    m_color_lbl8->setStyleSheet("QLabel{background-color:rgb(51, 204, 51)}");

    m_color_lbl9 = new ClickLabel(this);
    m_color_lbl9->setCursor(Qt::PointingHandCursor);
    m_color_lbl9->setStyleSheet("QLabel{background-color:rgb(204, 163, 0)}");

    m_color_lbl10 = new ClickLabel(this);
    m_color_lbl10->setCursor(Qt::PointingHandCursor);
    m_color_lbl10->setStyleSheet("QLabel{background-color:rgb(255, 153, 102)}");

    m_color_lbl11 = new ClickLabel(this);
    m_color_lbl11->setCursor(Qt::PointingHandCursor);
    m_color_lbl11->setStyleSheet("QLabel{background-color:rgb(255, 178, 128)}");

    m_color_lbl12 = new ClickLabel(this);
    m_color_lbl12->setCursor(Qt::PointingHandCursor);
    m_color_lbl12->setStyleSheet("QLabel{background-color:rgb(255, 102, 51)}");

    main_layout->addWidget(m_textlbl);

    line1_layout->addWidget(m_color_lbl1);
    line1_layout->addWidget(m_color_lbl2);
    line1_layout->addWidget(m_color_lbl3);
    line1_layout->addWidget(m_color_lbl4);
    line1_layout->addWidget(m_color_lbl5);
    line1_layout->addWidget(m_color_lbl6);

    line2_layout->addWidget(m_color_lbl7);
    line2_layout->addWidget(m_color_lbl8);
    line2_layout->addWidget(m_color_lbl9);
    line2_layout->addWidget(m_color_lbl10);
    line2_layout->addWidget(m_color_lbl11);
    line2_layout->addWidget(m_color_lbl12);

    main_layout->addSpacing(4);
    main_layout->addLayout(line1_layout);
    main_layout->addSpacing(4);
    main_layout->addLayout(line2_layout);
    main_layout->addSpacing(4);

    setLayout(main_layout);
}

void SkinWidget::initSlot()
{
    connect(m_color_lbl1, SIGNAL(clicked()), this, SLOT(slot_colorLbl1Clicked()));
    connect(m_color_lbl2, SIGNAL(clicked()), this, SLOT(slot_colorLbl2Clicked()));
    connect(m_color_lbl3, SIGNAL(clicked()), this, SLOT(slot_colorLbl3Clicked()));
    connect(m_color_lbl4, SIGNAL(clicked()), this, SLOT(slot_colorLbl4Clicked()));
    connect(m_color_lbl5, SIGNAL(clicked()), this, SLOT(slot_colorLbl5Clicked()));
    connect(m_color_lbl6, SIGNAL(clicked()), this, SLOT(slot_colorLbl6Clicked()));
    connect(m_color_lbl7, SIGNAL(clicked()), this, SLOT(slot_colorLbl7Clicked()));
    connect(m_color_lbl8, SIGNAL(clicked()), this, SLOT(slot_colorLbl8Clicked()));
    connect(m_color_lbl9, SIGNAL(clicked()), this, SLOT(slot_colorLbl9Clicked()));
    connect(m_color_lbl10, SIGNAL(clicked()), this, SLOT(slot_colorLbl10Clicked()));
    connect(m_color_lbl11, SIGNAL(clicked()), this, SLOT(slot_colorLbl11Clicked()));
    connect(m_color_lbl12, SIGNAL(clicked()), this, SLOT(slot_colorLbl12Clicked()));
}

void SkinWidget::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.save();

    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor(115, 115, 115));
    painter.setBrush(QColor(229, 255, 255));

    painter.drawRoundedRect(QRectF(0,9,260,160),7,7);
    QPolygonF polygon;
    polygon<<QPointF(130,0)<<QPointF(120,9)<<QPointF(140,9)<<QPointF(130,0);
    painter.drawPolygon(polygon,Qt::WindingFill);

    painter.restore();
}

void SkinWidget::slot_colorLbl1Clicked()
{
    emit sig_colorLblClicked("rgb(255, 102, 102)");
}

void SkinWidget::slot_colorLbl2Clicked()
{
    emit sig_colorLblClicked("rgb(255, 153, 153)");
}

void SkinWidget::slot_colorLbl3Clicked()
{
    emit sig_colorLblClicked("rgb(255, 153, 220)");
}

void SkinWidget::slot_colorLbl4Clicked()
{
    emit sig_colorLblClicked("rgb(102, 139, 255)");
}

void SkinWidget::slot_colorLbl5Clicked()
{
    emit sig_colorLblClicked("rgb(102, 163, 255)");
}

void SkinWidget::slot_colorLbl6Clicked()
{
    emit sig_colorLblClicked("rgb(102, 194, 255)");
}

void SkinWidget::slot_colorLbl7Clicked()
{
    emit sig_colorLblClicked("rgb(0, 179, 89)");
}

void SkinWidget::slot_colorLbl8Clicked()
{
    emit sig_colorLblClicked("rgb(51, 204, 51)");
}

void SkinWidget::slot_colorLbl9Clicked()
{
    emit sig_colorLblClicked("rgb(204, 163, 0)");
}

void SkinWidget::slot_colorLbl10Clicked()
{
    emit sig_colorLblClicked("rgb(255, 153, 102)");
}

void SkinWidget::slot_colorLbl11Clicked()
{
    emit sig_colorLblClicked("rgb(255, 178, 128)");
}

void SkinWidget::slot_colorLbl12Clicked()
{
    emit sig_colorLblClicked("rgb(255, 102, 51)");
}
