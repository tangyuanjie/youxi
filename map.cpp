#include "map.h"
#include <QtGlobal>
#include <QTime>



Map::Map()
{
    createMap();//初始化颜色表

}

//初始化颜色表
void Map::createMap()
{
//     int map[8][6];
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            map[x][y] = qrand()%5 +1;//生成1-5的随机数
        }
    }
}

//判断是否存在三消
bool Map::check()
{
    //
    bool flag = false;
    //记录消除的对象
    int tmap[8][6];
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            tmap[x][y] = 0 ;//初始化表格全为零
        }
    }
    //
    for(int x=0;x<8-2;x++)
    {
        for( int y=0;y<6-2;y++ )
        {
//            tmap[x][y] = 0 ;//初始化表格全为零
            //判断水平方向上是否存在三个，可以消除的全部记作 1
            if (map[x][y] == map[x][y+1] && map[x][y+1] == map[x][y+2] )
            {
                flag = true;
               tmap[x][y] = 1;
               tmap[x][y+1] = 1;
               tmap[x][y+2] = 1;
            }
              //判断竖直方向上是否存在三个
            if (map[x][y] == map[x+1][y] && map[x+1][y] == map[x+2][y] )
            {
                 flag = true;
               tmap[x][y] = 1;
               tmap[x+1][y] = 1;
               tmap[x+2][y] = 1;
            }

        }
    }

        for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            eraze_map[x][y] = tmap[x][y] ;//全为零或者存在1
        }
    }
     return flag;
}


//判断选择的两个方块是否能够实现消除
bool Map::check_chooseright(int x1,int y1,int x2,int y2)
{



return  true;
}







