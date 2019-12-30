#include "mywidgetcamera.h"

MyWidgetCamera::MyWidgetCamera(QWidget* parent) : QCameraViewfinder(parent)
{
}

void MyWidgetCamera::closeEvent(QCloseEvent* event)
{
    emit sig_close();

    event->accept();
}




