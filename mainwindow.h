#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>



class Player;
 class Scene;
class Scene_start;


 class QAction;
 class QPushButton;
 class QToolBox;
 class QSpinBox;
 class QComboBox;
 class QFontComboBox;
 class QButtonGroup;
 class QLineEdit;
 class QGraphicsTextItem;
 class QFont;
 class QToolButton;
 class QAbstractButton;
 class QGraphicsView;
// class QGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    Player *player;
    Scene *scene;// 游戏正式场景
    Scene_start *scene_start; //开始场景
    QGraphicsView *view;
    QPushButton  *button;


public slots:
    void start();
    void setMode();
    void showRank();

private:
//    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
