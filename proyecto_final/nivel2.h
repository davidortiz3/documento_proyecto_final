#ifndef NIVEL2_H
#define NIVEL2_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "sprites.h"
#include <QGraphicsScene>
class nivel2:public QGraphicsPixmapItem
{
public:
    nivel2(int z, int l, QString ruta);
    ~nivel2();
private:
    int z, l;
};

#endif // NIVEL2_H
