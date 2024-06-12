#ifndef PLANO_H
#define PLANO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>
#include "sprites.h"
#include "enemies.h"
#include "fisicas.h"
#include "personaje.h"
class plano:public fisicas, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    plano(int z, int l, int h, QString ruta);
    ~plano();
    QTimer *timer;
    QTimer *timer_boom;
    int z,l,h;
};

#endif // PLANO_H
