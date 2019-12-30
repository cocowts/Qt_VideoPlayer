#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : FramelessWidget(parent)
{
    m_current_index = 0;

    initUi();
    initMedia();
    initSlot();

    this->installEventFilter(this);
}

void MainWindow::initUi()
{
    m_layout       = new QVBoxLayout;
    m_titlebar     = new TitleBar(this);
    m_middlewidget = new MiddleWidget(this);
    m_bottomwidget = new BottomWidget(this);
    m_skinWidget   = new SkinWidget(this);

    m_layout->addWidget(m_titlebar);
    m_layout->addWidget(m_middlewidget);
    m_layout->addWidget(m_bottomwidget);
    m_layout->setSpacing(0);
    m_layout->setMargin(0);

    slot_skinColor("rgb(0, 179, 89)");

    setLayout(m_layout);
    showNormal();
}

void MainWindow::initSlot()
{
    connect(m_titlebar, SIGNAL(sig_skinBtnClicked()), this, SLOT(slot_skin()));
    connect(m_titlebar, SIGNAL(sig_aboutBtnClicked()), this, SLOT(slot_about()));
    connect(m_titlebar, SIGNAL(sig_minimumBtnClicked()), this, SLOT(slot_minimum()));
    connect(m_titlebar, SIGNAL(sig_maximumBtnClicked()), this, SLOT(slot_maximum()));
    connect(m_titlebar, SIGNAL(sig_closeBtnClicked()), this, SLOT(slot_close()));
    //
    connect(m_middlewidget, SIGNAL(sig_itemDoubleClicked(QString)), this, SLOT(slot_itemSelected(QString)));
    connect(m_middlewidget, SIGNAL(sig_openFileActionTrig()), this, SLOT(slot_openFile()));
    connect(m_middlewidget, SIGNAL(sig_openDirActionTrig()), this, SLOT(slot_openDir()));
    connect(m_middlewidget, SIGNAL(sig_clearActionTrig()), this, SLOT(slot_clear()));
    connect(m_middlewidget, SIGNAL(sig_hideActionTrig()), this, SLOT(slot_hide()));
    connect(m_middlewidget, SIGNAL(sig_openCameraActionTrig()), this, SLOT(slot_openCamera()));
    connect(m_middlewidget, SIGNAL(sig_openStreamActionTrig()), this, SLOT(slot_openstream()));
    //
    connect(m_bottomwidget, SIGNAL(sig_lastBtnClicked()), this, SLOT(slot_last()));
    connect(m_bottomwidget, SIGNAL(sig_playBtnClicked()), this, SLOT(slot_play()));
    connect(m_bottomwidget, SIGNAL(sig_stopBtnClicked()), this, SLOT(slot_stop()));
    connect(m_bottomwidget, SIGNAL(sig_nextBtnClicked()), this, SLOT(slot_next()));
    connect(m_bottomwidget, SIGNAL(sig_volumeBtnClicked(int)), this, SLOT(slot_volume(int)));
    connect(m_bottomwidget, SIGNAL(sig_playorderBtnClicked()), this, SLOT(slot_playorder()));
    connect(m_bottomwidget, SIGNAL(sig_curtimeSliderMoved(int)), this, SLOT(slot_curtimeMoved(int)));
    connect(m_bottomwidget, SIGNAL(sig_volumePliderMoved(int)), this, SLOT(slot_volumeMoved(int)));
    //
    connect(m_player, SIGNAL(playing()), this, SLOT(slot_playing()));
    connect(m_player, SIGNAL(timeChanged(int)), this, SLOT(slot_timeChanged(int)));
    connect(m_player, SIGNAL(end()), this, SLOT(slot_end()));
    connect(m_player, SIGNAL(error()), this, SLOT(slot_error()));
    //
    connect(m_viewfinder, SIGNAL(sig_close()), this, SLOT(slot_cameraWidgetClose()));
    //
    connect(m_skinWidget, SIGNAL(sig_colorLblClicked(QString)), this, SLOT(slot_skinColor(QString)));
}

void MainWindow::initMedia()
{
    m_media    = nullptr;
    m_instance = new VlcInstance(VlcCommon::args(), this);
    m_player   = new VlcMediaPlayer(m_instance);
    m_video    = new MyWidgetVideo(this);
    m_player->setVideoWidget(m_video);
    m_middlewidget->addVedioWidget(m_video);

    m_viewfinder = new MyWidgetCamera(this);
    m_camera     = new QCamera(this);

    m_viewfinder->setWindowTitle("相机");
    m_viewfinder->setWindowIcon(QIcon(":/pic/top/pic/titleIcon.png"));
}

MainWindow::~MainWindow()
{
    delete m_player;
    delete m_media;
}
