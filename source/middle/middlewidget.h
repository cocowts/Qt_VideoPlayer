#ifndef MIDDLEWIDGET_H
#define MIDDLEWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QAction>
#include <QMenu>
#include <QContextMenuEvent>

class MiddleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MiddleWidget(QWidget *parent = nullptr);
    void addVedioWidget(QWidget* widget);
    void setListInfo(QStringList& list);
    void appendListInfo(QStringList& list);
    void setCurrentRow(int index);
    QWidget* getVedioWidget();

protected:
    QHBoxLayout* m_layout;
    QListWidget* m_listwidget;
    QWidget*     m_tempwidget;

    QAction* m_openfile_action;
    QAction* m_opendir_action;
    QAction* m_clear_action;
    QAction* m_hide_action;
    QAction* m_opencamera_action;
    QAction* m_stream_action;
    QMenu*   m_menu;

protected:
    void initUi();
    void initSlot();
    void createAction();

    void contextMenuEvent(QContextMenuEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

protected slots:
    void slot_itemDoubleClicked(QListWidgetItem* item);
    void slot_clearActionTrig();
    void slot_hideActionTrig();

signals:
    void sig_itemDoubleClicked(QString string);
    void sig_doubleClicked();

    void sig_openFileActionTrig();
    void sig_openDirActionTrig();
    void sig_clearActionTrig();
    void sig_hideActionTrig();
    void sig_openCameraActionTrig();
    void sig_openStreamActionTrig();
};

#endif // MIDDLEWIDGET_H
