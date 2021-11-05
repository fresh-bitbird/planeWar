#ifndef MAP_H
#define MAP_H

#include <QPixmap>
#include "config.h"

class Map
{
private:
    QPixmap map1;
    QPixmap map2;

    int map1PosY;
    int map2PosY;

    int mapScrollSpeed;

public:
    Map();
    void mapPosition();
    QPixmap& getMap1()
    { return map1; }
    QPixmap& getMap2()
    { return map2; }
    int& getMap1PosY()
    { return map1PosY; }
    int& getMap2PosY()
    { return map2PosY; }
};

#endif // MAP_H
