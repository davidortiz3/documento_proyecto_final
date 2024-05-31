#include "enemies.h"

enemies::enemies(int z, int l, int h, float direccion): fisicas(z, l, h, this), player(player) {
    this->z = z;
    this->l = l;
    this->direccion=direccion;
    pixmap_management = new sprites(":/nive1/personaje/kisspng-metal-slug-6-metal-slug-7-metal-slug-advance-metal-sprite-5ad6e7616174e7.7483900015240333773992.png", 1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(enemies_x_size, enemies_y_size);

    set_animations();

    setPixmap(pixmap_management->get_current_pixmap(3));
    setX(0);
    setY(0);

    timer_enemi = new QTimer(this);
    connect(timer_enemi, SIGNAL(timeout()), this, SLOT(MRU()));
    timer_enemi->start(16);
}

enemies::~enemies()
{
    delete pixmap_management;
}

QRect enemies::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(23*enemies_y_size);
    dim.setWidth(23*enemies_x_size);

    return dim;
}

void enemies::set_animations()
{
    set_left_animation();
    set_right_animation();
    set_up_animation();
    set_down_animation();
    set_death_animation();
}

void enemies::set_left_animation()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(11*enemies_x_size);
    pixmap_management->add_new_animation(dim,11);
}

void enemies::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(8.5*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(12*enemies_x_size);

    pixmap_management->add_new_animation(dim,12);
}


void enemies::set_up_animation()
{
    QRect dim;

    dim.setX(3*enemies_x_size);
    dim.setY(1*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(3*enemies_x_size);

    pixmap_management->add_new_animation(dim,4);
}

void enemies::set_down_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(323);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(enemies_x_size);

    pixmap_management->add_new_animation(dim,13);
}

void enemies::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(3.2*enemies_y_size);
    dim.setHeight(1*enemies_y_size);
    dim.setWidth(29*enemies_x_size);

    pixmap_management->add_new_animation(dim,7);
}

void enemies::iniciar_movimiento()
{
    set_starting_parameters_MCU(-150,0);
    timer_enemi->start(16);
}



void enemies::move() {
    /*if (this->pos().x() >= rightLimit) {
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
    }*/
    setPixmap(pixmap_management->get_current_pixmap(0));
    setPos(i,m);
    i-=10;

    qDebug()<<"se esta moviendo";
}

void enemies::jump() {
    if (!onGround) {
        return;
    }
    start_parabolic_movement(0, -150);
    onGround = false;
}

void enemies::chase(personaje *player) {
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

void enemies::attack(personaje *player) {
    float dx = player->x() - this->x();
    float dy = player->y() - this->y();
    float distance = std::sqrt(dx*dx + dy*dy);
    /*if (distance < attackRange) {
        player->reduceHealth(damage);
    }*/
}

void enemies::updateHealth(int damageTaken) {
    health -= damageTaken;
    /*if (health <= 0) {
        emit enemyDied(this);
    }*/
}

void enemies::specialAttack(personaje *player) {
    float dx = player->x() - this->x();
    float dy = player->y() - this->y();
    float distance = std::sqrt(dx*dx + dy*dy);
    if (distance < attackRange) {
        int specialDamage = (health == 100) ? 5 : 0;
        //player->reduceHealth(specialDamage);
    }
}
