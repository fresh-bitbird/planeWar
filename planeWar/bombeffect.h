#ifndef BOMBEFFECT_H
#define BOMBEFFECT_H

#include <QPixmap>
#include <QVector>
#include "config.h"

class BombEffect
{
private:
    QVector<QPixmap> bombEffect;
    int positionX;
    int positionY;
    bool free;
    int intervalRecorder;
    int loadEffectIndex;

public:
    BombEffect();
    QVector<QPixmap> getBombEffect()
    { return bombEffect; }
    bool isFree()
    { return free; }
    int getPositionX()
    { return positionX; }
    int getPositionY()
    { return positionY; }
    int getLLoadEffectIndex()
    { return loadEffectIndex; }
    void setFree(bool enable)
    { free = enable; }
    void setPositionX(int x)
    { positionX = x; }
    void setPositionY(int y)
    { positionY = y; }
    void updateInfo();
};

#endif // BOMBEFFECT_H
