#ifndef BOMBAS_H
#define BOMBAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QDebug>
#include "sprites.h"
#include "enemies.h"
#include "fisicas.h"
#include "nuclearbombs.h"
class bombas: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bombas(QVector<NuclearBombs*>enemy, QString ruta);
    ~bombas();
    float z,l,h;
private:
    QVector<NuclearBombs *> enemy;
    QTimer *timer;
    float direction, velocidad;
    bool quitar_disparo();
    bool remove_shoot();
public slots:
    void move();
signals:
    bool colision(QGraphicsItem *shoot, int item);
    bool quitar(QGraphicsItem *shoot);
};

#endif // BOMBAS_H
