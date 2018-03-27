#ifndef MAP_H
#define MAP_H





#include <QObject>





class Map : public QObject
{
public:
    Map();
    //数据
    //颜色矩阵
    int map[8][6];
    //序号矩阵，存储静态的对象序号矩阵
    int id_map[8][6];
    //消除矩阵，存储消除元素矩阵
    int eraze_map[8][6];

    //函数方法
    // 初始化的时候创建新的地图
    void createMap();
    //判断是否存在三消
    bool check();
    //判断选择的两个方块是否能够实现消除
    bool check_chooseright(int x1,int y1,int x2,int y2);

    //




};

#endif // MAP_H
