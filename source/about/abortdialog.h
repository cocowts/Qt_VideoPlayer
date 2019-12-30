#ifndef ABORTDIALOG_H
#define ABORTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>

class AbortDialog : public QDialog
{
    Q_OBJECT

protected:
    QLabel m_logoLbl;
    QLabel m_VersionLbl;

    QLabel m_authotLbl;
    QLabel m_authotUrlLbl;

    QLabel m_homeLbl;
    QLabel m_homeUrlLbl;

    QLabel m_mailLbl;
    QLabel m_mailUrlLbl;

    QPlainTextEdit m_edit;

    QPushButton m_okBtn;

    void initControl();
    void connectSlot();

protected slots:
    void onOKClicked();

public:
    AbortDialog(QWidget* parent);
};

#endif // ABORTDIALOG_H
