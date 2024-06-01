#include "proyectil.h"

proyectil::proyectil(QVector<enemies *> enemigo, float scale, float velocidad, float direction) {
    pixmap_management = new sprites(":/nive1/escenario/disparo.png", scale);
    pixmap_management->set_design_size(proyectil_x_size, proyectil_y_size);
    pixmap_management->cut_character_pixmap(set_complete_sprites());

    QPixmap pixmap = pixmap_management->get_fixed_image(set_complete_sprites());
    setPixmap(pixmap);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
    this->enemigo = enemigo;
    this->z=z;
    this->l=l;
    this->velocidad=velocidad;
    this->direction=direction;
    setPos(z,l);
    movimiento();

}


QRect proyectil::set_complete_sprites()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(proyectil_y_size);
    dim.setWidth(proyectil_x_size);
    return dim;
}
void proyectil::movimiento()
{
   animacion_disparo();
}

QRect proyectil::animacion_disparo()
{
    QRect dim;

    dim.setX(45);
    dim.setY(450);
    dim.setHeight(32);
    dim.setWidth(73);

    return dim;
}

void proyectil::mover()
{
    setPos(x(), y() + direction * velocidad);
}


