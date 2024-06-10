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
    NuclearBombs(int z, int l, int h, QString ruta);
    QTimer *timer;
    QTimer *timer_boom;
    int z,l,h;
private:
    bool limite();
public slots:
    void move();
signals:
    bool explosion(QGraphicsItem* bomba);
};


#endif // NUCLEARBOMBS_H
