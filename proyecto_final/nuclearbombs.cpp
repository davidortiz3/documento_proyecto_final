#include "nuclearbombs.h"

NuclearBombs::NuclearBombs(int z, int l, int h, QString ruta): fisicas(z,l,h,this){
    QPixmap img(ruta);
    setPixmap(img.scaled(img.width(),img.height()));
    //set_animations();
    setX(0);
    setY(0);
    timer=new QTimer;
    timer_boom=new QTimer;
    connect(timer_boom, SIGNAL(timeout()),this, SLOT(parabolic_shoot_bomba()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer_boom->start(16);
    timer->start(16);
}

NuclearBombs::~NuclearBombs()
{
    delete timer;
    delete timer_boom;
}

bool NuclearBombs::limite()
{
    bool rango=false;
    if(y()>500){
        timer_boom->stop();
        emit explosion(this);
        rango=true;
    }
    return rango;
}

void NuclearBombs::move()
{
    //connect(timer, SIGNAL(timeout()),this, SLOT(parabolic_shoot_bomba()));
    //timer->start(16);
    if(limite()){
        delete this;
    }
}

