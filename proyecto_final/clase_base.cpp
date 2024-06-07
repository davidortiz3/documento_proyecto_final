#include "clase_base.h"

clase_base::clase_base(QGraphicsView *graph) {
    this->graph = graph;
    time_level1=new QTimer;
    nivel1();
    connect(time_level1, SIGNAL(timeout()), this, SLOT(level2()));
}



clase_base::~clase_base()
{
    delete scene;
    delete bola1;
    delete plataforma;

    for(int i=0; i<enemigo.length(); i++){
        delete enemigo[i];
    }
    for(int i=0; i<bombas1.length(); i++){
        delete bombas1[i];
    }
    enemigo.clear();
    bombas1.clear();
}

void clase_base::keyPressEvent(QKeyEvent *keys)
{
    bool nivel=saber_nivel();
    if(nivel){
        if(bola1->x()<1450 || bola1->y()>600){
            set_focus_element(bola1,40*2,0);
        }
        if(unsigned(keys->key()) == mover[0])bola1->mover(keys->key(),limites(true));
        else if(unsigned(keys->key()) == mover[1])bola1->mover(keys->key(),limites(false));
        else if(unsigned(keys->key()) == mover[2]) bola1->mover(keys->key(), true);
        else if(unsigned(keys->key()) == mover[3]) disparar();
    }else{
        if(unsigned(keys->key()) == mover[0]){
            bola2->mover(keys->key(),limites(true));
        }
        else if(unsigned(keys->key()) == mover[1]){
            bola2->mover(keys->key(),limites(false));
        }else if(unsigned(keys->key()==mover[2])){
            //disparar2();
        }
    }

}

void clase_base::setup_enemigo()
{
    enemigo.push_back(new enemies(700,196,graph->height(), -1.0));
    enemigo.push_back(new enemies(900,196,graph->height(), -1.0));
    enemigo.push_back(new enemies(1000,196,graph->height(), -1.0));
    for(short i=0; i<enemigo.length(); i++) scene->addItem(enemigo[i]);
}

void clase_base::setup_enemigo2()
{

}




void clase_base::set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex, unsigned int scaley)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());


}

void clase_base::nivel1()
{
    mapa(":/nive1/escenario/Captura de pantalla_29-5-2024_191835_.jpeg");
    time_level1->start(600000);
    soldado(":/nive1/pngfind.com-metal-slug-png-4743164.png");
    setup_enemigo();
    enemies_MRU();
}

void clase_base::level2()
{
    mapa(":/nive1/escenario/piso_nivel2.png");
    terminar_level();
    arma_level2();

}

void clase_base::quitar_disparo(QGraphicsItem *shoot, int n)
{
   remove_shoot(shoot);
}

void clase_base::remove_shoot(QGraphicsItem *shoot)
{
    scene->removeItem(shoot);
    for(int i=0; i<enemigo.length(); i++){
        if(enemigo[i] == shoot){
            enemies* enemy=dynamic_cast<enemies*>(enemigo[i]);
            disconnect(enemy);
            enemigo.remove(i);
            break;
        }
    }
}

/*void clase_base::disparar2()
{
    bombas2.push_back(new proyectil(enemigo,0.3,10.0,-1.0));
    bombas2[bombas2.length()-1]->setPos(bola2->x(), bola2->y());
    scene->addItem(bombas2[bombas2.length()-1]);
    qDebug() << "Bala creada";
}*/


void clase_base::mapa(QString level)
{
    bool nivel=saber_nivel();
    if(!nivel){
        scene = new QGraphicsScene;
        scene->setSceneRect(0,0,graph->width()-2,graph->height()-2);
        graph->setScene(scene);
        plataforma=new escenario(0,0,level);
        scene->addItem(plataforma);
    }else{
        scene = new QGraphicsScene;
        scene->setSceneRect(0,0,graph->width()-2,graph->height()-2);
        graph->setScene(scene);
        plataforma2=new nivel2(10,-1000,level);
        scene->addItem(plataforma2);
    }
}

void clase_base::soldado(QString usuario)
{
    bola1 = new personaje(100,323,graph->height(),usuario);
    set_bomberman_keys();
    bola1->set_keys(mover);
    scene->addItem(bola1);
    set_focus_element(bola1,40*2,0);
}

void clase_base::arma_level2()
{
    bola2=new arma(1);
    set_bomberman_keys();
    bola2->set_keys(mover);
    scene->addItem(bola2);
    bola2->setPos(0,350);
}

void clase_base::set_bomberman_keys()
{
    mover[0] = Qt::Key_A;
    mover[1] = Qt::Key_D;
    mover[2] = Qt::Key_W;
    mover[3] = Qt::Key_S;
    mover[4] = Qt::Key_Space;

}

void clase_base::enemies_cicular()
{
    enemies *enemy= dynamic_cast<enemies*>(enemigo[1]);
    enemy->start_zigzag_movement();
}

bool clase_base::limites(bool limite)
{
    int posicion = bola1->x();

    if (limite) posicion -=8;
    else posicion +=8;

    if (posicion < -5 || posicion > 1500){
        return false;
    }
    return true;
}

void clase_base::terminar_level()
{
    time_level1->stop();
}

bool clase_base::saber_nivel()
{
    bool cual=time_level1->isActive();
    return cual;
}

void clase_base::disparar()
{

    bombas1.push_back(new proyectil(enemigo,bola1->x(), bola1->y()+100, graph->height(),":/nive1/personaje/bullet_222862.png"));
    //bombas1.push_back(new proyectil(enemigo, 0.03, 10.0, -1.0));
    connect(bombas1[bombas1.length()-1],SIGNAL(collition(QGraphicsItem*,int)),this,SLOT(quitar_disparo(QGraphicsItem*,int)));
    connect(bombas1[bombas1.length()-1],SIGNAL(fuera_de_rango(QGraphicsItem*)),this,SLOT(remove_shoot(QGraphicsItem*)));
    bombas1[bombas1.length()-1]->setPos(bola1->x()+100, bola1->y());
    scene->addItem(bombas1[bombas1.length()-1]);
    qDebug() << "Bala creada";
}


void clase_base::enemies_MRU()
{
    enemies *enemigo1=dynamic_cast<enemies*>(enemigo[1]);
    enemies *enemigo2=dynamic_cast<enemies*>(enemigo[2]);
    enemigo1->start_zigzag_movement();
    enemigo2->start_parabolic_movement(-900,0);

}

