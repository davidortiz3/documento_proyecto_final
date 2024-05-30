#include "enemies.h"
#include <cmath>

Enemies::Enemies(int z, int l, int h) : fisicas(z, l, h, this), player(player) {
    this->z = z;
    this->l = l;
    pixmap_management = new sprites(":/soldado/pngfind.com-metal-slug-png-4743164.png", 1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(enemies_x_size, enemies_y_size);

    set_animations();

    setPixmap(pixmap_management->get_current_pixmap(3));
    setX(0);
    setY(0);
}
    /*
    {

        switch (type) {
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
        }*/
    //}

Enemies::~Enemies()
{
    delete pixmap_management;

}

QRect Enemies::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(23*enemies_y_size);
    dim.setWidth(23*enemies_x_size);

    return dim;
}

void Enemies::set_animations()
{
    set_left_animation();
    set_right_animation();
    set_up_animation();
    set_down_animation();
    set_death_animation();
}

void Enemies::set_left_animation()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(6*enemies_x_size);
    pixmap_management->add_new_animation(dim,6);
}

void Enemies::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(8.5*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(12*enemies_x_size);

    pixmap_management->add_new_animation(dim,12);
}


void Enemies::set_up_animation()
{
    QRect dim;

    dim.setX(3*enemies_x_size);
    dim.setY(1*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(3*enemies_x_size);

    pixmap_management->add_new_animation(dim,4);
}

void Enemies::set_down_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(323);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(enemies_x_size);

    pixmap_management->add_new_animation(dim,13);
}

void Enemies::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(3.2*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(29*enemies_x_size);

    pixmap_management->add_new_animation(dim,7);
}

void Enemies::moveItem(const QPointF& direction, QGraphicsScene* scene) {
    QPointF newPos = pos() + direction;
    setPos(newPos);

    QList<QGraphicsItem*> collidingItems = scene->collidingItems(this);
    for (QGraphicsItem* item : collidingItems) {
        obstaculo* otherImage = dynamic_cast<obstaculo*>(item);
        if (otherImage) {
            setPos(pos() - direction);  // Revert the move
            qDebug() << "Collision detected with MovableImage2.";
            break;
        }
    }
}

void Enemies::move() {
    if (this->pos().x() >= rightLimit) {
        movingRight = false;
    }
    else if (this->pos().x() <= leftLimit) {
        movingRight = true;
    }
    if (movingRight) {
        this->setPos(this->pos().x() + speed, this->pos().y());
    }
    else {
        this->setPos(this->pos().x() - speed, this->pos().y());
    }
}

void Enemies::jump() {
    if (!onGround) {
        return;
    }
    start_parabolic_movement(0, -150);
    onGround = false;
}

void Enemies::chase(personaje *player) {
    float dx = player->x() - this->x();
    float dy = player->y() - this->y();
    float distance = std::sqrt(dx*dx + dy*dy);

    if (distance < range) {
        setPos(x() + speed * dx / distance, y() + speed * dy / distance);
        if (dy > 0) {
            jump();
        }
    }
}

void Enemies::attack(personaje *player) {
    float dx = player->x() - this->x();
    float dy = player->y() - this->y();
    float distance = std::sqrt(dx*dx + dy*dy);
    /*if (distance < attackRange) {
        player->reduceHealth(damage);
    }*/
}

void Enemies::updateHealth(int damageTaken) {
    health -= damageTaken;
    /*if (health <= 0) {
        emit enemyDied(this);
    }*/
}

void Enemies::specialAttack(personaje *player) {
    float dx = player->x() - this->x();
    float dy = player->y() - this->y();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance < attackRange) {
        int specialDamage = (health == 100) ? 5 : 0;
        //player->reduceHealth(specialDamage);
    }
}
