#include "nuclearbombs.h"

NuclearBombs::NuclearBombs(int z, int l, int h, personaje *player, QString ruta): fisicas(z,l,h,this) {

    QPixmap img(ruta);
    setPixmap(img.scaled(img.width()/10,img.height()/10));
    set_animations();
    setX(0);
    setY(0);
    timer=new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(move_nbomb()));
    timer->start(16);
    qsrand((uint)time.msec());
    movementType = qrand() % 3 + 1;
}

void NuclearBombs::set_animations(){
    set_animation_left();
    set_animation_right();
    set_animation_default();
}

void NuclearBombs::set_animation_default(){

}

void NuclearBombs::set_animation_left(){

}

void NuclearBombs::set_animation_right(){

}
void NuclearBombs::move_nbomb(){
    int x = this->x();
    int y = this->y();
    int playerX = player->x();
    int playerY = player->y();
    int dx = playerX - x;
    int dy = playerY - y;
    float length = sqrt(dx*dx + dy*dy);
    dx /= length;
    dy /= length;
    x += speed * dx;
    y += speed * dy;
    setX(x);
    setY(y);
}
