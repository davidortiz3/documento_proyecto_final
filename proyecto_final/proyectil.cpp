#include "proyectil.h"

proyectil::proyectil(int z, int l, int h, QString ruta): fisicas(z,l,h,this) {

    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/10,img.height()/10));
    timer=new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(mover_bala()));
    timer->start(16);
}

proyectil::~proyectil()
{
    delete timer;
}

void proyectil::move()
{
    qDebug()<<"bala creada";
    setPos(x()+25, y());
}
