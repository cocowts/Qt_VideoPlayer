#ifndef MYWIDGETVIDEO_H
#define MYWIDGETVIDEO_H

#include <VLCQtWidgets/WidgetVideo.h>

class MyWidgetVideo : public VlcWidgetVideo
{
    Q_OBJECT
public:
    explicit MyWidgetVideo(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* e);
};

#endif // MYWIDGETVIDEO_H
