#include "nivel2.h"

#include "nivel2.h"

nivel2::nivel2(int z, int l,QString ruta) {
    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/4,img.height()/4));
    this->z=z;
    this->l=l;
    setPos(z,l);
    //137,139
}

nivel2::~nivel2()
{

}
