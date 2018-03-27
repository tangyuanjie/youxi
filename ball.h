#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

#include   <QGraphicsSimpleTextItem>

  

class Ball : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Ball(int num );
    //属性
    int number; //在所有ball中的序号
    int index_x; //在网格中的行序号和列序号
    int index_y;
    int color; //颜色

    void setcolor(int c);
    void move(int x,int y);

//virtual function 需要重新实现的虚函数
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;



signals:
//    void nodeIsMoving(QPointF &pos);
    void IsPressed(Ball*);
//    void nodeIsRelease();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent ( QGraphicsSceneMouseEvent *event ) ;



};

#endif // BALL_H
