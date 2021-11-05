#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>
#include "config.h"


class EnemyPlane
{
private:
    QPixmap plane;
    int positionX;
    int positionY;
    QRect planeRect;
    int speed;
    bool free;

public:
    EnemyPlane();
    bool isFree()
    { return free; }
    QRect getRect()
    { return planeRect; }
    int getPositionX()
    { return positionX; }
    int getPositionY()
    { return positionY; }
    QPixmap getPlane()
    { return plane; }
    void setFree(bool enable)
    { free = enable; }
    void setPositionX(int x)
    { positionX = x; }
    void setPositionY(int y)
    { positionY = y; }
    void updatePosition();
};

#endif // ENEMYPLANE_H
