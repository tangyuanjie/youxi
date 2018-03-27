#include "item.h"

#include <QPixmap>
#include <QString>

Item::Item(int num)
{
    n =num;
      QPixmap pixmap;
      QString str[3];
      str[0] = "../start.png";

      str[1] = "../set.png";
      str[2] = "../rank.png";

    pixmap.load(str[n]);


    pixmap= pixmap.scaled(40,40,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    setPixmap(pixmap);

    setCursor(Qt::PointingHandCursor);


}


QRectF Item::boundingRect() const
{
    QRect rect = this->pixmap().rect();
    //return QRectF(rect);
    return QRectF(0,0,rect.width(),rect.width()+15);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    QPixmap pixmap = this->pixmap();
    QRect rect = pixmap.rect();

    painter->drawPixmap(rect,pixmap);

//
//    //print name,calculate the text's heigh & width for center layout
//    QPen pen(Qt::black);
//    painter->setPen(pen);
//    painter->setRenderHint(QPainter::Antialiasing);
//    QFont font("Verdana",8, QFont::Normal);
//    painter->setFont(font);
//    painter->drawText(QRectF(0,rect.height(),rect.width(),15),Qt::AlignCenter,myText);
//
//    if (option->state & QStyle::State_Sunken)
//    {
//        QRectF rect1 = boundingRect();
//        //QPen pen(Qt::darkGreen);
//        painter->setPen(QPen(Qt::darkGreen));
//        painter->drawRoundRect(rect1, 10,10);
//    }else
//    {
//
//    }
}
QPainterPath Item::shape() const
{
    QRectF rect = boundingRect();

    QPainterPath path;
    path.addRoundRect(rect, 5,5);
    return path;
}

 void Item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
 {
 setCursor(Qt::OpenHandCursor);
 }

  void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
 {
// setCursor(Qt::OpenHandCursor);
//      update();
     QGraphicsItem::mousePressEvent(event);
//     emit IsPressed(2);
     sendsignal();

 }

  //发射按键按下的信号
      void  Item::sendsignal()
      {
          emit IsPressed();
      }







