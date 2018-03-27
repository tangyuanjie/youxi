#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Ball;
class Map;


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    //对象
    Ball * balls[6*8]; //所有的小球
    Map *map; // 用于存储静态的颜色表信息
    //记录点击信息
    int ball_one;
    int ball_two;
    //程序运行状态 0：静止状态，1：动画状态
    int mode ;

//动画处理
    void start();
    void moveballs();
    //延时函数
    void wait(int n);

//初始化
//    void  initialize();

public slots:

    void ball_clicked(Ball*); // 对象点击处理


};

#endif // SCENE_H
