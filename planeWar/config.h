#ifndef CONFIG_H
#define CONFIG_H

#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 668
#define GAME_TITLE "飞机大战 0.1"

#define GAME_ICON ":/resource/pic/app.ico"
#define MAP_LEVEL1 ":/resource/pic/img_bg_level_1.jpg"
#define MAP_SCROLL_SPEED 2
#define REFRESH_RATE 10

#define CHARACTER_PLANE_PATH ":/resource/pic/hero2.png"

#define BULLET_PATH ":/resource/pic/bullet_11.png"
#define BULLET_SPEED 5
#define BULLET_NUM 30
#define BULLET_SHOOT_INTERVAL 20

#define ENEMY_PLANE_PATH ":/resource/pic/img-plane_5.png"
#define ENEMY_PLANE_SPEED 3
#define ENEMY_NUM 20
#define ENEMY_INTERVAL 40

#define BOMB_EFFECT_PATH ":/resource/pic/bomb-%1.png"
#define BOMB_NUM 20
#define BOMB_LASTING_EFFECT_NUM 7
#define BOMB_INTERVAL 20

#define AUDIO_BACKGROUND ":/resource/pic/bg.wav"
#define AUDIO_BOMB ":/resource/pic/bomb.wav"


class config
{
public:
    config();
};

#endif // CONFIG_H
