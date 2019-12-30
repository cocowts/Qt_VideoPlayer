#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H

#include "clickslider.h"

#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class BottomWidget : public QFrame
{
    Q_OBJECT
public:
    enum PLAY_ORDER
    {
        SEQUENTIAL = 0,  // 列表顺序播放
        LOOP,            // 列表循环播放
        CURRENT_LOOP,    // 单曲循环播放
        RANDOM,          // 随机播放
        ORDER_COUNT
    };

    enum PLAY_STATUS
    {
        PAUSE = 0,
        PLAY
    };

public:
    BottomWidget(QWidget* parent = nullptr);
    void setCurTime(int value);
    void setFullTime(int value);
    void setVolume(int value);
    void setPlayStatus(PLAY_STATUS status);

    PLAY_ORDER getOrder();
    int getVolume();

    void setColor(QString rgb);

protected:
    QHBoxLayout* m_layout;

    QPushButton* m_last_btn;
    QPushButton* m_play_btn;
    QPushButton* m_stop_btn;
    QPushButton* m_next_btn;
    QPushButton* m_volume_btn;
    QPushButton* m_playorder_btn;

    QLabel* m_curtime_lbl;
    QLabel* m_fulltime_lbl;
    QLabel* m_btm_right_lbl;

    ClickSlider* m_curtime_slider;
    ClickSlider* m_volume_slider;

    int m_full_time;
    bool m_ispress;
    bool ms_issilence;

protected:
    void initUi();
    void initSlot();
    QString formatTime(int ms);
    void setOrder(PLAY_ORDER mode);

    void paintEvent(QPaintEvent* event);

protected slots:
    void slot_volumeBtnClicked();
    void slot_playorderBtnClicked();

    void slot_curtimeSliderPressed();
    void slot_curtimeSliderReleased();
    void slot_volumeSliderReleased();
    void slot_curtimeSliderMoved(int value);
    void slot_volumePliderMoved(int value);

signals:
    void sig_lastBtnClicked();
    void sig_playBtnClicked();
    void sig_stopBtnClicked();
    void sig_nextBtnClicked();
    void sig_volumeBtnClicked(int value);
    void sig_playorderBtnClicked();

    void sig_curtimeSliderPressed();
    void sig_curtimeSliderReleased();
    void sig_curtimeSliderMoved(int value);
    void sig_volumePliderMoved(int value);
};

#endif // BOTTOMWIDGET_H
