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
    //����
    int number; //������ball�е����
    int index_x; //�������е�����ź������
    int index_y;
    int color; //��ɫ

    void setcolor(int c);
    void move(int x,int y);

//virtual function ��Ҫ����ʵ�ֵ��麯��
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
