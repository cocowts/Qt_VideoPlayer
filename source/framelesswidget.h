#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>

enum class CursorPos : char
{
    Default,
    Right,
    Left,
    Bottom,
    Top,
    TopRight,
    TopLeft,
    BottomRight,
    BottomLeft
};

#pragma pack(push)
#pragma pack(1)

struct pressWindowState final
{
    bool MousePressed;
    bool IsPressBorder;
    QPoint MousePos;
    QPoint WindowPos;
};

class FramelessWidget : public QWidget
{
    Q_OBJECT

protected:
    pressWindowState m_state;
    int              m_border;
    CursorPos        m_curPos;

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

public:
    explicit FramelessWidget(QWidget *parent = nullptr);
    void mouseMoveRect(const QPoint &p);

signals:
    void sig_PosChange(int,int);

public slots:
};

#pragma pack(pop)

#endif // FRAMELESSWIDGET_H
