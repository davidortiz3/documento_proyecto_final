#include "clase_base.h"

clase_base::clase_base(QGraphicsView *graph) {
    this->graph = graph;
    time_level1=new QTimer;
    nivel1();
    connect(time_level1, SIGNAL(timeout()), this, SLOT(level2()));
    /*
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,graph->width()-2,graph->height()-2);
    graph->setScene(scene);
    bola1 = new personaje(100,323,graph->height());
    plataforma=new escenario(0,0);
    obstaculo1= new obstaculo(0,0, graph->height());
    obstaculo2= new obstaculo(0,0,graph->height());
    enemigo1= new enemies(700,196,graph->height(), -1.0);
    set_bomberman_keys();
    bola1->set_keys(mover);
    scene->addItem(plataforma);
    scene->addItem(bola1);
    scene->addItem(enemigo1);
    scene->addItem(obstaculo1);
    set_focus_element(bola1,40*2,0);
    setup_enemigo();
    enemies_MRU();
   */
}



clase_base::~clase_base()
{
    delete scene;
    delete bola1;
    delete plataforma;
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
            disparar2();
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

void clase_base::setup_nbombs()
{
    nbombs.push_back(new NuclearBombs(70, 100, graf->height(), bola1, ":/nbomb.png"));
    nbombs.push_back(new NuclearBombs(90, 100, graf->height(), bola1, ":/nbomb.png"));
}


void clase_base::set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex, unsigned int scaley)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());


}

void clase_base::nivel1()
{
    mapa(":/nive1/escenario/Captura de pantalla_29-5-2024_191835_.jpeg");
    time_level1->start(6000);
    soldado(":/nive1/pngfind.com-metal-slug-png-4743164.png");
    setup_enemigo();
    enemies_MRU();
}

void clase_base::level2()
{
    mapa(":/nive1/escenario/nivel1.jpg");
    terminar_level();
    arma_level2();
}

void clase_base::disparar2()
{
    bombas2.push_back(new arma(0.3,10.0,-1.0));
    bombas2[bombas2.length()-1]->setPos(bola2->x(), bola2->y());
    scene->addItem(bombas2[bombas2.length()-1]);
    qDebug() << "Bala creada";
}

void clase_base::mapa(QString level)
{
    /*int new_width = 370;
    int new_height = 600;
    //graph->setGeometry(0, 0, new_width, new_height);
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0,graph->width() - 2, graph->height()- 2);
    graph->setScene(scene);
    QPixmap background(level);
    scene->setBackgroundBrush(background);*/
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
        plataforma2=new nivel2(0,0,level);
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
    enemigo[1]->startCircularMovement();
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

    //scene->clear();
    //delete plataforma;
}

bool clase_base::saber_nivel()
{
    bool cual=time_level1->isActive();
    return cual;
}

void clase_base::disparar()
{
    bombas1.push_back(new proyectil(bola1->x(), bola1->y()+100, graph->height(),":/nive1/personaje/bullet_222862.png"));
    bombas1[bombas1.length()-1]->setPos(bola1->x(), bola1->y());
    scene->addItem(bombas1[bombas1.length()-1]);
    qDebug() << "Bala creada";
}


void clase_base::enemies_MRU()
{
    enemigo[0]->start_MRU();
    enemigo[1]->start_MRU();

}

/*std::vector<std::string>readFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file) {
        std::cerr << "No se pudo abrir el archivo " << fileName << std::endl;
        return {};
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, lines)) {
        lines.push_back(line);
    }
    return lines;
}*/

void clase_base::nuclearBombs_move()
{
    nbombs[0]->nbomb_move();
    nbombs[1]->nbomb_move();

}
