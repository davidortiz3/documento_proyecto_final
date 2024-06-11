#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fisicas.h"
#include "sprites.h"
#include "escenario.h"
#include "obstaculo.h"
#include "proyectil.h"
#define personaje_x_size 33
#define personaje_y_size 50
constexpr int speed =1;
class personaje : public fisicas, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje(QVector<QGraphicsPixmapItem *> enemigo, int z, int l, int h, QString usuario);
    void set_animations();
    void set_left_animation();
    void set_death_animation();
    void set_keys(unsigned int *keys);
    QRect set_complete_sprites();
    void set_up_animation();
    void set_down_animation();
    bool colisiones;
    void set_right_animation();
    QVector<QGraphicsPixmapItem*>enemigo;
    bool choque_enemigo();
    ~personaje();
private:
   //unsigned int j[5];
    int leftLimit, rightLimit, topLimit, bottomLimit;
    int z, l,derecha=400, izquierda=-150,jump=-150;
    sprites *pixmap_management;
    unsigned int keys[4];
    int vida_personaje=100;
public slots:
    void mover(unsigned int n, bool is_valid);
signals:
    bool choque(int n);
};
#endif // PERSONAJE_H
