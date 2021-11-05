#include "bullet.h"

Bullet::Bullet()
{
    bullet.load(BULLET_PATH);
    positionX = WINDOW_WIDTH * 0.5;
    positionY = WINDOW_HEIGHT;
    free = true;
    speed = BULLET_SPEED;
    rect.setWidth(bullet.width());
    rect.setHeight(bullet.height());
    rect.moveTo(positionX, positionY);
}

void Bullet::updatePosition()
{
    if(free)
        return;
    positionY -= speed;
    rect.moveTo(positionX, positionY);
    if(positionY <= -rect.height())
        free = true;
}
