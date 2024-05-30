#ifndef ENEMIES_H
#define ENEMIES_H

#include <QGraphicsPixmapItem>
#include <QPointF>
#include "fisicas.h"
#include "sprites.h"
#include "escenario.h"
#include "obstaculo.h"
#include "proyectil.h"
#include "personaje.h"

#define enemies_x_size 33
#define enemies_y_size 50

class Enemies : public QGraphicsPixmapItem, public fisicas {
public:
    enum Type { Minion, MegaMinion, Boss };

    Enemies(int z, int l, int h);
    ~Enemies();
    void mover_derecha();
    void moveItem(const QPointF& direction, QGraphicsScene* scene);
    void move();
    void jump();
    void chase(personaje *player);
    void attack(personaje *player);
    void updateHealth(int damageTaken);
    void specialAttack(personaje *player);
    QRect set_complete_sprites();
    void set_animations();
    void set_left_animation();
    void set_right_animation();
    void set_up_animation();
    void set_down_animation();
    void set_death_animation();

signals:
    void enemyDied(Enemies* enemy);

private:
    int z, l;
    int health;
    int damage;
    bool movingRight = true;
    bool onGround = true;
    int attackRange = 5;
    int rightLimit = 20;
    int leftLimit = 0;
    int range = 10;
    personaje *player;
    sprites* pixmap_management;
};

#endif // ENEMIES_H
