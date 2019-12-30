#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QPoint>

class TitleBar : public QFrame
{
    Q_OBJECT

public:
    TitleBar(QWidget* parent = nullptr);
    void setColor(QString rgb);
    QPoint getSkinBtnPos();

protected:
     QHBoxLayout* m_layout;

     QPushButton* m_skin_btn;
     QPushButton* m_about_btn;
     QPushButton* m_minimum_btn;
     QPushButton* m_maximum_btn;
     QPushButton* m_close_btn;

protected:
    void initUi();
    void initSlot();

    void mouseDoubleClickEvent(QMouseEvent* event);

protected slots:
    void slot_skinBtnClicked();
    void slot_aboutBtnClicked();
    void slot_maximumBtnClicked();

signals:
    void sig_skinBtnClicked();
    void sig_aboutBtnClicked();
    void sig_minimumBtnClicked();
    void sig_maximumBtnClicked();
    void sig_closeBtnClicked();
};

#endif // TITLEBAR_H
