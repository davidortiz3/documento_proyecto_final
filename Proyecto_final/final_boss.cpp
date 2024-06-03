#include "final_boss.h"

Final_boss::Final_boss() {

    pixmap_management = new sprites(":/nive1/personaje/kisspng-metal-slug-6-metal-slug-7-metal-slug-advance-metal-sprite-5ad6e7616174e7.7483900015240333773992.png", 1);
    pixmap_management->cut_character_pixmap(set_complete_sprites());
    pixmap_management->set_design_size(bossfinal_x_size, bossfinal_y_size);
    set_animations();
    setPixmap(pixmap_management->get_current_pixmap(3));
    setX(0);
    setY(0);
    timer_boss = new QTimer;
    connect(timer_boss, SIGNAL(timeout()), this, SLOT(MRU()));
    timer_boss->start(16);
}
Final_boss::~Final_boss(){
    delete pixmap_management;
}

void attackSpecialBoss();
void Final_boss::megaJump(int jumpHeight) {
    if (!onGround) {
        return;
    }
    start_parabolic_movement(0, int jumpHeight);
    onGround = false;
}

void Final_boss::attack1(personaje *player) {
    this->attack(player);
}
void attack2(){

}
void Final_boss::special1(personaje *player) {
    this->specialAttack(player);
}
void special2(){

}

QRect Final_boss::set_complete_sprites()
{
    QRect dim;

    dim.setX(0);
    dim.setY(0);
    dim.setHeight(23*bossfinal_y_size);
    dim.setWidth(23*bossfinal_x_size);

    return dim;
}

void Final_boss::set_animations()
{
    set_left_animation();
    set_right_animation();
    set_up_animation();
    set_down_animation();
    set_death_animation();
}

void Final_boss::set_left_animation()
{
    QRect dim;
    dim.setX(0);
    dim.setY(0);
    dim.setHeight(1*bossfinal_y_size);
    dim.setWidth(6*bossfinal_x_size);
    pixmap_management->add_new_animation(dim,6);
}

void Final_boss::set_right_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(8.5*bossfinal_y_size);
    dim.setHeight(1*bossfinal_y_size);
    dim.setWidth(12*bossfinal_x_size);

    pixmap_management->add_new_animation(dim,12);
}


void Final_boss::set_up_animation()
{
    QRect dim;

    dim.setX(3*bossfinal_x_size);
    dim.setY(1*bossfinal_y_size);
    dim.setHeight(1*bossfinal_y_size);
    dim.setWidth(3*bossfinal_x_size);

    pixmap_management->add_new_animation(dim,4);
}

void Final_boss::set_down_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(323);
    dim.setHeight(1*bossfinal_y_size);
    dim.setWidth(bossfinal_x_size);

    pixmap_management->add_new_animation(dim,13);
}

void Final_boss::set_death_animation()
{
    QRect dim;

    dim.setX(0);
    dim.setY(3.2*bossfinal_y_size);
    dim.setHeight(1*bossfinal_y_size);
    dim.setWidth(29*bossfinal_x_size);

    pixmap_management->add_new_animation(dim,7);
}

void Final_boss::start_move()
{
    set_starting_parameters_MCU(-150,0);
    timer_boss->start(16);
}
