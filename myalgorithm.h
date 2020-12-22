#ifndef MYALGORITHM_H
#define MYALGORITHM_H

#include <QObject>
#include "string.h"
#include "time.h"
#include <zbar.h>
#include "opencv2/opencv.hpp"
#include <iostream>
#include "windows.h"
#include "string"
#include "QTextBrowser"
class myAlgorithm : public QObject
{
    Q_OBJECT
public:
    explicit myAlgorithm(QObject *parent = nullptr);

    // 以时间作为图片名 精确到毫秒
    std::string GetTimeAsFileName();
    // 识别二维码 自动识别模式
    cv::Mat  detect_bar_auto(cv::Mat input);

    // 保存结果
    void saveResult(cv::Mat img, std::string path, std::string filename);

    QTextBrowser* message = NULL;
signals:
    void sendMessage(const QString& info);

private:


};

#endif // MYALGORITHM_H
