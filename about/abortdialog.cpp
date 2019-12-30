#include "abortdialog.h"
#include <QPalette>
#include <QPixmap>

AbortDialog::AbortDialog(QWidget* parent) : QDialog(parent, Qt::Drawer | Qt::Desktop)
{
    initControl();
    connectSlot();
}

void AbortDialog::initControl()
{
    QPixmap pm(":/pic/about/pic/about.png");

    pm = pm.scaled(84, 88, Qt::KeepAspectRatio);

    m_logoLbl.setParent(this);
    m_logoLbl.setPixmap(pm);
    m_logoLbl.move(14, 19);
    m_logoLbl.resize(84, 88);

    m_VersionLbl.setParent(this);
    m_VersionLbl.move(115, 29);
    m_VersionLbl.resize(218, 20);
    m_VersionLbl.setText("简播放  v1.0.0.10 (32-bit) ");

    m_authotLbl.setParent(this);
    m_authotLbl.move(44, 132);
    m_authotLbl.resize(54, 20);
    m_authotLbl.setText("作 者 ：");

    m_authotUrlLbl.setParent(this);
    m_authotUrlLbl.move(127, 132);
    m_authotUrlLbl.resize(113, 20);
    m_authotUrlLbl.setText("TianSong");

    m_mailLbl.setParent(this);
    m_mailLbl.move(44, 162);
    m_mailLbl.resize(81, 19);
    m_mailLbl.setText("邮 箱 ：");

    m_mailUrlLbl.setParent(this);
    m_mailUrlLbl.move(127, 162);
    m_mailUrlLbl.resize(146, 19);
    m_mailUrlLbl.setText("1508539502@qq.com");

    m_homeLbl.setParent(this);
    m_homeLbl.move(44, 199);
    m_homeLbl.resize(81, 19);
    m_homeLbl.setText("主 页 ：");

    m_homeUrlLbl.setParent(this);
    m_homeUrlLbl.move(127, 199);
    m_homeUrlLbl.resize(235, 19);
    m_homeUrlLbl.setOpenExternalLinks(true);
    m_homeUrlLbl.setText("<a href=\"https://segmentfault.com/u/tiansong\">https://segmentfault.com/u/tiansong");

    m_okBtn.setParent(this);
    m_okBtn.move(156, 379);
    m_okBtn.resize(88, 24);
    m_okBtn.setText("确定");

    m_edit.setParent(this);
    m_edit.move(24, 235);
    m_edit.resize(377, 115);
    m_edit.setReadOnly(true);
    m_edit.insertPlainText("开发平台: Qt 5.12.1\n\n构建时间: 2019.05.11 - 20:18:41\n\n"
                           "开源计划: https://segmentfault.com/u/tiansong\n\n"
                           "Copyright © 2018-2019 TianSong");

    QPalette p = palette();
    p.setColor(QPalette::Active, QPalette::Background, Qt::white);
    p.setColor(QPalette::Inactive, QPalette::Background, Qt::white);
    setPalette(p);

    setWindowTitle("关于");
    setFixedSize(420, 427);
}

void AbortDialog::connectSlot()
{
    connect(&m_okBtn, SIGNAL(clicked()), this, SLOT(onOKClicked()));
}

void AbortDialog::onOKClicked()
{
    close();
}
