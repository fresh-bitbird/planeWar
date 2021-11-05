#ifndef CHARACTERPLANE_H
#define CHARACTERPLANE_H

#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"

class CharacterPlane
{

private:
    QPixmap plane;
    int positionX;
    int positionY;
    QRect planeRect;
    Bullet bullets[BULLET_NUM];
    int shootIntervalRecorder;

public:
    CharacterPlane();
    void shoot();
    void setPosition(int x, int y);
    QPixmap getPlane()
    { return plane; }
    int getPositionX()
    { return positionX; }
    int getPositionY()
    { return positionY; }
    QRect getPlaneRect()
    { return planeRect; }
    Bullet* getBullets()
    { return bullets;}
};

#endif // CHARACTERPLANE_H
