#include "mainwidget.h"
#include "./ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    initScene();
    setWindowIcon(QIcon(GAME_ICON));
    playGame();
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::initScene()
{
    srand(time(nullptr));
    setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    setWindowTitle(GAME_TITLE);
    timer.setInterval(REFRESH_RATE);
    disappearRecorder = 0;
}

void MainWidget::playGame()
{
    timer.start();
    connect(&timer, &QTimer::timeout, [=](){
        enemyDisappear();updatePosition(); update();collisionDetection();
    });
}

void MainWidget::updatePosition()
{
    map.mapPosition();
    characterPlane.shoot();
    for(int i = 0; i < BULLET_NUM; i++)
    {
        if(!characterPlane.getBullets()[i].isFree())
            characterPlane.getBullets()[i].updatePosition();
    }
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(!enemyPlane[i].isFree())
            enemyPlane[i].updatePosition();
    }
    for(int i = 0; i < BOMB_NUM; i++)
    {
        if(!bombEffects[i].isFree())
            bombEffects[i].updateInfo();
    }
}

void MainWidget::paintEvent(QPaintEvent *painEvent)
{
    QPainter painter(this);
    painter.drawPixmap(0, map.getMap1PosY(), map.getMap1());
    painter.drawPixmap(0, map.getMap2PosY(), map.getMap2());
    painter.drawPixmap(characterPlane.getPositionX(), characterPlane.getPositionY(),
                       characterPlane.getPlane());
    for(int i = 0; i < BULLET_NUM; i++)
        if(!characterPlane.getBullets()[i].isFree())
            painter.drawPixmap(characterPlane.getBullets()[i].getPositionX(),
                               characterPlane.getBullets()[i].getPositionY(),
                               characterPlane.getBullets()[i].getBullet());
    for(int i = 0; i < ENEMY_NUM; i++)
        if(!enemyPlane[i].isFree())
            painter.drawPixmap(enemyPlane[i].getPositionX(),
                               enemyPlane[i].getPositionY(),
                               enemyPlane[i].getPlane());
    for(int i = 0; i < BOMB_NUM; i++)
        if(!bombEffects[i].isFree())
            painter.drawPixmap(bombEffects[i].getPositionX(),
                               bombEffects[i].getPositionY(),
                               bombEffects[i].getBombEffect()[bombEffects[i].getLLoadEffectIndex()]);
}

void MainWidget::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    setMouseTracking(true);
    int x = mouseEvent->x() - characterPlane.getPlaneRect().width() * 0.5;
    int y = mouseEvent->y() - characterPlane.getPlaneRect().height() * 0.5;

    if(x < 0)
        x = 0;
    else if(x > WINDOW_WIDTH - characterPlane.getPlaneRect().width())
        x = WINDOW_WIDTH - characterPlane.getPlaneRect().width();

    if(y < 0)
        y = 0;
    else if(y > WINDOW_HEIGHT - characterPlane.getPlaneRect().height())
        y = WINDOW_HEIGHT - characterPlane.getPlaneRect().height();
    characterPlane.setPosition(x, y);
}

void MainWidget::enemyDisappear()
{

    disappearRecorder++;
    if(disappearRecorder < ENEMY_INTERVAL)
        return;
    disappearRecorder = 0;
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(enemyPlane[i].isFree())
        {
            enemyPlane[i].setFree(false);
            enemyPlane[i].setPositionX(
                        rand() % (WINDOW_WIDTH - enemyPlane[i].getRect().width())
                        );
            enemyPlane[i].setPositionY(-enemyPlane[i].getRect().height());
            break;
        }
    }
}

void MainWidget::collisionDetection()
{
    for(int i = 0; i < ENEMY_NUM; i++)
    {
        if(enemyPlane[i].isFree())
            continue;
        for(int j = 0; j < BULLET_NUM; j++)
        {
            if(characterPlane.getBullets()[j].isFree())
                continue;
            if(enemyPlane[i].getRect().intersects(
                        characterPlane.getBullets()[j].getRect()))
            {
                enemyPlane[i].setFree(true);
                characterPlane.getBullets()[j].setFree(true);
                for(int k = 0; k < BOMB_LASTING_EFFECT_NUM; k++)
                {
                    if(bombEffects[k].isFree())
                    {
                        bombEffects[k].setFree(false);
                        bombEffects[k].setPositionX(enemyPlane[i].getPositionX());
                        bombEffects[k].setPositionY(enemyPlane[i].getPositionY());
                        break;
                    }
                }
            }
        }
    }
}
