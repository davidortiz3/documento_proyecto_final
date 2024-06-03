#include "arma.h"

arma::arma(float scale, float speed, float direction) {
    pixmap_management = new sprites(":/nive1/personaje/pngkit_game-sprite-png_2414663.png",scale);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(arma_x_size, arma_y_size);
    //setPixmap();
    set_animations();
    setX(1*arma_y_size*scale);
    setY(1*arma_x_size*scale);
    setPixmap(pixmap_management->get_current_pixmap(0));
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void arma::set_keys(unsigned int *keys)
{
    for(unsigned int i=0;i<4;i++) this->keys[i] = keys[i];
}

void arma::mover(unsigned int key, bool is_valid)
{
    if(key == keys[0]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) setX(x()-arma_velocidad);
    }
    else if(key == keys[1]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid) setX(x()+arma_velocidad);
    }
    else if(key == keys[2]){
        setPixmap(pixmap_management->get_current_pixmap(0));
        if(is_valid);
    }
}

arma::~arma()
{
    delete pixmap_management;
}

QRect arma::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*arma_y_size);
    dim.setWidth(8*arma_x_size);

    return dim;
}

void arma::set_animations()
{
    set_down_animation();
}


void arma::set_down_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*arma_y_size);
    dim.setWidth(8*arma_x_size);

    pixmap_management->add_new_animation(dim,8);
}

void arma::move()
{
    setPos(x(), y() + direction * speed);
    //if(test_collition() || test_range()) delete this;
}
