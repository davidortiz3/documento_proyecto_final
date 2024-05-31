#include "escenario.h"

escenario::escenario(int z, int l) {
    QPixmap img(":/nive1/escenario/Captura de pantalla_29-5-2024_191835_.jpeg");
    setPixmap(img.scaled(img.width()*2,img.height()*2));
    this->z=z;
    this->l=l;
    setPos(z,l);
    //137,139
}
