#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "fisicas.h"
#include "sprites.h"
#include "escenario.h"
#define personaje_x_size 232
#define personaje_y_size 463
#define speed 4
class personaje :public QGraphicsPixmapItem,  public fisicas
{
public:
    personaje(int z, int l, int h);
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
    //void keys(unsigned int *j);
    void set_up_animation();
    void set_down_animation();
    bool colisiones;
    void set_right_animation();
    ~personaje();
private:
   //unsigned int j[5];
    int z, l, velocidad=12;
    sprites *pixmap_management;
    unsigned int keys[4];

};

#endif // PERSONAJE_H
