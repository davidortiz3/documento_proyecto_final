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
#include "arma.h"
#include "personaje.h"
#include "proyectil.h"
#include "enemies.h"
#include <QApplication>
#include "nivel2.h"
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
    void setup_enemigo();
    void set_focus_element(QGraphicsPixmapItem *item,unsigned int scalex, unsigned int scaley);
    void nivel1();
    void mapa(QString level);
    void soldado(QString usuario);
    void arma_level2();
private:
    QGraphicsView *graph;
    QGraphicsScene *scene;
    personaje *bola1;
    arma *bola2;
    escenario *plataforma;
    nivel2 *plataforma2;

    QVector<enemies*> enemigo;
    QVector<arma*> bombas2;
    QVector<proyectil*> bombas1;
    QTimer *time_level1;
    unsigned int mover[5];
    QBrush set_rgb_color(int r, int g, int b, int a = 255);
    void set_bomberman_keys();
    int leftLimit, rightLimit, topLimit, bottomLimit;
    proyectil *bala;
    void enemies_MRU();
    void enemies_cicular();
    bool limites(bool limite);
    void terminar_level();
    bool saber_nivel();
public slots:
    void disparar();
    void level2();
    void disparar2();

/*signals:
    void letterPressed(QChar letter);*/
};

#endif // CLASE_BASE_H
