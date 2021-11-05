#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    plane.load(ENEMY_PLANE_PATH);
    positionX = 0;
    positionY = 0;
    free = true;
    speed = ENEMY_PLANE_SPEED;
    planeRect.setWidth(plane.width());
    planeRect.setHeight(plane.height());
    planeRect.moveTo(positionX, positionY);
}

void EnemyPlane::updatePosition()
{
    if(free)
        return;
    positionY += speed;
    planeRect.moveTo(positionX, positionY);
    if(positionY > WINDOW_HEIGHT)
        free = true;
}
