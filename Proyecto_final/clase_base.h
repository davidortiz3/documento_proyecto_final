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
#include "obstaculo.h"
#include "personaje.h"
#include "proyectil.h"
class clase_base: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    clase_base(QGraphicsView *graph);
    ~clase_base();
    //void get_keyEvent(QKeyEvent *event);
    void start_parabolic();
    void move_right();
    void keyPressEvent(QKeyEvent *keys) override;
    void movimiento();

    void set_focus_element(QGraphicsPixmapItem *item,unsigned int scalex, unsigned int scaley);
private:
    QGraphicsView *graph;
    QGraphicsScene *scene;
    personaje *bola1;
    escenario *plataforma;
    unsigned int mover[5];
    QBrush set_rgb_color(int r, int g, int b, int a = 255);
    void set_bomberman_keys();
    int leftLimit, rightLimit, topLimit, bottomLimit;
    bool moveImage();
    obstaculo *obstaculo1;
    proyectil *bala;

/*signals:
    void letterPressed(QChar letter);*/
};

#endif // CLASE_BASE_H
