#include "clase_base.h"

clase_base::clase_base(QGraphicsView *graph) {
    this->graph = graph;
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,graph->width()-2,graph->height()-2);
    graph->setScene(scene);
    bola1 = new personaje(100,323,graph->height());
    plataforma=new escenario(0,0);
    obstaculo1= new obstaculo(0,0, graph->height());
    obstaculo2= new obstaculo(0,0,graph->height());
    enemigo1= new enemies(200,323,graph->height(), -1.0);
    set_bomberman_keys();
    bola1->set_keys(mover);
    scene->addItem(plataforma);
    scene->addItem(bola1);
    scene->addItem(enemigo1);
    scene->addItem(obstaculo1);
    set_focus_element(bola1,40*2,0);
    //scene->addItem(bala);
    //obstaculo1->circular();
    //obstaculo2->circular();
    //QObject::connect(this, SIGNAL(letterPressed(QChar letter)), bala, SLOT(handleLetterPressed(QChar)));
}



clase_base::~clase_base()
{
    delete scene;
    delete bola1;
    delete plataforma;
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
    if(bola1->x()<1450 || bola1->y()>600){
        set_focus_element(bola1,40*2,0);
    }
    bola1->mover(keys->key(),true);
    /*if(keys->key()==Qt::Key_Z){
        emit letterPressed('z');
    }*/
}




void clase_base::set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex, unsigned int scaley)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());


}

void clase_base::set_bomberman_keys()
{
    mover[0] = Qt::Key_A;
    mover[1] = Qt::Key_D;
    mover[2] = Qt::Key_W;
    mover[3] = Qt::Key_S;
    mover[5] = Qt::Key_Space;

}

bool clase_base::moveImage()
{
    bool validar=false;
    leftLimit = 0;
    rightLimit = 3819;
    topLimit = 2200;
    bottomLimit = 2000;
    // Calcular la nueva posición
    int newX = bola1->x() + 2;
    int newY = bola1->y() + 2;

    if ( newY <= bottomLimit){
        validar=true;
        return validar;
    }else{
        return validar;
    }
}
