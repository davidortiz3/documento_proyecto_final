#ifndef ARMA_H
#define ARMA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "sprites.h"
#include "enemies.h"
#include <QVector>
#define arma_x_size 125
#define arma_y_size 112
#define arma_velocidad 8
class arma: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    arma(float scale, float speed = 10.0, float direction = -1.0);
    void set_keys(unsigned int *keys);
    void mover(unsigned int key, bool is_valid);
    ~arma();

public slots:
    void move();
private:
    QRect set_complete_sprites();
    void set_animations();
    void set_down_animation();
    QTimer *timer;
    sprites *pixmap_management;
    QVector<enemies *> enemy;
    float velocidad;
    float direction;
    unsigned int keys[4];
    bool collition();
    bool fuera_de_rango();
signals:
    bool colision(QGraphicsItem *shoot, int item);
    bool limite(QGraphicsItem *shoot);
};

#endif // ARMA_H
