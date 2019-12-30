#include "mainwindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QCameraInfo>
#include <QDebug>

bool MainWindow::openFiles(OpenMode open_mode)
{
    bool ret = false;
    QFileDialog fdlg(this);
    QStringList name_filters;

    name_filters.append("*.mp4 *.flv *.avi");
    name_filters.append("*.mp4");
    name_filters.append("*.flv");
    name_filters.append("*.avi");

    fdlg.setWindowTitle("选择文件");
    fdlg.setWindowIcon(QIcon(":/Res/pic/titleIcon.png"));
    fdlg.setNameFilters(name_filters);
    fdlg.setAcceptMode(QFileDialog::AcceptOpen);

    if (open_mode == kOpenFile)
    {
        fdlg.setFileMode(QFileDialog::ExistingFiles);

        if( fdlg.exec() == QFileDialog::Accepted )
        {
            m_list_path = fdlg.selectedFiles();

            ret = true;
        }
    }
    else if (open_mode == kOpenDir)
    {
        fdlg.setFileMode(QFileDialog::Directory);

        if( fdlg.exec() == QFileDialog::Accepted )
        {
            QFileInfoList fi_list = fdlg.directory().entryInfoList(name_filters);

            for(int i=0; i<fi_list.length(); i++)
            {
                m_list_path.append(fi_list[i].filePath());
            }

            ret = true;
        }
    }

    if (ret == true)
    {
        QStringList filename_list;

        for(int i=0; i<m_list_path.length(); i++)
        {
            filename_list << QFileInfo(m_list_path[i]).fileName();
        }

        m_middlewidget->setListInfo(filename_list);
    }

    return ret;
}

QString MainWindow::getFilePath(QString filename)
{
    QString ret;

    for(int i=0; i<m_list_path.length(); i++)
    {
        if( m_list_path[i].indexOf(filename, 0) != -1 )
        {
            m_current_index = i;
            ret = m_list_path[i];

            break;
        }
    }

    return ret;
}

QString MainWindow::getIndexPath(int index)
{
    if (m_list_path.length()==0)
        return "";

    if (index >= 0)
    {
        index = index % m_list_path.length();
    }
    else
    {
        while(index<0)
        {
            index += m_list_path.length();
        }
    }

    m_current_index = index;
    m_middlewidget->setCurrentRow(index);

    return m_list_path[index];
}

void MainWindow::createLocalMedia(const QString& file, bool is_local)
{
    if (file != "")
    {
        m_player->stop();
        if (m_media != nullptr)
            delete m_media;

        m_bottomwidget->setCurTime(0);
        m_media = new VlcMedia(file, is_local, m_instance);
        m_player->open(m_media);
    }
}

void MainWindow::slot_skin()
{
    if (m_skinWidget->isVisible())
    {
        m_skinWidget->hide();
    }
    else
    {
        m_skinWidget->setGeometry(m_titlebar->getSkinBtnPos().x()-123, m_titlebar->getSkinBtnPos().y()+24, 260, 169);
        m_skinWidget->show();
        m_skinWidget->raise();
    }
}

void MainWindow::slot_about()
{
    AbortDialog(this).exec();
}

void MainWindow::slot_minimum()
{
    this->showMinimized();
}

void MainWindow::slot_maximum()
{
    static bool is_maximum = false;

    if(m_skinWidget->isVisible())
        slot_skin();

    if (!is_maximum)
        this->showMaximized();
    else
        this->showNormal();

    is_maximum = !is_maximum;
}

void MainWindow::slot_close()
{
    this->close();
}

void MainWindow::slot_itemSelected(QString string)
{
    QString file = getFilePath(string);

    createLocalMedia(file);
}

void MainWindow::slot_openFile()
{
    openFiles(kOpenFile);
}

void MainWindow::slot_openDir()
{
    openFiles(kOpenDir);
}

void MainWindow::slot_clear()
{
    m_list_path.clear();
}

void MainWindow::slot_hide()
{
}

void MainWindow::slot_openCamera()
{
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();

    if (cameras.length()!=0)
    {
        QInputDialog id(this);

        id.setContextMenuPolicy (Qt::NoContextMenu);
        id.setWindowTitle("相机");
        id.setLabelText("请选择要打开的相机设备");
        id.setOkButtonText("确定");
        id.setCancelButtonText("取消");
        id.setWindowFlag(Qt::Drawer);

        QStringList items;
        for(int i=0; i<cameras.length(); i++)
            items.append(QString("设备 ") + QString::number(i+1));
        id.setComboBoxItems(items);

        if (id.exec() == QInputDialog::Accepted)
        {
            if (m_camera!=nullptr)
                delete m_camera;

            int num = QString(id.textValue()[3]).toInt()-1;
            m_camera = new QCamera(cameras[num], this);

            m_camera->setViewfinder(m_viewfinder);
            m_camera->setCaptureMode(QCamera::CaptureVideo);
            m_camera->start();

            m_viewfinder->setWindowFlags(Qt::Window);
            m_viewfinder->showMaximized();
        }
    }
    else
    {
        QMessageBox(QMessageBox::Information, "相机", "当前无可用的相机设备", QMessageBox::Ok, this, Qt::Drawer).exec();
    }
}

void MainWindow::slot_openstream()
{
    QInputDialog id(this);

    id.setContextMenuPolicy (Qt::NoContextMenu);
    id.setWindowTitle("打开媒体");
    id.setLabelText("请输入网络 URL:\n[视网络环境等待时间会有不同]");
    id.setOkButtonText("确定");
    id.setCancelButtonText("取消");
    id.setWindowFlag(Qt::Drawer);

    if (id.exec() == QInputDialog::Accepted)
    {
        QString url = id.textValue();

        createLocalMedia(url, false);
    }
}
//
void MainWindow::slot_last()
{
    QString file = getIndexPath(m_current_index-1);

    createLocalMedia(file);
}

void MainWindow::slot_play()
{
    if (m_media == nullptr)
        return;

    if (m_player->state() == Vlc::Playing)
    {
        m_player->pause();
        m_bottomwidget->setPlayStatus(BottomWidget::PLAY);
    }
    else
    {
        m_player->play();
        m_bottomwidget->setPlayStatus(BottomWidget::PAUSE);
    }
}

void MainWindow::slot_stop()
{
    m_player->stop();

    m_bottomwidget->setFullTime(0);
    m_bottomwidget->setCurTime(0);
}

void MainWindow::slot_next()
{
    QString file = getIndexPath(m_current_index+1);

    createLocalMedia(file);
}

void MainWindow::slot_volume(int value)
{
    m_player->audio()->setVolume(value);
}

void MainWindow::slot_playorder()
{
}

void MainWindow::slot_curtimeMoved(int value)
{
    m_player->setTime(value);
}

void MainWindow::slot_volumeMoved(int value)
{
    m_player->audio()->setVolume(value);
}

void MainWindow::slot_playing()
{
    m_bottomwidget->setFullTime(m_player->length());
    m_bottomwidget->setPlayStatus(BottomWidget::PAUSE);
}

void MainWindow::slot_timeChanged(int time)
{
    m_bottomwidget->setCurTime(time);
}

void MainWindow::slot_end()
{
    m_bottomwidget->setCurTime(0);

    switch(m_bottomwidget->getOrder())
    {
    case BottomWidget::SEQUENTIAL:
        if ((m_current_index+1) != m_list_path.length())
            createLocalMedia(getIndexPath(m_current_index+1));
        break;

    case BottomWidget::LOOP:
        createLocalMedia(getIndexPath(m_current_index+1));
        break;

    case BottomWidget::CURRENT_LOOP:
        createLocalMedia(getIndexPath(m_current_index));
        break;

    case BottomWidget::RANDOM:
        createLocalMedia(getIndexPath(m_current_index+qrand()));
        break;

    default:
        break;
    }
}

void MainWindow::slot_error()
{
    QMessageBox(QMessageBox::Information, "播放异常", "请更换视频源后重试", QMessageBox::Ok, this, Qt::Drawer).exec();
}
//
void MainWindow::slot_cameraWidgetClose()
{
    m_camera->stop();
}
//
void MainWindow::slot_skinColor(QString rgb)
{
    m_titlebar->setColor(rgb);
    m_bottomwidget->setColor(rgb);
}
