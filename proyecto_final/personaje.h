#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "fisicas.h"
#include "sprites.h"
#include "escenario.h"
#include "obstaculo.h"
#include "proyectil.h"
#define personaje_x_size 33
#define personaje_y_size 50
#define speed 1
class personaje :public QGraphicsPixmapItem,  public fisicas
{
public:
    personaje(int z, int l, int h, QString usuario);
    void mover_derecha();
    void mover_izquierda();
    void saltar();
    void agachar();
    void colision();
    bool debug();
    void set_animations();
    void set_left_animation();
    void mover(unsigned int n, bool is_valid);
    void set_death_animation();
    void set_keys(unsigned int *keys);
    QRect set_complete_sprites();
    void set_up_animation();
    void set_down_animation();
    bool colisiones;
    void set_right_animation();

    ~personaje();
private:
   //unsigned int j[5];
    int leftLimit, rightLimit, topLimit, bottomLimit;
    int z, l, velocidad=3;
    sprites *pixmap_management;
    unsigned int keys[4];
    void moveItem(const QPointF& direction, QGraphicsScene* scene);
    void moveImage();
    void movimiento();

};

#endif // PERSONAJE_H
