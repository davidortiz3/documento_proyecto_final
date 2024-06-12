#include "personaje.h"

personaje::personaje(QVector<QGraphicsPixmapItem*>enemigo,int z, int l, int h, QString usuario): fisicas( z,l,h, this){
    this->z=z;
    this->l=l;
    pixmap_management = new sprites(usuario,1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(personaje_x_size,  personaje_y_size);
    set_animations();
    setPixmap(pixmap_management->get_current_pixmap(3));
    setX(0);
    setY(0);
    this->enemigo=enemigo;
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
    dim.setHeight(23*personaje_y_size);
    dim.setWidth(23*personaje_x_size);

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
    dim.setWidth(6*personaje_x_size);

    pixmap_management->add_new_animation(dim,6);
}

void personaje::mover(unsigned int key, bool is_valid)
{
    if(key == keys[0]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid){
            start_parabolic_movement(izquierda,0);
            if(choque_enemigo());
        }
    }
    else if(key == keys[1]){
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid) {
            start_parabolic_movement(derecha,0);
            if(choque_enemigo());
        }
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid) {
            start_parabolic_movement(0,jump);
            if(choque_enemigo());
        }
    }else if(key==keys[4]){
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid){
            start_parabolic_movement(150,-200);
        }
    }
}

void personaje::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(8.5*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(12*personaje_x_size);

    pixmap_management->add_new_animation(dim,12);
}

bool personaje::choque_enemigo()
{
    bool is_deleted = false;
    for(int i=0; i< enemigo.length(); i++){
        enemies *enemy=dynamic_cast<enemies*>(enemigo.at(i));
        if(enemy->collidesWithItem(this)){
            emit choque(i);
            qDebug() << "Hubo colision";
            is_deleted = true;
            break;
        }
    }

    return is_deleted;
}

void personaje::set_up_animation()
{
    QRect dim;

    dim.setX(3*personaje_x_size);
    dim.setY(1*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(3*personaje_x_size);

    pixmap_management->add_new_animation(dim,4);
}

void personaje::set_down_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(323);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(personaje_x_size);

    pixmap_management->add_new_animation(dim,13);
}

void personaje::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(3.2*personaje_y_size);
    dim.setHeight(1*personaje_y_size);
    dim.setWidth(29*personaje_x_size);

    pixmap_management->add_new_animation(dim,7);
}
