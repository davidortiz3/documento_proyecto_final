#include "proyectil.h"

proyectil::proyectil(int z, int l) {
    QPixmap img(":/balas/escenario/pngegg (1).png");
    setPixmap(img.scaled(img.width()/5,img.height()/5));
    this->z=z;
    this->l=l;
    setPos(z,l);
    movimiento();

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

