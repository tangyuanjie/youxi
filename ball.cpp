#include "ball.h"

Ball::Ball(int num)
{
    number  =num ;

     setCursor(Qt::PointingHandCursor);

//    QString str;
//    str.setNum(color);
//    str=QString("../").append(str);
//    str.append(".png");
//    //加载图片
//    QPixmap pixmap;
//    pixmap.load(str);   
//    pixmap= pixmap.scaled(40,40,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    setPixmap(pixmap);
}

void Ball::setcolor(int c)
{
    color  = c ;
    QString str;
    str.setNum(color);
    str=QString("../").append(str);
    str.append(".png");
    //加载图片
    QPixmap pixmap;
    pixmap.load(str);
    pixmap= pixmap.scaled(40,40,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pixmap);

}

// 完成虚函数
QRectF Ball::boundingRect() const
{
    QRect rect = this->pixmap().rect();
    //return QRectF(rect);
    return QRectF(0,0,rect.width(),rect.width()+15);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    QPixmap pixmap = this->pixmap();
    QRect rect = pixmap.rect();
    painter->drawPixmap(rect,pixmap);
}
QPainterPath Ball::shape() const
{
    QRectF rect = boundingRect();
    QPainterPath path;
    path.addRoundRect(rect, 5,5);
    return path;
}

//按键响应 ，发射信号
  void Ball::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
     QGraphicsItem::mousePressEvent(event);
     emit IsPressed(this);
 }
   void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
 setCursor(Qt::OpenHandCursor);
 }



 void Ball :: move(int x,int y)
 {
     this->setPos(x,y);
 }






