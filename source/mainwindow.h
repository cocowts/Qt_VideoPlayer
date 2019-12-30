#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <top/titlebar.h>
#include <middle/middlewidget.h>
#include <bottom/bottomwidget.h>
#include <framelesswidget.h>
#include <mywidgetvideo.h>
#include <mywidgetcamera.h>
#include <about/abortdialog.h>
#include <skin/skinwidget.h>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Audio.h>

#include <QCamera>
#include <QCameraViewfinder>

#include <QVBoxLayout>

class MainWindow : public FramelessWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

protected:
    enum OpenMode
    {
        kOpenFile = 0,
        kOpenDir
    };

    QVBoxLayout*  m_layout = nullptr;

    MiddleWidget* m_middlewidget = nullptr;
    BottomWidget* m_bottomwidget = nullptr;
    TitleBar*     m_titlebar;
    SkinWidget*   m_skinWidget = nullptr;

    MyWidgetVideo*  m_video    = nullptr;
    VlcInstance*    m_instance = nullptr;
    VlcMedia*       m_media    = nullptr;
    VlcMediaPlayer* m_player   = nullptr;

    MyWidgetCamera* m_viewfinder = nullptr;
    QCamera*        m_camera     = nullptr;

    QStringList m_list_path;
    int m_current_index;

protected:
    void initUi();
    void initSlot();
    void initMedia();

    bool openFiles(OpenMode open_mode);
    QString getFilePath(QString filename);
    QString getIndexPath(int index);
    void createLocalMedia(const QString& file, bool is_local = true);

protected slots:
    void slot_skin();
    void slot_about();
    void slot_minimum();
    void slot_maximum();
    void slot_close();
    //
    void slot_itemSelected(QString string);
    void slot_openFile();
    void slot_openDir();
    void slot_clear();
    void slot_hide();
    void slot_openCamera();
    void slot_openstream();
    //
    void slot_last();
    void slot_play();
    void slot_stop();
    void slot_next();
    void slot_volume(int value);
    void slot_playorder();
    //
    void slot_curtimeMoved(int value);
    void slot_volumeMoved(int value);
    //
    void slot_playing();
    void slot_timeChanged(int time);
    void slot_end();
    void slot_error();
    //
    void slot_cameraWidgetClose();
    //
    void slot_skinColor(QString rgb);
};

#endif // MAINWINDOW_H
