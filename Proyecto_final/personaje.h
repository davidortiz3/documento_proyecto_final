#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "fisicas.h"

class personaje :public QGraphicsPixmapItem,  public fisicas
{
public:
    personaje(int z, int l, int h);
    void mover_derecha();
    void mover_izquierda();
    void saltar();
    void agachar();
    //void mover(unsigned int n);
    //void keys(unsigned int *j);

private:
   //unsigned int j[5];
    int z, l, velocidad=12;
};

#endif // PERSONAJE_H
