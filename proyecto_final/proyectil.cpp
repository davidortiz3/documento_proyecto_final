#include "proyectil.h"

proyectil::proyectil(QVector<QGraphicsPixmapItem *> enemy, float z, float l, float h, QString ruta): fisicas(z,l,h,this) {

    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/15,img.height()/15));
    timer=new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(16);
}

proyectil::~proyectil()
{
    delete timer;
}

void proyectil::move()
{
    bomba();
    if(quitar_disparo() || remove_shoot()) delete this;
}

bool proyectil::quitar_disparo()
{
    bool is_deleted = false;
    if(y()<0){
        emit fuera_de_rango(this);
        is_deleted = true;
    }

    return is_deleted;
}

bool proyectil::remove_shoot()
{
    bool is_deleted = false;
    for(int i=0; i< enemy.length(); i++){
        if(enemy.at(i)->collidesWithItem(this)){
            timer->stop();
            emit collition(this,i);
            is_deleted = true;
            break;
        }
    }

    return is_deleted;
}
