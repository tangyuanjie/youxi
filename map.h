#ifndef MAP_H
#define MAP_H





#include <QObject>





class Map : public QObject
{
public:
    Map();
    //����
    //��ɫ����
    int map[8][6];
    //��ž��󣬴洢��̬�Ķ�����ž���
    int id_map[8][6];
    //�������󣬴洢����Ԫ�ؾ���
    int eraze_map[8][6];

    //��������
    // ��ʼ����ʱ�򴴽��µĵ�ͼ
    void createMap();
    //�ж��Ƿ��������
    bool check();
    //�ж�ѡ������������Ƿ��ܹ�ʵ������
    bool check_chooseright(int x1,int y1,int x2,int y2);

    //




};

#endif // MAP_H
