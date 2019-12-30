#include "bottomwidget.h"

#include <QIcon>
#include <QPixmap>

#include <QDebug>

BottomWidget::BottomWidget(QWidget* parent) : QFrame(parent)
{
    m_full_time = 0;
    m_ispress = false;
    ms_issilence = false;

    initUi();
    initSlot();
    setMouseTracking(true);

    setCurTime(0);
    setFullTime(0);
    setVolume(0);
}

void BottomWidget::initUi()
{
    m_layout         = new QHBoxLayout;
    m_last_btn       = new QPushButton(this);
    m_play_btn       = new QPushButton(this);
    m_stop_btn       = new QPushButton(this);
    m_next_btn       = new QPushButton(this);
    m_volume_btn     = new QPushButton(this);
    m_playorder_btn  = new QPushButton(this);
    m_curtime_lbl    = new QLabel(this);
    m_fulltime_lbl   = new QLabel(this);
    m_btm_right_lbl  = new QLabel(this);
    m_curtime_slider = new ClickSlider(this);
    m_volume_slider  = new ClickSlider(this);
    //
    m_last_btn->setFixedSize(30, 30);
    m_last_btn->setCursor(Qt::PointingHandCursor);
    m_last_btn->setToolTip("上一部");
    m_last_btn->setIcon(QIcon(":/pic/bottom/pic/last.png"));
    m_last_btn->setIconSize(m_last_btn->size());
    m_last_btn->setStyleSheet("QPushButton{background:rgb(102, 183, 255);border-radius:15px}");

    m_play_btn->setFixedSize(34, 34);
    m_play_btn->setCursor(Qt::PointingHandCursor);
    m_play_btn->setToolTip("播放");
    m_play_btn->setIcon(QIcon(":/pic/bottom/pic/play.png"));
    m_play_btn->setIconSize(m_play_btn->size());
    m_play_btn->setStyleSheet("QPushButton{background:rgb(102, 183, 255);border-radius:17px}");

    m_stop_btn->setFixedSize(34, 34);
    m_stop_btn->setCursor(Qt::PointingHandCursor);
    m_stop_btn->setToolTip("停止");
    m_stop_btn->setIcon(QIcon(":/pic/bottom/pic/stop.png"));
    m_stop_btn->setIconSize(m_stop_btn->size());
    m_stop_btn->setStyleSheet("QPushButton{background:rgb(102, 183, 255);border-radius:17px}");

    m_next_btn->setFixedSize(30, 30);
    m_next_btn->setCursor(Qt::PointingHandCursor);
    m_next_btn->setToolTip("下一部");
    m_next_btn->setIcon(QIcon(":/pic/bottom/pic/next.png"));
    m_next_btn->setIconSize(m_next_btn->size());
    m_next_btn->setStyleSheet("QPushButton{background:rgb(102, 183, 255);border-radius:15px}");
    //
    m_curtime_lbl->setText("00:00:00");
    m_curtime_lbl->setFixedHeight(15);

    m_curtime_slider->setOrientation(Qt::Horizontal);
    m_curtime_slider->setMinimumSize(100, 15);
    m_curtime_slider->setRange(0, 300);
    m_curtime_slider->setSingleStep(1);
    m_curtime_slider->setCursor(Qt::PointingHandCursor);
    m_curtime_slider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: rgb(102,183,255);}\
                                     QSlider::add-page:horizontal{background:#c2c2c4;}\
                                     QSlider::handle:horizontal{width: 14px;background: url(:/pic/bottom/pic/curtime_handle.png);margin: -5 0 -5 0}");

    m_fulltime_lbl->setText("00:00:00");
    m_fulltime_lbl->setFixedHeight(15);
    //
    m_volume_btn->setFixedSize(16, 12);
    m_volume_btn->setCursor(Qt::PointingHandCursor);
    m_volume_btn->setToolTip("静音");
    m_volume_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/volume.png)}");

    m_volume_slider->setOrientation(Qt::Horizontal);
    m_volume_slider->setFixedSize(80, 15);
    m_volume_slider->setToolTip("音量调节");
    m_volume_slider->setMinimum(0);
    m_volume_slider->setMaximum(100);
    m_volume_slider->setSingleStep(1);
    m_volume_slider->setCursor(Qt::PointingHandCursor);
    m_volume_slider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: rgb(102,183,255);}\
                                     QSlider::add-page:horizontal{background:#c2c2c4;}\
                                     QSlider::handle:horizontal{width: 12px;background: url(:/pic/bottom/pic/volume_handle.png);margin: -4 0 -4 0}");
    //
    m_playorder_btn->setFixedSize(17, 14);
    m_playorder_btn->setCursor(Qt::PointingHandCursor);
    m_playorder_btn->setToolTip("顺序播放");
    m_playorder_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/sequential.png)}");
    //
    m_btm_right_lbl->setParent(this);
    m_btm_right_lbl->setPixmap(QPixmap(":/pic/bottom/pic/bottom_right.png"));
    m_btm_right_lbl->setAttribute(Qt::WA_TranslucentBackground);
    //
    m_layout->addWidget(m_last_btn);
    m_layout->addSpacing(10);
    m_layout->addWidget(m_play_btn);
    m_layout->addSpacing(10);
    m_layout->addWidget(m_stop_btn);
    m_layout->addSpacing(10);
    m_layout->addWidget(m_next_btn);
    m_layout->addSpacing(20);

    m_layout->addWidget(m_fulltime_lbl);
    m_layout->addWidget(m_curtime_slider);
    m_layout->addWidget(m_curtime_lbl);

    m_layout->addSpacing(10);
    m_layout->addWidget(m_volume_btn);
    m_layout->addWidget(m_volume_slider);
    m_layout->addSpacing(10);
    m_layout->addWidget(m_playorder_btn);

    m_layout->setMargin(10);
    m_layout->setSpacing(10);

    setLayout(m_layout);
    setFixedHeight(50);
    setStyleSheet("QFrame{Background:rgb(246,246,248);border-color:rgb(225,225,225);border-width:lpx;border-style: solid}");
}

void BottomWidget::initSlot()
{
    connect(m_last_btn, SIGNAL(clicked()), this, SIGNAL(sig_lastBtnClicked()));
    connect(m_play_btn, SIGNAL(clicked()), this, SIGNAL(sig_playBtnClicked()));
    connect(m_stop_btn, SIGNAL(clicked()), this, SIGNAL(sig_stopBtnClicked()));
    connect(m_next_btn, SIGNAL(clicked()), this, SIGNAL(sig_nextBtnClicked()));

    connect(m_volume_btn, SIGNAL(clicked()), this, SLOT(slot_volumeBtnClicked()));
    connect(m_playorder_btn, SIGNAL(clicked()), this, SLOT(slot_playorderBtnClicked()));

    connect(m_curtime_slider, SIGNAL(sliderPressed()), this, SLOT(slot_curtimeSliderPressed()));
    connect(m_curtime_slider, SIGNAL(sliderReleased()), this, SLOT(slot_curtimeSliderReleased()));
    connect(m_volume_slider, SIGNAL(sliderReleased()), this, SLOT(slot_volumeSliderReleased()));
    connect(m_curtime_slider, SIGNAL(sliderMoved(int)), this, SLOT(slot_curtimeSliderMoved(int)));
    connect(m_volume_slider, SIGNAL(sliderMoved(int)), this, SLOT(slot_volumePliderMoved(int)));
}

QString BottomWidget::formatTime(int ms)
{
    const int ss = 1000;
    const int mi = ss * 60;
    const int hh = mi * 60;

    int hour   = ms / hh;
    int minute = (ms - hour * hh) / mi;
    int second = (ms - hour * hh - minute * mi) / ss;

    QString hou;
    QString min;
    QString sec;

    hou.sprintf("%02d", hour);
    min.sprintf("%02d", minute);
    sec.sprintf("%02d", second);

    return hou + ":" + min + ":" + sec ;
}

void BottomWidget::setCurTime(int value)
{
    if (m_ispress) return;

    int pos = 0;

    if (m_full_time == 0)
        pos = 0;
    else
        pos = static_cast<int>(value * m_curtime_slider->maximum() / m_full_time);

    m_curtime_slider->setValue(pos);
    m_curtime_lbl->setText(formatTime(value));
}

void BottomWidget::setFullTime(int value)
{
    m_full_time = value;

    m_fulltime_lbl->setText(formatTime(value));
}

void BottomWidget::setVolume(int value)
{
    m_volume_slider->setValue(value);
}

void BottomWidget::setPlayStatus(PLAY_STATUS status)
{
    if (status == PLAY)
    {
        m_play_btn->setToolTip("播放");
        m_play_btn->setIcon(QIcon(":/pic/bottom/pic/play.png"));
    }
    else
    {
        m_play_btn->setToolTip("暂停");
        m_play_btn->setIcon(QIcon(":/pic/bottom/pic/pause.png"));
    }
}

BottomWidget::PLAY_ORDER BottomWidget::getOrder()
{
    if (m_playorder_btn->toolTip() == "顺序播放")
    {
        return SEQUENTIAL;
    }
    else if (m_playorder_btn->toolTip() == "循环播放")
    {
        return LOOP;
    }
    else if (m_playorder_btn->toolTip() == "单曲播放")
    {
        return CURRENT_LOOP;
    }
    else if (m_playorder_btn->toolTip() == "随机播放")
    {
        return RANDOM;
    }

    return SEQUENTIAL;
}

int BottomWidget::getVolume()
{
    return m_volume_slider->value();
}

void BottomWidget::setOrder(PLAY_ORDER mode)
{
    switch (mode)
    {
    case SEQUENTIAL:
        m_playorder_btn->setToolTip("顺序播放");
        m_playorder_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/sequential.png)}");
        break;
    case LOOP:
        m_playorder_btn->setToolTip("循环播放");
        m_playorder_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/loop.png)}");
        break;
    case CURRENT_LOOP:
        m_playorder_btn->setToolTip("单曲播放");
        m_playorder_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/currentiteminloop.png)}");
        break;
    case RANDOM:
        m_playorder_btn->setToolTip("随机播放");
        m_playorder_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/random.png)}");
        break;
    default:
        break;
    }
}

void BottomWidget::setColor(QString rgb)
{
    m_last_btn->setStyleSheet("QPushButton{background:" + rgb + ";border-radius:15px}");
    m_play_btn->setStyleSheet("QPushButton{background:" + rgb + ";border-radius:17px}");
    m_stop_btn->setStyleSheet("QPushButton{background:" + rgb + ";border-radius:17px}");
    m_next_btn->setStyleSheet("QPushButton{background:" + rgb + ";border-radius:15px}");
    m_curtime_slider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: " + rgb + ";}\
                                     QSlider::add-page:horizontal{background:#c2c2c4;}\
                                     QSlider::handle:horizontal{width: 14px;background: url(:/pic/bottom/pic/curtime_handle.png);margin: -5 0 -5 0}");
    m_volume_slider->setStyleSheet("QSlider::groove:horizontal{height: 4px;background: " + rgb + ";}\
                                    QSlider::add-page:horizontal{background:#c2c2c4;}\
                                    QSlider::handle:horizontal{width: 12px;background: url(:/pic/bottom/pic/volume_handle.png);margin: -4 0 -4 0}");
}

//
void BottomWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    m_btm_right_lbl->setGeometry(width()-13, height()-13, 10, 10);
}

//
void BottomWidget::slot_volumeBtnClicked()
{
    static int volume = m_volume_slider->value();

    if (ms_issilence)
    {
        m_volume_btn->setToolTip("静音");
        m_volume_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/volume.png)}");
        m_volume_slider->setValue(volume);

        emit sig_volumeBtnClicked(volume);
    }
    else
    {
        m_volume_btn->setToolTip("音量");
        m_volume_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/volume_silence.png)}");
        volume = m_volume_slider->value();
        m_volume_slider->setValue(0);

        emit sig_volumeBtnClicked(0);
    }

    ms_issilence = !ms_issilence;
}

void BottomWidget::slot_playorderBtnClicked()
{
    int order = (static_cast<int>(getOrder()) + 1) % ORDER_COUNT;

    setOrder(static_cast<PLAY_ORDER>(order));

    emit sig_playorderBtnClicked();
}

void BottomWidget::slot_curtimeSliderPressed()
{
    m_ispress = true;
}

void BottomWidget::slot_curtimeSliderReleased()
{
    m_ispress = false;

    int value = m_curtime_slider->value();

    slot_curtimeSliderMoved(value);
}

void BottomWidget::slot_volumeSliderReleased()
{
    int value = m_volume_slider->value();

    slot_volumePliderMoved(value);
}

void BottomWidget::slot_curtimeSliderMoved(int value)
{
    if( m_full_time != 0 )
    {
       int current = static_cast<int>((value * m_full_time / m_curtime_slider->maximum()));

       m_curtime_lbl->setText(formatTime(current));

       emit sig_curtimeSliderMoved(current);
    }
    else
    {
       m_curtime_slider->setValue(value);
    }
}

void BottomWidget::slot_volumePliderMoved(int value)
{
    if(value!=0)
    {
        ms_issilence = true;
        m_volume_btn->setToolTip("静音");
        m_volume_btn->setStyleSheet("QPushButton{background:transparent;border-image:url(:/pic/bottom/pic/volume.png)}");
    }

    emit sig_volumePliderMoved(value);
}


