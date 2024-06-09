#include "enemies.h"

enemies::enemies(int z, int l, int h, float direccion): fisicas(z, l, h, this) {
    this->z = z;
    this->l = l;
    this->direccion=direccion;
    pixmap_management = new sprites(":/nive1/personaje/volar.png", 1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(enemies_x_size, enemies_y_size);

    set_animations();

    setPixmap(pixmap_management->get_current_pixmap(0));
    setX(0);
    setY(0);
    timer_enemi = new QTimer;
    time_move = new QTimer;
    //connect(timer_enemi, SIGNAL(timeout()), this, SLOT(movimiento()));
    connect(time_move, SIGNAL(timeout()), this, SLOT(MRU()));
    //time_move->start(16);
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
    dim.setHeight(10*enemies_y_size);
    dim.setWidth(10*enemies_x_size);

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
    dim.setHeight(enemies_y_size);
    dim.setWidth(enemies_x_size);
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
    //start_parabolic_movement(-150,0);
    time_move->start(16);
}

void enemies::movimiento()
{
    setPixmap(pixmap_management->get_current_pixmap(0));
    time_move->start(16);
}






