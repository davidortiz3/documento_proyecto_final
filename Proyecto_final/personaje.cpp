#include "personaje.h"

personaje::personaje(int z, int l, int h) : fisicas( z,l,h, this){
    QPixmap img(":/pngwing.com (5).png");
    setPixmap(img.scaled(img.width()/100,img.height()/100));
    this->z=z;
    this->l=l;
    //setPos(z,h);

}

void personaje::mover_derecha()
{
   z+=velocidad;
    setPos(z,l);
}


/*void personaje::mover(unsigned int n)
{

    if(j[0]==n){
        setX(x()-7);
    }else if(j[1]==n){
        setX(x()+7);
    }else if(j[2]==n){
        setY(y()-7);
    }else if(j[3]==n){
        setY(y()+7);
    }else if(j[4]==n){
        start_parabolic_movement();
    }
}*/

/*void personaje::keys(unsigned int *j)
{
    for(int i=0; i<5; i++){
        this->j[i]=j[i];
    }
}*/


