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
    //生成颜色表
    map = new Map(); //初始化颜色表


//   生成 balls 一共有八行六列
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            balls[y + 6*(x) ] = new Ball(y + 6*(x) );//设置的序号,0开始
            //id_map 更新序号表
            map->id_map[x][y] = y + 6*(x); //在序号表中存储对应对象的序号
            balls[y + 6*(x) ]->index_x = x; //矩阵中的行序号
            balls[y + 6*(x) ]->index_y = y; //矩阵中的列序号
            //由颜色表初始化对象颜色
            balls[y + 6*(x) ]->setcolor(map->map[(balls[y + 6*(x) ]->index_x)][(balls[y + 6*(x) ]->index_y)]);
//          balls[x + 6*(y-1) -1]->setcolor(1);//设置图片
        }
    }

    // 在场景中添加对象，显示
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            this->addItem(balls[y + 6*(x) ]);//添加对象
            balls[y + 6*(x) ]->setPos(y * 40 +80,x*40 + 0); // 设置位置
             //信号与槽连接
            connect(balls[y + 6*(x) ], SIGNAL(IsPressed(Ball*)), this, SLOT(ball_clicked(Ball*)));//

        }
    }
    //初始化点击信息
     ball_one = -1;
     ball_two = -1;
     //
    //程序运行状态
    mode = 0 ;//最初为静止状态

}

void Scene::start()
{

    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
//            this->addItem(balls[y + 6*(x) ]);//添加对象
            balls[y + 6*(x) ]->move(y * 40 +80,x*40 + 0); // 设置位置

        }
    }
    wait(1000);
     for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
//            this->addItem(balls[y + 6*(x) ]);//添加对象
            balls[y + 6*(x) ]->move(y * 40 +80+ 50,x*40 + 0); // 设置位置

        }
    }

    //初始化之后判断是否可以消除
    this->update();
     qDebug() <<map->map;
//     wait(8000);
      qDebug() <<2;
    if (map->check()) //如果可以消除，进入动画
    {
        //延时一段时间

//        wait(1000);
          this->update();
           qDebug() <<33333;
//          wait(1000);
//        moveballs();
    }
}

// 对象点击处理
void Scene::ball_clicked(Ball* b)
{
    // 判断运行状态，确定是否响应点击信息
    if ( mode > 0)
            return; //不是静止状态则返回；

    //点击响应
    qDebug() <<b->number;
    if ( ball_one <0 )
            ball_one = b->number;
    else if (ball_two <0  )
    {
        ball_two = b->number;
        // 交换位置，判断能否消除，改变程序状态
        int x1 = balls[ball_one]->index_x;
        int y1 = balls[ball_one]->index_y;
        int x2 =balls[ball_two]->index_x;
        int y2 = balls[ball_two]->index_y;

        //如果是相邻的，check
        if ( qAbs(x1-x2)+qAbs(y1-y2) == 1 ) // 如果是同行或者同列
        {
            bool checkble = false;
            checkble = map->check_chooseright(x1,y1,x2,y2);
            if (checkble) //如果能够消除，进入动画状态
                mode =1;
        }

        //清除点击信息
        ball_one = -1;
        ball_two = -1;
    }

}

//动画操作
  void Scene :: moveballs()
 {
      //进入动画，设置程序状态为动画状态
      mode = 1;
 //开始动画
      //获得所有消除对象的序号
//      map->eraze_map;
//      map->id_map;
      //每个对象要移动的行数
      int lines[48];
      for (int y=0; y<48; y++)
      {
          lines[y] = 0;
      }
      //
      for (int y=0; y<6; y++)
      {   int num =0;//每一列消除对象的个数计数
          int first =-1;
          for ( int x=0; x<8; x++)
          {
            if(map->eraze_map[x][y] == 1)//找到可以消除的对象
            {
                num++;
                if (first == -1)
                    first =x;//记录最上面的对象行数
                //将消除对象移动到最上方，【】更新颜色
                balls[map->id_map[x][y]]->index_x = 0-num;//x轴上方num行
                 qsrand(QTime(0,qrand()%5,0).msecsTo(QTime::currentTime()));//生成1-5的随机数
                balls[map->id_map[x][y]]->setcolor(qrand()%5 +1);//更新颜色
                int px = balls[map->id_map[x][y]]->pos().x();
                balls[map->id_map[x][y]]->setPos(px,0-40*num);
                //
            }
          }
          if (num > 0)//如果有消除的
          {
              for ( int i=0; i<first; i++)  //上面的对象
                {
                    lines[map->id_map[i][y]] = num;//
                }
              //计算移动的行数
              for ( int x=0; x<8; x++)
              {
                   if(map->eraze_map[x][y] == 1)//找到可以消除的对象
                   {
                    lines[map->id_map[x][y]] = num;//上方的对象需要移动的距离
                   }
              }
          }

      }


      //获得所有需要移动的对象
      //计算移动对象需要移动的距离,要更新idmap



      //动画

      //记录新的表格


      //再次判断是否可消除





  }

//延时num毫秒
    void Scene ::wait(int num)
    {
        QTime n=QTime::currentTime();
        QTime now;
        do{
//          qDebug()<<"jjmm";
          now=QTime::currentTime();
     }   while (n.msecsTo(now)<=num);

    }












