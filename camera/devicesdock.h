#ifndef DEVICESDOCK_H
#define DEVICESDOCK_H

#include <QWidget>
#include <QListWidgetItem>
#include "cameramanager.h"

namespace Ui {
class DevicesDock;
}

class DevicesDock : public QWidget
{
    Q_OBJECT

public:
    explicit DevicesDock(QWidget *parent = 0);
    ~DevicesDock();

    QTextBrowser* message = NULL;

private slots:
    void on_btn_search_clicked();

    void handleCameraUpdate(const QStringList &list);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);


public slots:
    // 转接message
    void reciveAndSendMessage(const QString& info);

signals:
    void sigActivated(QString &cameraName);
    void sendMessage(const QString& info);
private:
    Ui::DevicesDock *ui;
    CameraManager *mCameras = NULL;
};

#endif // DEVICESDOCK_H
