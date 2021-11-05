#ifndef BULLET_H
#define BULLET_H

#include "config.h"
#include <QPixmap>
#include <QRect>

class Bullet
{
private:
    QPixmap bullet;
    int positionX;
    int positionY;
    int speed;
    bool free;
    QRect rect;

public:
    Bullet();
    QPixmap getBullet()
    { return bullet; }
    int getPositionX()
    { return positionX; }
    int getPositionY()
    { return positionY; }
    int getSpeed()
    { return speed; }
    bool isFree()
    { return free; }
    QRect getRect()
    { return rect; }
    void setPositionX(int x)
    { positionX = x; }
    void setPositionY(int y)
    { positionY = y; }
    void setFree(bool enable)
    { free = enable;}
    void updatePosition();
};

#endif // BULLET_H
