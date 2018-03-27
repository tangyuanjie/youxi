#include "scene_start.h"
//#include "player.h"
#include "item.h"

Scene_start::Scene_start(  )
{
//    addText("Start!");
    this->setSceneRect(0, 0, 400, 400);

    item1 = new Item(0);
    item2 = new Item(1);
    item3 = new Item(2);

    this->addItem(item1);
    this->addItem(item2);
    this->addItem(item3);

   item1->setPos(180+40+20,150);
   item2->setPos(180+40+20,150+40+20);
   item3->setPos(180+40+20,150+80+40);
   //
//   (QGraphicsSimpleTextItem *)pItem[3] ;

   name= new QGraphicsSimpleTextItem();
   pItem[0]= new QGraphicsSimpleTextItem();
   pItem[1]= new QGraphicsSimpleTextItem();
   pItem[2]= new QGraphicsSimpleTextItem();

   name->setText(QString::fromLocal8Bit("消消乐游戏"));
   pItem[0]->setText(QString::fromLocal8Bit("开始游戏"));
   pItem[1]->setText(QString::fromLocal8Bit("模式设置"));
   pItem[2]->setText(QString::fromLocal8Bit("游戏排行"));

    // 字体
    QFont font = pItem[0]->font();
    font.setPixelSize(35);  // 像素大小
    //font.setItalic(true);  // 斜体
//    font.setUnderline(true);  // 下划线
    name->setFont(font);
    pItem[0]->setFont(font);
    pItem[1]->setFont(font);
    pItem[2]->setFont(font);
    name->setBrush(QBrush(QColor(0, 120, 230)));
    pItem[0]->setBrush(QBrush(QColor(0, 0, 0)));
    pItem[1]->setBrush(QBrush(QColor(0, 0, 0)));
    pItem[2]->setBrush(QBrush(QColor(0, 0, 0)));


    //    pItem->setBrush(QBrush(QColor(0, 160, 230)));
    this ->addItem(name);
    this ->addItem(pItem[0]);
    this ->addItem(pItem[1]);
    this ->addItem(pItem[2]);
    //pItem[0]->setPos(180,150+40);
    name->setPos(180-160+60+10,150-60);
    pItem[0]->setPos(180-160+60,150);
    pItem[1]->setPos(180-160+60,150+40+20);
    pItem[2]->setPos(180-160+60,150+80+40);

    //连接信号与槽



}
