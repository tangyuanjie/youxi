#include "scene.h"
#include "ball.h"
#include "map.h"


#include <qdebug.h>
#include <QtGlobal>
#include <QTime>



Scene::Scene()
{
//    addText("Hello, world!");
this->setSceneRect(0,0, 400, 400);
    //������ɫ��
    map = new Map(); //��ʼ����ɫ��


//   ���� balls һ���а�������
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            balls[y + 6*(x) ] = new Ball(y + 6*(x) );//���õ����,0��ʼ
            //id_map ������ű�
            map->id_map[x][y] = y + 6*(x); //����ű��д洢��Ӧ��������
            balls[y + 6*(x) ]->index_x = x; //�����е������
            balls[y + 6*(x) ]->index_y = y; //�����е������
            //����ɫ���ʼ��������ɫ
            balls[y + 6*(x) ]->setcolor(map->map[(balls[y + 6*(x) ]->index_x)][(balls[y + 6*(x) ]->index_y)]);
//          balls[x + 6*(y-1) -1]->setcolor(1);//����ͼƬ
        }
    }

    // �ڳ�������Ӷ�����ʾ
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            this->addItem(balls[y + 6*(x) ]);//��Ӷ���
            balls[y + 6*(x) ]->setPos(y * 40 +80,x*40 + 0); // ����λ��
             //�ź��������
            connect(balls[y + 6*(x) ], SIGNAL(IsPressed(Ball*)), this, SLOT(ball_clicked(Ball*)));//

        }
    }
    //��ʼ�������Ϣ
     ball_one = -1;
     ball_two = -1;
     //
    //��������״̬
    mode = 0 ;//���Ϊ��ֹ״̬

}

void Scene::start()
{

    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
//            this->addItem(balls[y + 6*(x) ]);//��Ӷ���
            balls[y + 6*(x) ]->move(y * 40 +80,x*40 + 0); // ����λ��

        }
    }
    wait(1000);
     for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
//            this->addItem(balls[y + 6*(x) ]);//��Ӷ���
            balls[y + 6*(x) ]->move(y * 40 +80+ 50,x*40 + 0); // ����λ��

        }
    }

    //��ʼ��֮���ж��Ƿ��������
    this->update();
     qDebug() <<map->map;
//     wait(8000);
      qDebug() <<2;
    if (map->check()) //����������������붯��
    {
        //��ʱһ��ʱ��

//        wait(1000);
          this->update();
           qDebug() <<33333;
//          wait(1000);
//        moveballs();
    }
}

// ����������
void Scene::ball_clicked(Ball* b)
{
    // �ж�����״̬��ȷ���Ƿ���Ӧ�����Ϣ
    if ( mode > 0)
            return; //���Ǿ�ֹ״̬�򷵻أ�

    //�����Ӧ
    qDebug() <<b->number;
    if ( ball_one <0 )
            ball_one = b->number;
    else if (ball_two <0  )
    {
        ball_two = b->number;
        // ����λ�ã��ж��ܷ��������ı����״̬
        int x1 = balls[ball_one]->index_x;
        int y1 = balls[ball_one]->index_y;
        int x2 =balls[ball_two]->index_x;
        int y2 = balls[ball_two]->index_y;

        //��������ڵģ�check
        if ( qAbs(x1-x2)+qAbs(y1-y2) == 1 ) // �����ͬ�л���ͬ��
        {
            bool checkble = false;
            checkble = map->check_chooseright(x1,y1,x2,y2);
            if (checkble) //����ܹ����������붯��״̬
                mode =1;
        }

        //��������Ϣ
        ball_one = -1;
        ball_two = -1;
    }

}

//��������
  void Scene :: moveballs()
 {
      //���붯�������ó���״̬Ϊ����״̬
      mode = 1;
 //��ʼ����
      //�������������������
//      map->eraze_map;
//      map->id_map;
      //ÿ������Ҫ�ƶ�������
      int lines[48];
      for (int y=0; y<48; y++)
      {
          lines[y] = 0;
      }
      //
      for (int y=0; y<6; y++)
      {   int num =0;//ÿһ����������ĸ�������
          int first =-1;
          for ( int x=0; x<8; x++)
          {
            if(map->eraze_map[x][y] == 1)//�ҵ����������Ķ���
            {
                num++;
                if (first == -1)
                    first =x;//��¼������Ķ�������
                //�����������ƶ������Ϸ�������������ɫ
                balls[map->id_map[x][y]]->index_x = 0-num;//x���Ϸ�num��
                 qsrand(QTime(0,qrand()%5,0).msecsTo(QTime::currentTime()));//����1-5�������
                balls[map->id_map[x][y]]->setcolor(qrand()%5 +1);//������ɫ
                int px = balls[map->id_map[x][y]]->pos().x();
                balls[map->id_map[x][y]]->setPos(px,0-40*num);
                //
            }
          }
          if (num > 0)//�����������
          {
              for ( int i=0; i<first; i++)  //����Ķ���
                {
                    lines[map->id_map[i][y]] = num;//
                }
              //�����ƶ�������
              for ( int x=0; x<8; x++)
              {
                   if(map->eraze_map[x][y] == 1)//�ҵ����������Ķ���
                   {
                    lines[map->id_map[x][y]] = num;//�Ϸ��Ķ�����Ҫ�ƶ��ľ���
                   }
              }
          }

      }


      //���������Ҫ�ƶ��Ķ���
      //�����ƶ�������Ҫ�ƶ��ľ���,Ҫ����idmap



      //����

      //��¼�µı��


      //�ٴ��ж��Ƿ������





  }

//��ʱnum����
    void Scene ::wait(int num)
    {
        QTime n=QTime::currentTime();
        QTime now;
        do{
//          qDebug()<<"jjmm";
          now=QTime::currentTime();
     }   while (n.msecsTo(now)<=num);

    }












