#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include "fisicas.h"
#include "sprites.h"
#include "personaje.h"

#define proyectil_x_size 250
#define proyectil_y_size 250

class enemies;  // Declaración anticipada de la clase enemies

class proyectil : public QObject, public QGraphicsPixmapItem {

public:
    proyectil(QVector<enemies*> enemigo, float scale, float velocidad, float direction);
    void movimiento();
    QRect animacion_disparo();
private:
    int z, l;
    float direction, velocidad;
    QRect set_complete_sprites();
    QTimer *timer;
    QVector<enemies*> enemigo;
    sprites* pixmap_management;
private slots:
    void mover();
signals:
    void choque_enemigos(QGraphicsItem *disparos, int imagen);
    void fuera_de_rango(QGraphicsItem *disparos);
};

#endif // PROYECTIL_H
