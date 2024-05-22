#ifndef CLASE_BASE_H
#define CLASE_BASE_H
#include <QWidget>
#include <QVector>
#include <QGraphicsRectItem>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <cstdlib>
#include <ctime>
#include <QObject>
#include "escenario.h"
#include "escenario.h"
#include "personaje.h"
class clase_base: public QObject, public QGraphicsRectItem
{

public:
    clase_base(QGraphicsView *graph);
    ~clase_base();
    //void get_keyEvent(QKeyEvent *event);
    void start_parabolic();
    void move_right();
    void keyPressEvent(QKeyEvent *keys);
    void movimiento();
    void cargar_escena();
private:
    QGraphicsView *graph;
    QGraphicsScene *scene;
    personaje *bola1;
    escenario *plataforma;
    unsigned int mover[5];
    QBrush set_rgb_color(int r, int g, int b, int a = 255);
    void set_bomberman_keys();

};

#endif // CLASE_BASE_H
