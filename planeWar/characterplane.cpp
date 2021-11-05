#include "characterplane.h"

CharacterPlane::CharacterPlane()
{
    plane.load(CHARACTER_PLANE_PATH);
    positionX = WINDOW_WIDTH * 0.5 - plane.width() * 0.5;
    positionY = WINDOW_HEIGHT - plane.height();

    planeRect.setWidth(plane.width());
    planeRect.setHeight(plane.height());
    planeRect.moveTo(positionX, positionY);
    shootIntervalRecorder = 0;
}

void CharacterPlane::setPosition(int x, int y)
{
    positionX = x;
    positionY = y;
    planeRect.moveTo(positionX, positionY);
}

void CharacterPlane::shoot()
{
    shootIntervalRecorder++;
    if(shootIntervalRecorder < BULLET_SHOOT_INTERVAL)
        return;
    shootIntervalRecorder = 0;
    for(int i = 0; i < BULLET_NUM; i++)
    {
        if(bullets[i].isFree())
        {
            bullets[i].setFree(false);
            bullets[i].setPositionX(positionX + planeRect.width() * 0.5
                                    - bullets[i].getRect().width() * 0.5);
            bullets[i].setPositionY(positionY);
            break;
        }
    }
}
