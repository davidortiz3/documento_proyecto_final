#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "fisicas.h"
class escenario:public QGraphicsPixmapItem
{
public:
    escenario(int z, int l, QString level);
    ~escenario();
private:
    int z, l;
};

#endif // ESCENARIO_H
