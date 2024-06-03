#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>
#include "sprites.h"
#include "enemies.h"
#include "fisicas.h"
class proyectil: public fisicas, public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    proyectil(int z, int l, int h, QString ruta);
    ~proyectil();
    QTimer *timer;
    int z,l,h;
public slots:
    void move();
};

#endif // PROYECTIL_H
