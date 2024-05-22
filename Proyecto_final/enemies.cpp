#include "Enemies.h"
#include "Physics.h"
#include <cmath>

Enemies::Enemies(Type type, Character* mainCharacter, Physics* physics)
    : mainCharacter(mainCharacter),
    position(0, 0),
    speed(1.0),
    range(100.0),
    leftLimit(-100.0),
    rightLimit(100.0),
    movingRight(true),
    physics(physics)
{

    case Minion:
        health = 50;
        damage = 2;
        break;
    case MegaMinion:
        health = 75;
        damage = 2;
        break;
    case Boss:
        health = 100;
        damage = 3;
        break;
}

void Enemies::move() {
    if (movingRight) {
        position.setX(position.x() + speed);
        physics->applyFriction(speed);
        if (position.x() > rightLimit) {
            movingRight = false;
        }
    } else {
        position.setX(position.x() - speed);
        physics->applyFriction(speed);
        if (position.x() < leftLimit) {
            movingRight = true;
        }
    }
}

void Enemies::jump() {
    float velocityY = 0;
    physics->applyGravity(velocityY);
    position.setY(position.y() + velocityY);
}

void Enemies::chase(QPointF playerPos) {
    float dx = playerPos.x() - position.x();
    float dy = playerPos.y() - position.y();
    float distance = std::sqrt(dx*dx + dy*dy);

    if (distance < range) {
        position.setX(position.x() + speed * dx / distance);
        position.setY(position.y() + speed * dy / distance);
        if (dy > 0) {
            jump();
        }
    }
}
void Enemies::attack() {
    float dx = mainCharacter->posX - position.x();
    float dy = mainCharacter->posY - position.y();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance < attackRange) {
        mainCharacter->reduceHealth(damage);
    }
}
void Enemies::updateHealth(int damageTaken) {
    health -= damageTaken;
    if (health <= 0) {
        emit enemyDied(this);
    }
}
void Enemies::specialAttack() {
    float dx = mainCharacter->posX - position.x();
    float dy = mainCharacter->posY - position.y();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance < attackRange) {
        int specialDamage = (health == 100) ? 5 : 0;
        mainCharacter->reduceHealth(specialDamage);
    }
}
