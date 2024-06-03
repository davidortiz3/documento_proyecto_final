#ifndef FINAL_BOSS_H
#define FINAL_BOSS_H
#include <QGraphicsPixmapItem>
#include <QPointF>
#include "fisicas.h"
#include "sprites.h"
#include "enemies.h"
#include "escenario.h"
#include "obstaculo.h"
#include "proyectil.h"
#include "personaje.h"

#define bossfinal_x_size 33
#define bossfinal_y_size 50

class Final_boss: public QGraphicsPixmapItem, public enemies {
public:
    Final_boss();
    ~Final_boss();
    void attackSpecialBoss(personaje *player);
    void megaJump(int jumpHeight);
    void attack1(personaje *player);
    void attack2(personaje *player);
    void special1(personaje *player);
    void special2(personaje *player);
    void set_animations();
    void set_left_animation();
    void set_right_animation();
    void set_up_animation();
    void set_down_animation();
    void set_death_animation();
    void set_complete_sprites();
    void start_move();
private:
    int rangeAttack;
    int rangeVision;
    int rangeSpecials;
    personaje *player;
    QTimer *timer_boss;
};
#endif // FINAL_BOSS_H
