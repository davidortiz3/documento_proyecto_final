#ifndef ENEMIES_H
#define ENEMIES_H

#include <QObject>
#include <QPointF>
#include "fisicas.h"
#include "personaje.h"
#include "sprites.h"

class Personaje;

class Enemies : public QObject, public fisicas {
    Q_OBJECT

public:
    enum Type { Minion = 50, MegaMinion = 75, Boss = 100 };

    Enemies(Type type, Personaje* personaje, fisicas* fisicas);
    void move();
    void jump();
    void chase(QPointF playerPos);
    void attack();
    void specialAttack();
    void updateHealth(int damageTaken);  // Corregido el nombre de la función
    void set_animations();
    QPixmap getCurrentPixmap();
    QRect set_complete_sprites();  // Añadida la función faltante

signals:
    void enemyDied(Enemies* enemy);

private:
    QPointF position;
    Personaje* mainCharacter;  // Cambiado de 'personaje' a 'mainCharacter'
    fisicas* physics;  // Cambiado de 'fisicas' a 'physics'
    sprites* spriteManager;  // Cambiado de 'sprites' a 'spriteManager'
    float speed;
    float range;
    float leftLimit;
    float rightLimit;
    bool movingRight;
    int health;
    int damage;
    int attackRange;  // Añadida la variable faltante
};

#endif // ENEMIES_H
