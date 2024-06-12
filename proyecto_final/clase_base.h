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
#include "nuclearbombs.h"
#include <QApplication>
#include "nivel2.h"
#include <random>
#include <QFile>
#include <QDataStream>
#include "plano.h"
#include "bombas.h"
class clase_base: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    clase_base(QGraphicsView *graph);
    ~clase_base();
    //void get_keyEvent(QKeyEvent *event);
    void start_parabolic();
    void set_bomberman_keys();
    void keyPressEvent(QKeyEvent *keys) override;
    void movimiento();
    void setup_enemigo();
    void set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex);
    void nivel1();
    void mapa(QString level);
    void mapa2(QString level);
    void arma_level2();
private:
    QGraphicsView *graph;
    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    QGraphicsScene *scene3;
    personaje *bola1;
    arma *bola2;
    escenario *plataforma;
    escenario *plataforma3;
    nivel2 *plataforma2;
    plano* map;
    QVector<QGraphicsPixmapItem*> enemigo;
    QVector<NuclearBombs*> bombas2;
    QVector<proyectil*> bombas1;
    QVector<bombas*> bombas3;
    QVector<NuclearBombs*> helicoptero;
    QTimer *time_level1, *timer_bomba, *time_fin;
    unsigned int mover[5];
    QBrush set_rgb_color(int r, int g, int b, int a = 255);
    int leftLimit, rightLimit, topLimit, bottomLimit;
    proyectil *bala;
    void enemies_MRU();
    void final_nivel();
    bool limites(bool limite);
    void terminar_level();
    bool saber_nivel();
    void escribir_archivo(const QString &archivo, const QString &contenido);
    QString leer_archivo(const QString &filePath);
    void setup_helicoptero();
    void fisicas_helicoptero();
    int puntaje=0;
public slots:
    void disparar();
    void disparar2();
    void level2();
    void quitar_disparo(QGraphicsItem *shoot);
    void quitar_item(QGraphicsItem* shoot);
    void remove_shoot(QGraphicsItem *shoot, int n);
    void quitar_bomba(QGraphicsItem *shoot, int n);
    void soldado(const QString usuario);
    void quitar_enemigo(int n);
    void setup_enemigo2();
    void terminar_level2();
    //void disparar2();

/*signals:
    void letterPressed(QChar letter);*/
};

#endif // CLASE_BASE_H
