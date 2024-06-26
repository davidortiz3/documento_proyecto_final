#include "clase_base.h"

clase_base::clase_base(QGraphicsView *graph) {
    this->graph = graph;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,graph->width()-2,graph->height()-2);
    graph->setScene(scene);
    bola1 = new personaje(0,100,graph->height());
    plataforma=new escenario(0,400);
    //movimiento();
    //bola1->keys(mover);
    scene->addItem(bola1);
    scene->addItem(plataforma);
    //cargar_escena();
}



clase_base::~clase_base()
{
    delete scene;
    delete bola1;
}

void clase_base::keyPressEvent(QKeyEvent *keys)
{
    /*if(keys->key() == Qt::Key_A) {
        bola1->startCircularMovement();
    } else if(keys->key() == Qt::Key_D) {
        bola1->start_parabolic_movement();
    } else if(keys->key() == Qt::Key_W) {
        bola1->right();
    } else if(keys->key() == Qt::Key_S) {
        bola1->setPos(bola1->x(), bola1->y() + 7);
    } else if(keys->key() == Qt::Key_Space) {
        bola1->start_oscillation();
    }*/
    bola1->mover(keys->key(),true);
}

/*void clase_base::movimiento()
{
    mover[0] = Qt::Key_A;
    mover[1] = Qt::Key_D;
    mover[2] = Qt::Key_W;
    mover[3] = Qt::Key_S;
    mover[5] =Qt::Key_Space;
}*/

void clase_base::cargar_escena()
{
    graph->setGeometry(0,0,200,200);

    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,graph->width()-2, graph->height()-2);
    graph->setScene(scene);
    //scene->setBackgroundBrush(set_rgb_color(255,255,255));
}

void clase_base::set_bomberman_keys()
{
    mover[0] = Qt::Key_A;
    mover[1] = Qt::Key_D;
    mover[2] = Qt::Key_W;
    mover[3] = Qt::Key_S;
    mover[5] = Qt::Key_Space;
}
