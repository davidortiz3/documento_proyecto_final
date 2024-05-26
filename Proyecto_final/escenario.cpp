#include "escenario.h"

escenario::escenario(int z, int l) {
    QPixmap img(":/nivel1/escenario/nivel1.jpg");
    setPixmap(img.scaled(img.width()/5,img.height()/5));
    this->z=z;
    this->l=l;
    setPos(z,l);
}
