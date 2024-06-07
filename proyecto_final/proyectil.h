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
class proyectil: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    proyectil(QVector<QGraphicsPixmapItem*>enemy,float z, float l, float h, QString ruta);
    ~proyectil();
    float z,l,h;
private:
    QVector<QGraphicsPixmapItem *> enemy;
    QTimer *timer;
    float direction, velocidad;
    bool quitar_disparo();
    bool remove_shoot();
public slots:
    void move();
signals:
    bool collition(QGraphicsItem *shoot, int item);
    bool fuera_de_rango(QGraphicsItem *shoot);
};
#endif // PROYECTIL_H
