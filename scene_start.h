#ifndef SCENE_START_H
#define SCENE_START_H

#include <QGraphicsScene>

#include "item.h"

//class Player;
class Item;


class Scene_start : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene_start( );

//    Player * player;
    Item * item1 ;
    Item * item2 ;
    Item * item3 ;

    QGraphicsSimpleTextItem *pItem[3] ;
    QGraphicsSimpleTextItem *name;


public slots:
//    void item_clicked();

//    void increaseCount();

signals:
//    void gamestart();
//    void setmode();
//    void showrank();
};

#endif // SCENE_START_H
