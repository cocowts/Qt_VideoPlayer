#include "mywidgetvideo.h"
#include <QKeyEvent>
#include <QMouseEvent>

MyWidgetVideo::MyWidgetVideo(QWidget* parent) : VlcWidgetVideo(parent)
{

}

void MyWidgetVideo::keyPressEvent(QKeyEvent* e)
{
    if ((e->key() == Qt::Key_Escape) && isFullScreen())
    {
        this->setWindowFlags(Qt::SubWindow);
        this->showNormal();
    }
}


