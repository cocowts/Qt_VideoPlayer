#ifndef MYWIDGETCAMERA_H
#define MYWIDGETCAMERA_H

#include <QCameraViewfinder>
#include <QCloseEvent>
#include <QWidget>

class MyWidgetCamera : public QCameraViewfinder
{
    Q_OBJECT

public:
    explicit MyWidgetCamera(QWidget* parent = nullptr);

protected:
    void closeEvent(QCloseEvent* event);

signals:
    void sig_close();
};

#endif // MYWIDGETCAMERA_H
