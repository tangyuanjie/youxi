#include "map.h"
#include <QtGlobal>
#include <QTime>



Map::Map()
{
    createMap();//��ʼ����ɫ��

}

//��ʼ����ɫ��
void Map::createMap()
{
//     int map[8][6];
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            map[x][y] = qrand()%5 +1;//����1-5�������
        }
    }
}

//�ж��Ƿ��������
bool Map::check()
{
    //
    bool flag = false;
    //��¼�����Ķ���
    int tmap[8][6];
    for(int x=0;x<8;x++)
    {
        for( int y=0;y<6;y++ )
        {
            tmap[x][y] = 0 ;//��ʼ�����ȫΪ��
        }
    }
    //
    for(int x=0;x<8-2;x++)
    {
        for( int y=0;y<6-2;y++ )
        {
//            tmap[x][y] = 0 ;//��ʼ�����ȫΪ��
            //�ж�ˮƽ�������Ƿ��������������������ȫ������ 1
            if (map[x][y] == map[x][y+1] && map[x][y+1] == map[x][y+2] )
            {
                flag = true;
               tmap[x][y] = 1;
               tmap[x][y+1] = 1;
               tmap[x][y+2] = 1;
            }
              //�ж���ֱ�������Ƿ��������
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
            eraze_map[x][y] = tmap[x][y] ;//ȫΪ����ߴ���1
        }
    }
     return flag;
}


//�ж�ѡ������������Ƿ��ܹ�ʵ������
bool Map::check_chooseright(int x1,int y1,int x2,int y2)
{



return  true;
}







