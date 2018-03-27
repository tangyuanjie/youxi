
 #include <QtGui>
 #include <QLabel>
#include <QPushButton>

#include "mainwindow.h"
//#include "ui_mainwindow.h"


#include "scene_start.h"
#include "scene.h"

#include <qdebug.h>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //视图
    view = new QGraphicsView();
//    player =  new Player();

    //场景 【游戏场景】
    scene = new Scene();
    //另一个场景  【开始场景】
    scene_start = new Scene_start() ;

    // 为视图设置场景
    view->setScene(scene_start);

    //布局
    QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(view);

     //其他物件
     button = new QPushButton(this);
     layout->addWidget(button);

     //主窗口部件
     QWidget *widget = new QWidget;
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(tr("xiaxiaole"));
//     setFixedSize(this->size());

//连接信号与槽
     connect(scene_start->item1, SIGNAL(IsPressed()), this, SLOT(start()));//开始按钮
     connect(scene_start->item2, SIGNAL(IsPressed()), this, SLOT(setMode()));//按钮 设置
     connect(scene_start->item3, SIGNAL(IsPressed()), this, SLOT(showRank()));//按钮 排行榜


}

//点击开始按键后的效果
void MainWindow::start()
{
qDebug() << "start";
  view->setScene(scene);//显示游戏场景
  scene->start();
//  scene->wait(2000);



}

//设置模式
void MainWindow::setMode()
{
qDebug() << "setMode";
}

// 显示排行榜
void MainWindow::showRank()
{
qDebug() << "showRank";
}


MainWindow::~MainWindow()
{

}
