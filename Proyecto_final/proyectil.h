#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fisicas.h"
#include "sprites.h"
#include "personaje.h"
class proyectil:public QGraphicsPixmapItem, public fisicas
{
public:
    proyectil(int z, int l, int h);
    void movimiento();
    QRect animacion_disparo();
private:
    int z, l;
private slots:
    void handleLetterPressed(QChar letter);
};

#endif // PROYECTIL_H
