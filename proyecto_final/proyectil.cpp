#include "proyectil.h"

proyectil::proyectil(QVector<QGraphicsPixmapItem *> enemy, QString ruta) {

    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/27,img.height()/27));
    timer=new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(16);
    this->enemy=enemy;
}

proyectil::~proyectil()
{
    delete timer;
}

void proyectil::move()
{
    setPos(x()+10, y() );
    if(quitar_disparo() || remove_shoot()) delete this;
}

bool proyectil::quitar_disparo()
{
    bool is_deleted = false;
    if(x()>1500){
        emit fuera_de_rango(this);
        is_deleted = true;
    }

    return is_deleted;
}

bool proyectil::remove_shoot()
{
    bool is_deleted = false;
    for(int i=0; i< enemy.length(); i++){
        enemies *enemigo=dynamic_cast<enemies*>(enemy.at(i));
        if(enemigo->collidesWithItem(this)){
            timer->stop();
            emit collition(this,i);
            is_deleted = true;
            break;
        }
    }

    return is_deleted;
}
