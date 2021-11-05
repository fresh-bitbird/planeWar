#include "bombeffect.h"

BombEffect::BombEffect()
{
    for(int i = 1; i <= BOMB_LASTING_EFFECT_NUM; i++)
    {
        QString path = QString(BOMB_EFFECT_PATH).arg(i);
        bombEffect.push_back(QPixmap(path));
    }
    positionX = 0;
    positionY = 0;
    free = true;
    intervalRecorder = 0;
    loadEffectIndex = 0;
}

void BombEffect::updateInfo()
{
    if(free)
        return;
    intervalRecorder++;
    if(intervalRecorder < BOMB_INTERVAL)
        return;
    intervalRecorder = 0;
    loadEffectIndex++;
    if(loadEffectIndex > BOMB_LASTING_EFFECT_NUM - 1)
    {
        loadEffectIndex = 0;
        free = true;
    }
}
