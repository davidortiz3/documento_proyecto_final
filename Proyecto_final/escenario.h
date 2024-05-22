#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "fisicas.h"
class escenario:public QGraphicsPixmapItem
{
public:
    escenario(int z, int l);
private:
    int z, l;
};

#endif // ESCENARIO_H
