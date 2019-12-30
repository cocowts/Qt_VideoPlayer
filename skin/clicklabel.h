#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QLabel>

class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *e);

signals:
    void clicked();
};

#endif // CLICKLABEL_H
