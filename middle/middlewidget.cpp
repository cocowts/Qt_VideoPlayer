#include "middlewidget.h"
#include <QKeyEvent >

#include "QDebug"

MiddleWidget::MiddleWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
    createAction();
    initSlot();
    setMouseTracking(true);
}

void MiddleWidget::initUi()
{
    m_layout = new QHBoxLayout;
    m_listwidget = new QListWidget(this);
    m_tempwidget = new QWidget(this);

    m_listwidget->setFixedWidth(200);
    m_listwidget->setStyleSheet("QListWidget{background-color:rgb(255, 255, 255);padding:0px;margin:0px;outline:0px;border:0px;}"\
                                "QListWidget::item{height:20px;width:100%;padding:1px;margin:0px;outline:0px;border:0px;}"\
                                "QListWidget::item:hover{background-color:rgb(231,231,231);padding:0px;margin:0px;}"\
                                "QListWidget::item:selected{background-color:rgb(212,212,212);padding:0px;margin:0px;}"\
                                "QListWidget::item:selected:active{background-color:rgb(212,212,212);padding:0px;margin:0px;}");


    m_layout->addWidget(m_listwidget);
    m_layout->addWidget(m_tempwidget);
    m_layout->setSpacing(0);
    m_layout->setMargin(0);

    setLayout(m_layout);
}

void MiddleWidget::initSlot()
{
    connect(m_listwidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(slot_itemDoubleClicked(QListWidgetItem*)));

    connect(m_clear_action, SIGNAL(triggered()), this, SLOT(slot_clearActionTrig()));
    connect(m_hide_action, SIGNAL(triggered()), this, SLOT(slot_hideActionTrig()));

    connect(m_openfile_action, SIGNAL(triggered()), this, SIGNAL(sig_openFileActionTrig()));
    connect(m_opendir_action, SIGNAL(triggered()), this, SIGNAL(sig_openDirActionTrig()));
    connect(m_clear_action, SIGNAL(triggered()), this, SIGNAL(sig_clearActionTrig()));
    connect(m_hide_action, SIGNAL(triggered()), this, SIGNAL(sig_hideActionTrig()));
    connect(m_opencamera_action, SIGNAL(triggered()), this, SIGNAL(sig_openCameraActionTrig()));
    connect(m_stream_action, SIGNAL(triggered()), this, SIGNAL(sig_openStreamActionTrig()));
}

void MiddleWidget::addVedioWidget(QWidget* widget)
{
    if ((widget != nullptr) && (m_tempwidget != nullptr))
    {
        m_layout->removeWidget(m_tempwidget);
        delete m_tempwidget;

        m_tempwidget = widget;
        m_layout->addWidget(m_tempwidget);
    }
}

void MiddleWidget::createAction()
{
    m_menu = new QMenu(this);
    m_openfile_action = new QAction("打开文件", m_menu);
    m_opendir_action  = new QAction("打开文件夹", m_menu);
    m_clear_action    = new QAction("清空列表", m_menu);
    m_hide_action     = new QAction("隐藏/显示列表", m_menu);
    m_opencamera_action = new QAction("打开摄像头", m_menu);
    m_stream_action     = new QAction("打开视频流", m_menu);

    m_menu->addAction(m_openfile_action);
    m_menu->addAction(m_opendir_action);
    m_menu->addSeparator();
    m_menu->addAction(m_clear_action);
    m_menu->addAction(m_hide_action);
    m_menu->addSeparator();
    m_menu->addAction(m_opencamera_action);
    m_menu->addAction(m_stream_action);
    m_menu->setStyleSheet("QMenu{background-color: rgb(255, 255, 255); border: 1px solid rgb(125, 125, 125);}"\
                          "QMenu::item{background-color: transparent; padding:3px 20px;margin:5px 10px;}"\
                          "QMenu::item:selected{background-color:rgb(231,231,231);}"\
                          "QMenu::item:pressed {background-color:rgb(212,212,212);}");
}

void MiddleWidget::appendListInfo(QStringList& list)
{
    for(int i=0; i<list.length(); i++)
    {
        m_listwidget->addItem(list[i]);
    }
}

void MiddleWidget::setListInfo(QStringList& list)
{
    m_listwidget->clear();

    for(int i=0; i<list.length(); i++)
    {
        m_listwidget->addItem(list[i]);
    }

    m_listwidget->show();
}

void MiddleWidget::setCurrentRow(int index)
{
    m_listwidget->setCurrentRow(index);
}

QWidget* MiddleWidget::getVedioWidget()
{
    return m_tempwidget;
}

void MiddleWidget::contextMenuEvent(QContextMenuEvent *event)
{
    m_menu->exec(QCursor::pos());

    event->accept();
}

void MiddleWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event)

    m_tempwidget->setWindowFlags(Qt::Window);
    m_tempwidget->showFullScreen();
}

void MiddleWidget::slot_itemDoubleClicked(QListWidgetItem* item)
{
    emit sig_itemDoubleClicked(item->text());
}

void MiddleWidget::slot_clearActionTrig()
{
    m_listwidget->clear();
}

void MiddleWidget::slot_hideActionTrig()
{
    if (m_listwidget->isHidden())
        m_listwidget->show();
    else
        m_listwidget->hide();
}



