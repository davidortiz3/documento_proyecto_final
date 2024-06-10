#ifndef NUCLEARBOMBS_H
#define NUCLEARBOMBS_H
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
class NuclearBombs:public fisicas, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    NuclearBombs(int z, int l, int h, personaje *player, QString ruta);
    QTimer *timer;
    int z,l,h;
    void move_nbomb();
private:
    personaje *player;
};

#endif // NUCLEARBOMBS_H
