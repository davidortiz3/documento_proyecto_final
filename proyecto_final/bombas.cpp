#include "bombas.h"

bombas::bombas(QVector<NuclearBombs *> enemy, QString ruta) {
    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/27,img.height()/27));
    timer=new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(16);
    this->enemy=enemy;
}

bombas::~bombas()
{
    delete timer;
}

void bombas::move()
{
    setPos(x(), y()-10);
    if(quitar_disparo() || remove_shoot()) delete this;
}

bool bombas::quitar_disparo()
{
    bool is_deleted = false;
    if(y()<-100){
        timer->stop();
        emit quitar(this);
        is_deleted = true;
    }
    return is_deleted;
}

bool bombas::remove_shoot()
{
    bool is_deleted = false;
    for(int i=0; i< enemy.length(); i++){
        //NuclearBombs *enemigo=dynamic_cast<NuclearBombs*>(enemy.at(i));
        if(enemy.at(i)->collidesWithItem(this)){
            timer->stop();
            emit colision(this,i);
            is_deleted = true;
            break;
        }
    }
    return is_deleted;
}


