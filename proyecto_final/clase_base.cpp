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
    //enemigo1= new enemies(700,196,graph->height(), -1.0);
    set_bomberman_keys();
    bola1->set_keys(mover);
    scene->addItem(plataforma);
    scene->addItem(bola1);
    //scene->addItem(enemigo1);
    scene->addItem(obstaculo1);
    set_focus_element(bola1,40*2,0);
    setup_enemigo();
    enemies_MRU();
    //enemies_cicular();
    //enemigo1->start_MRU();
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

    if(bola1->x()<1450 || bola1->y()>600){
        set_focus_element(bola1,40*2,0);
    }
    if(unsigned(keys->key()) == mover[0]){
        bola1->mover(keys->key(),limite(true));
    }
    else if(unsigned(keys->key()) == mover[1]){
        bola1->mover(keys->key(),limite(false));
    }
    else if(unsigned(keys->key()) == mover[2]){
        disparar();
    }

}

void clase_base::setup_enemigo()
{
    enemigo.push_back(new enemies(700,196,graph->height(), -1.0));
    enemigo.push_back(new enemies(900,196,graph->height(), -1.0));
    enemigo.push_back(new enemies(1000,196,graph->height(), -1.0));
    for(short i=0; i<enemigo.length(); i++) scene->addItem(enemigo[i]);
}




void clase_base::set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex, unsigned int scaley)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());


}

bool clase_base::limite(bool limite)
{
    int posicion = bola1->x();

    if (limite) posicion -=8;
    else posicion +=8;

    if (posicion < 20 || posicion > 335){
        return false;
    }
    return true;
}

void clase_base::set_bomberman_keys()
{
    mover[0] = Qt::Key_A;
    mover[1] = Qt::Key_D;
    mover[2] = Qt::Key_W;
    mover[3] = Qt::Key_S;
    mover[5] = Qt::Key_Space;

}

void clase_base::enemies_cicular()
{
    enemigo[1]->startCircularMovement();
}

void clase_base::disparar()
{
    disparos.push_back(new proyectil(enemigo, 0.03, 10.0, -1.0));
    connect(disparos[disparos.length()-1],SIGNAL(is_enemy_reached(QGraphicsItem*,int)),this,SLOT(enemy_is_reached(QGraphicsItem*,int)));
    connect(disparos[disparos.length()-1],SIGNAL(is_shoot_out_of_range(QGraphicsItem*)),this,SLOT(remove_shoot(QGraphicsItem*)));
    //qDebug() << "Bala creada";
    disparos[disparos.length()-1]->setPos(bola1->x(), bola1->y());
    scene->addItem(disparos[disparos.length()-1]);
}

void clase_base::enemies_MRU()
{
    enemigo[0]->start_MRU();
    enemigo[1]->start_MRU();
}

