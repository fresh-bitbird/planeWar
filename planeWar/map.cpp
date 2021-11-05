#include "map.h"

Map::Map()
{
    map1.load(MAP_LEVEL1);
    map2.load(MAP_LEVEL1);

    map1PosY = -WINDOW_HEIGHT;
    map2PosY = 0;

    mapScrollSpeed = MAP_SCROLL_SPEED;
}

void Map::mapPosition()
{
    map1PosY += mapScrollSpeed;
    if(map1PosY >= 0)
        map1PosY = -WINDOW_HEIGHT;

    map2PosY += mapScrollSpeed;
    if(map2PosY >= WINDOW_HEIGHT)
        map2PosY = 0;
}
