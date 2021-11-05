#ifndef MAINWIDGET_H
#define MAINWIDGET_H

//#include <QtMultimedia/QSoundEffect>

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <random>
#include <ctime>
#include <QUrl>
#include "config.h"
#include "map.h"
#include "characterplane.h"
#include "enemyplane.h"
#include "bombeffect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void initScene();
    void playGame();
    void updatePosition();
    void paintEvent(QPaintEvent* painEvent);
    void mouseMoveEvent(QMouseEvent* mouseEvent);
    void enemyDisappear();
    void collisionDetection();

private:
    Ui::MainWidget *ui;
    QTimer timer;
    Map map;
    CharacterPlane characterPlane;
    EnemyPlane enemyPlane[ENEMY_NUM];
    int disappearRecorder;
    BombEffect bombEffects[BOMB_NUM];
};
#endif // MAINWIDGET_H
