#include "escenario.h"

escenario::escenario(int z, int l) {
    QPixmap img(":/calle/escenario/calle.png");
    setPixmap(img.scaled(img.width(),img.height()/2));
    this->z=z;
    this->l=l;
    setPos(z,l);
}
