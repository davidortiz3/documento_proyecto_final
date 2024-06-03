#include "obstaculo.h"

obstaculo::obstaculo(int z, int l, int h) : fisicas( z,l,h, this) {
    QPixmap img(":/obstaculo1/escenario/pngegg.png");
    setPixmap(img.scaled(img.width()/5,img.height()/5));
    this->z=z;
    this->l=l;
    setPos(z,l);
}

void obstaculo::decoracion()
{
    start_oscillation();

}

void obstaculo::circular()
{
    startCircularMovement();
}
