#ifndef OBSTACULO_H
#define OBSTACULO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fisicas.h"
class obstaculo:public QGraphicsPixmapItem, public fisicas
{
public:
    obstaculo(int z, int l, int h);
    void decoracion();
    void circular();
private:
    int z, l;

};

#endif // OBSTACULO_H
