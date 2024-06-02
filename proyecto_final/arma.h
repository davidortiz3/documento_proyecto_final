#ifndef ARMA_H
#define ARMA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"
#define arma_x_size 125
#define arma_y_size 112
#define arma_velocidad 8
class arma: public QObject, public QGraphicsPixmapItem
{
public:
    arma(unsigned int scale);
    void set_keys(unsigned int *keys);
    void move(unsigned int key, bool is_valid);
    ~arma();

private:
    QRect set_complete_sprites();
    void set_animations();
    void set_left_animation();
    void set_right_animation();
    void set_down_animation();
    void set_death_animation();

    sprites *pixmap_management;
    unsigned int keys[4];
};

#endif // ARMA_H
