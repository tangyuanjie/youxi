#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

#include   <QGraphicsSimpleTextItem>



class Item : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Item(int n);
    int n;

//virtual function
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;
    void  sendsignal();

signals:
//    void nodeIsMoving(QPointF &pos);
    void IsPressed();
//    void nodeIsRelease();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent ( QGraphicsSceneMouseEvent *event ) ;

//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

//    setCursor(Qt::OpenHandCursor);

};

#endif // ITEM_H
