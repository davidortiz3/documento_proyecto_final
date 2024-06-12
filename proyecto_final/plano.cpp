#include "plano.h"

plano::plano(int z, int l, int h, QString ruta): fisicas(z,l,h,this){
    QPixmap img(ruta);
    setPixmap(img.scaled(img.width(),img.height()));
    //set_animations();
    setX(0);
    setY(0);
    timer=new QTimer;
    timer_boom=new QTimer;
    //connect(timer_boom, SIGNAL(timeout()),this, SLOT(parabolic_shoot_bomba()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer_boom->start(16);
    timer->start(16);
}

plano::~plano()
{
    delete timer;
    delete timer_boom;
}
