#include "escenario.h"

escenario::escenario(int z, int l, QString level) {
    QPixmap img(level);
    setPixmap(img.scaled(img.width()*2,img.height()*2));
    this->z=z;
    this->l=l;
    setPos(z,l);
    //137,139
}

escenario::~escenario()
{

}
