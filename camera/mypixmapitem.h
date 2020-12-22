#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H
#include <QGraphicsPixmapItem>
#include "QTextBrowser"

class MyPixmapItem : public QGraphicsPixmapItem
{
public:
    enum { Type = UserType + 5 };

    MyPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent = nullptr);

    int type() const override { return Type; }

    QTextBrowser* message;
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void sendMessage(const QString& info);
};

#endif // MYPIXMAPITEM_H
