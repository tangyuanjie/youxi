
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
    //��ͼ
    view = new QGraphicsView();
//    player =  new Player();

    //���� ����Ϸ������
    scene = new Scene();
    //��һ������  ����ʼ������
    scene_start = new Scene_start() ;

    // Ϊ��ͼ���ó���
    view->setScene(scene_start);

    //����
    QHBoxLayout *layout = new QHBoxLayout;
     layout->addWidget(view);

     //�������
     button = new QPushButton(this);
     layout->addWidget(button);

     //�����ڲ���
     QWidget *widget = new QWidget;
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(tr("xiaxiaole"));
//     setFixedSize(this->size());

//�����ź����
     connect(scene_start->item1, SIGNAL(IsPressed()), this, SLOT(start()));//��ʼ��ť
     connect(scene_start->item2, SIGNAL(IsPressed()), this, SLOT(setMode()));//��ť ����
     connect(scene_start->item3, SIGNAL(IsPressed()), this, SLOT(showRank()));//��ť ���а�


}

//�����ʼ�������Ч��
void MainWindow::start()
{
qDebug() << "start";
  view->setScene(scene);//��ʾ��Ϸ����
  scene->start();
//  scene->wait(2000);



}

//����ģʽ
void MainWindow::setMode()
{
qDebug() << "setMode";
}

// ��ʾ���а�
void MainWindow::showRank()
{
qDebug() << "showRank";
}


MainWindow::~MainWindow()
{

}
