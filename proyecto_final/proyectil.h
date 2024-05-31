#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fisicas.h"
#include "sprites.h"
#include "personaje.h"
class proyectil:public QGraphicsPixmapItem
{
public:
    proyectil(int z, int l);
    void movimiento();
    QRect animacion_disparo();
private:
    int z, l;
private slots:

};

#endif // PROYECTIL_H
