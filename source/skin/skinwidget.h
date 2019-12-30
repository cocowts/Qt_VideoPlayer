#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <skin/clicklabel.h>

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>

class SkinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SkinWidget(QWidget *parent = nullptr);

protected:
    QLabel* m_textlbl;
    ClickLabel *m_color_lbl1, *m_color_lbl2, *m_color_lbl3, *m_color_lbl4, *m_color_lbl5, *m_color_lbl6;
    ClickLabel *m_color_lbl7, *m_color_lbl8, *m_color_lbl9, *m_color_lbl10, *m_color_lbl11, *m_color_lbl12;

protected:
    void initUi();
    void initSlot();

    void paintEvent(QPaintEvent* e);

signals:
    void sig_colorLblClicked(QString rgb);

protected slots:
    void slot_colorLbl1Clicked();
    void slot_colorLbl2Clicked();
    void slot_colorLbl3Clicked();
    void slot_colorLbl4Clicked();
    void slot_colorLbl5Clicked();
    void slot_colorLbl6Clicked();
    void slot_colorLbl7Clicked();
    void slot_colorLbl8Clicked();
    void slot_colorLbl9Clicked();
    void slot_colorLbl10Clicked();
    void slot_colorLbl11Clicked();
    void slot_colorLbl12Clicked();
};

#endif // SKINWIDGET_H
