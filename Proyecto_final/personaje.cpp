#include "personaje.h"

personaje::personaje(int z, int l, int h) : fisicas( z,l,h, this){
    this->z=z;
    this->l=l;
    pixmap_management = new sprites("qrc:/new/prefix1/personaje/correr_derecha.png",2);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(personaje_x_size,  personaje_y_size);

    set_animations();

    setPixmap(pixmap_management->get_current_pixmap(3));
    setPos(z,h);

}

void personaje::mover_derecha()
{
    z+=velocidad;
    setPos(z,l);
}




void personaje::set_keys(unsigned int *keys)
{
    for(unsigned int i=0;i<5;i++) this->keys[i] = keys[i];
}



personaje::~personaje()
{
    delete pixmap_management;
}

QRect personaje::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(3*personaje_y_size);
    dim.setWidth(7*personaje_x_size);

    return dim;
}

void personaje::set_animations()
{
    set_left_animation();
    set_right_animation();
    set_up_animation();
    set_down_animation();
    set_death_animation();
}

void personaje::set_left_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(3*personaje_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::mover(unsigned int key, bool is_valid)
{
    if(key == keys[0]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) setX(x()-speed);
    }
    else if(key == keys[1]){
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid) setX(x()+speed);
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(2));
        if(is_valid) setY(y()-speed);
    }
    else if(key == keys[3]){
        setPixmap(pixmap_management->get_current_pixmap(3));
        if(is_valid) setY(y()+speed);
    }
}

void personaje::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(1*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(3*personaje_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_up_animation()
{
    QRect dim;

    dim.setX(3*personaje_x_size);
    dim.setY(1*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(3*personaje_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_down_animation()
{
    QRect dim;

    dim.setX(3*personaje_x_size);
    dim.setY(0);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(3*personaje_x_size);

    pixmap_management->add_new_animation(dim,3);
}

void personaje::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(2*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(7*personaje_x_size);

    pixmap_management->add_new_animation(dim,7);
}
