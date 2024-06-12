#include "clase_base.h"

clase_base::clase_base(QGraphicsView *graph) {
    this->graph = graph;
    time_level1=new QTimer;
    nivel1();
    connect(time_level1, SIGNAL(timeout()), this, SLOT(level2()));
    //level2();
}

clase_base::~clase_base()
{
    delete scene;
    delete bola1;
    delete plataforma;
    delete scene2;
    delete scene3;
    for(int i=0; i<enemigo.length(); i++){
        delete enemigo[i];
    }
    for(int i=0; i<bombas1.length(); i++){
        delete bombas1[i];
    }
    for(int i=0; i<bombas2.length(); i++){
        delete bombas2[i];
    }
    enemigo.clear();
    bombas1.clear();
    bombas2.clear();
    bombas3.clear();
}

void clase_base::keyPressEvent(QKeyEvent *keys)
{
    bool nivel=saber_nivel();
    if(nivel){
        if(bola1->x()<1600 || bola1->y()>600){
            set_focus_element(bola1,40*2);
        }
        if(unsigned(keys->key()) == mover[0])bola1->mover(keys->key(),limites(true));
        else if(unsigned(keys->key()) == mover[1])bola1->mover(keys->key(),limites(false));
        else if(unsigned(keys->key()) == mover[2]) bola1->mover(keys->key(), true);
        else if(unsigned(keys->key()) == mover[3]) disparar();
        else if(unsigned(keys->key()) == mover[4]);bola1->mover(keys->key(),true);
    }else{
        if(bola2->x()<1600 || bola2->y()>600){
            set_focus_element(bola2,40*2);
        }
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

    enemigo.push_back(new enemies(3000,0,graph->height(), -1.0,":/nive1/personaje/volar.png"));
    enemigo.push_back(new enemies(1100,0,graph->height(), -1.0,":/nive1/personaje/volar.png"));
    enemigo.push_back(new enemies(1800,0,graph->height(), -1.0,":/nive1/personaje/volar.png"));

    for(short i=0; i<enemigo.length(); i++) scene->addItem(enemigo[i]);
}

void clase_base::setup_enemigo2()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(65,750);
    int number = dis(gen);
    bombas2.push_back(new NuclearBombs(number,700, graph->height(),":/nive1/bomba.png"));
    connect(bombas2[bombas2.length()-1],SIGNAL(explosion(QGraphicsItem*)),this,SLOT(quitar_item(QGraphicsItem*)));
    scene2->addItem(bombas2[bombas2.length()-1]);
}


void clase_base::set_focus_element(QGraphicsPixmapItem *item, unsigned int scalex)
{
    scene->setSceneRect(item->x()+scalex-scene->width()/2,0,scene->width(),scene->height());
}

void clase_base::nivel1()
{
    mapa(":/nive1/escenario/Captura de pantalla_29-5-2024_191835_.jpeg");
    time_level1->start(45000);
    setup_enemigo();
    soldado(":/nive1/pngfind.com-metal-slug-png-4743164.png");
    //final_nivel();
    enemies_MRU();

}

void clase_base::level2()
{
    timer_bomba=new QTimer;
    time_fin=new QTimer;
    mapa(":/nive1/escenario/piso_nivel2.png");
    terminar_level();
    arma_level2();
    setup_helicoptero();
    fisicas_helicoptero();
    //soldado(":/nive1/pngfind.com-metal-slug-png-4743164.png");
    connect(timer_bomba,SIGNAL(timeout()),this,SLOT(setup_enemigo2()));
    connect(time_fin,SIGNAL(timeout()),this,SLOT(terminar_level2()));
    timer_bomba->start(2000);
    time_fin->start(60000);
}

void clase_base::quitar_disparo(QGraphicsItem *shoot)
{
    scene->removeItem(shoot);
}

void clase_base::quitar_item(QGraphicsItem *shoot)
{
    scene2->removeItem(shoot);
    for(int i=0; i<bombas2.length(); i++){
        if(bombas2[i] == shoot){
            //enemies* enemy=dynamic_cast<enemies*>(enemigo[i]);
            disconnect(bombas2[i]);
            bombas2.remove(i);
            break;
        }
    }
}

void clase_base::remove_shoot(QGraphicsItem *shoot, int n)
{
    scene->removeItem(enemigo[n]);
    enemigo.remove(n);
    for(int i=0; i<enemigo.length(); i++){
        if(enemigo[i] == shoot){
            enemies* enemy=dynamic_cast<enemies*>(enemigo[i]);
            disconnect(enemy);
            //enemigo.remove(i);
            break;
        }
    }
}

void clase_base::quitar_bomba(QGraphicsItem *shoot, int n)
{
    //scene2->removeItem(shoot);
    scene2->removeItem(bombas2[n]);
    bombas2.remove(n);
    puntaje+=30;
    for(int i=0; i<bombas2.length(); i++){
        if(bombas2[i] == shoot){
            disconnect(bombas2[i]);
            //bombas2.remove(i);
            //scene2->removeItem(bombas2[i]);
            break;
        }
    }
}

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
        scene2 = new QGraphicsScene;
        scene2->setSceneRect(0,0,graph->width()-2,graph->height()-2);
        graph->setScene(scene2);
        plataforma2=new nivel2(0,-1350,level);
        scene2->addItem(plataforma2);
    }
}

void clase_base::soldado(const QString usuario)
{
    bola1 = new personaje(enemigo,100,323,graph->height(),usuario);
    set_bomberman_keys();
    bola1->set_keys(mover);
    scene->addItem(bola1);
    set_focus_element(bola1,40*2);
    //connect(bola1,SIGNAL(choque(int)),this,SLOT(quitar_enemigo(int)));
}

void clase_base::quitar_enemigo(int n)
{
    scene->removeItem(enemigo[n]);
}

void clase_base::arma_level2()
{
    bola2=new arma(1);
    set_bomberman_keys();
    bola2->set_keys(mover);
    scene2->addItem(bola2);
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


bool clase_base::limites(bool limite)
{
    int posicion = bola1->x();
    if (limite) posicion -=8;
    else posicion +=8;
    if (posicion < -5 || posicion > 1800){
        return false;
    }
    return true;
}

void clase_base::terminar_level()
{
    time_level1->stop();
    //scene->clear();
    enemigo.clear();
    bombas1.clear();
}

void clase_base::terminar_level2()
{
    plataforma3=new escenario(0,0,":/nive1/escenario/Neo Geo NGCD - Metal Slug - Game Over Screen.png");
    scene3 = new QGraphicsScene;
    scene3->setSceneRect(0,0,graph->width()-2,graph->height()-2);
    scene3->addItem(plataforma3);
    scene->clear();
    scene2->clear();
}

bool clase_base::saber_nivel()
{
    bool cual=time_level1->isActive();
    return cual;
}

void clase_base::escribir_archivo(const QString &archivo, const QString &contenido)
{
    QFile file(archivo);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se puede abrir el archivo para escritura";
        return;
    }

    QTextStream out(&file);
    out << contenido;

    file.close();
}

QString clase_base::leer_archivo(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se puede abrir el archivo para lectura";
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString dato = in.readLine();
        //qDebug() << line;
        return dato;
    }

    file.close();
}

void clase_base::setup_helicoptero()
{
    helicoptero.push_back(new NuclearBombs(70, 100,graph->height(),":/nive1/personaje/pngegg (1).png"));
    helicoptero.push_back(new NuclearBombs(400, 100,graph->height(),":/nive1/personaje/depositphotos_537901280-stock-illustration-military-plane-front-view-green.png"));
    for(int i=0; i<helicoptero.length();i++){
        scene2->addItem(helicoptero[i]);
    }
}

void clase_base::fisicas_helicoptero()
{
    helicoptero[0]->start_pendulum_motion(50,200);
    helicoptero[1]->start_harmonic_movement(100,1);
}

void clase_base::disparar()
{
    bombas1.push_back(new proyectil(enemigo,":/nive1/personaje/bullet_222862.png"));
    connect(bombas1[bombas1.length()-1],SIGNAL(collition(QGraphicsItem*,int)),this,SLOT(remove_shoot(QGraphicsItem*,int)));
    connect(bombas1[bombas1.length()-1],SIGNAL(fuera_de_rango(QGraphicsItem*)),this,SLOT(quitar_disparo(QGraphicsItem*)));
    bombas1[bombas1.length()-1]->setPos(bola1->x(), bola1->y());
    scene->addItem(bombas1[bombas1.length()-1]);
    qDebug() << "Bala creada";
}

void clase_base::disparar2()
{
    bombas3.push_back(new bombas(bombas2,":/nive1/pngegg (1).png"));
    connect(bombas3[bombas3.length()-1],SIGNAL(colision(QGraphicsItem*,int)),this,SLOT(quitar_bomba(QGraphicsItem*,int)));
    //connect(bombas3[bombas3.length()-1],SIGNAL(quitar(QGraphicsItem*)),this,SLOT(quitar_item(QGraphicsItem*)));
    bombas3[bombas3.length()-1]->setPos(bola2->x()+50, bola2->y());
    scene2->addItem(bombas3[bombas3.length()-1]);
    //qDebug() << "Bala creada";

}
void clase_base::enemies_MRU()
{
    enemies *enemigo1=dynamic_cast<enemies*>(enemigo[1]);
    enemies *enemigo2=dynamic_cast<enemies*>(enemigo[2]);
    enemies *enemigo3=dynamic_cast<enemies*>(enemigo[0]);
    /*enemigo1->start_parabolic_movement(-150,0);
    enemigo2->start_parabolic_movement(-150,0);
    enemigo3->start_parabolic_movement(-150,0);*/
}

void clase_base::final_nivel()
{
    map=new plano(100,100,graph->height(),":/nive1/personaje/mapa.png");
    scene->addItem(map);
    map->start_pendulum_motion(100,10);
}
