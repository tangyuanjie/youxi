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
    //����
    Ball * balls[6*8]; //���е�С��
    Map *map; // ���ڴ洢��̬����ɫ����Ϣ
    //��¼�����Ϣ
    int ball_one;
    int ball_two;
    //��������״̬ 0����ֹ״̬��1������״̬
    int mode ;

//��������
    void start();
    void moveballs();
    //��ʱ����
    void wait(int n);

//��ʼ��
//    void  initialize();

public slots:

    void ball_clicked(Ball*); // ����������


};

#endif // SCENE_H
