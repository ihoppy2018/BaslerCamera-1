#pragma execution_character_set("utf-8")
#include "devicesdock.h"
#include "ui_devicesdock.h"
#include <QDebug>
#include "camerawindow.h"

DevicesDock::DevicesDock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DevicesDock),
    mCameras(CameraManager::getInstance())
{
    ui->setupUi(this);
    connect(mCameras, &CameraManager::sigCameraUpdate, this, &DevicesDock::handleCameraUpdate);

    // 获取parent 的message ui指针
    CameraWindow *ptr = (CameraWindow*)parentWidget();
    message = ptr->mmessage;
    mCameras->message = ptr->mmessage;
    (message == NULL)? (qDebug() << "message is null") : (qDebug() << "message is noNUll"<< message);

    // 信号槽 message
    connect(mCameras, &CameraManager::sendMessage, this, &DevicesDock::reciveAndSendMessage);
}

DevicesDock::~DevicesDock()
{
    qDebug() << "~DevicesDock";
    delete mCameras;
    delete ui;
}

void DevicesDock::on_btn_search_clicked()
{
    mCameras->searchCameras();
    // 发送消息的两种方式 1.指针传递 2.信号槽机制
    message->append("start find device ");
    emit sendMessage("start find device (signals and slots)");
}

void DevicesDock::handleCameraUpdate(const QStringList &list)
{
    ui->listWidget->clear();
    ui->listWidget->addItems(list);
}

void DevicesDock::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
//    qDebug() << "itemDoubleClicked" << item->text();
//    QString friendName = item->text();

//    mCameras->openCamera(friendName);
}

void DevicesDock::on_listWidget_itemClicked(QListWidgetItem *item)
{
    qDebug() << "itemClicked" << item->text();
    QString str = item->text();
    emit sigActivated(str);
}

void DevicesDock::reciveAndSendMessage(const QString& info)
{
    emit sendMessage(info);
}

