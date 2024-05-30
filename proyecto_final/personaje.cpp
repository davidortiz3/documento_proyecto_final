#include "personaje.h"

personaje::personaje(int z, int l, int h) : fisicas( z,l,h, this){
    this->z=z;
    this->l=l;
    pixmap_management = new sprites(":/soldado/pngfind.com-metal-slug-png-4743164.png",1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(personaje_x_size,  personaje_y_size);

    set_animations();

    setPixmap(pixmap_management->get_current_pixmap(3));
    setX(0);
    setY(0);

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
        if(is_valid) start_parabolic_movement(-100,0);
    }
    else if(key == keys[1]){
        setPixmap(pixmap_management->get_current_pixmap(1));
        if(is_valid) start_parabolic_movement(100,0);
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) {
            start_parabolic_movement(0,-150);
            z=static_cast<int>(x());
            l=static_cast<int>(y());

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

void personaje::moveItem(const QPointF& direction, QGraphicsScene* scene) {
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


