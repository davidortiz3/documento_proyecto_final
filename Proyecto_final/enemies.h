#ifndef ENEMIES_H
#define ENEMIES_H

#include <QObject>
#include <QPointF>
#include "Physics.h"
//#include "personaje.h"

class Character;

class Enemies : public QObject {
    Q_OBJECT

public:
    enum Type { Minion = 50, MegaMinion = 75, Boss = 100 };  // Tipos de enemigos con su respectiva vida

    Enemies(Type type, Character* mainCharacter, Physics* physics);  // Agregar un puntero a Physics en el constructor

    void move();  // Función para mover al enemigo
    void jump();  // Función para hacer saltar al enemigo
    void chase(QPointF playerPos);  // Función para perseguir al personaje principal
    void attack();  // Función para atacar cuerpo a cuerpo
    void specialAttack();
signals:
    void enemyDied(Enemies* enemy);  // Señal que se emite cuando el enemigo muere

private:
    QPointF position;  // Posición del enemigo
    Character* mainCharacter;
    Physics* physics;  // Puntero a la clase Physics
    float speed;  // Velocidad del enemigo
    float range;  // Rango de detección del enemigo
    float leftLimit;  // Límite izquierdo del movimiento
    float rightLimit;  // Límite derecho del movimiento
    bool movingRight;  // Dirección del movimiento
    int health;  // Vida del enemigo
    int damage;  // Daño que hace el enemigo
};

#endif // ENEMIES_H
