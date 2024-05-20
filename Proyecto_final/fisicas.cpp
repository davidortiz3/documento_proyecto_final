#include "fisicas.h"

fisicas::fisicas(int z, int l, int h, QGraphicsPixmapItem *item):angle(0), radius(100), centerX(200), centerY(200),amplitude(100), frequency(1), phase(0)
{
    this->item = item;
    this->z = z;
    this->l = h-l;
    this->h = h;
    vy = 0;
    vx = system_scale*0;
    vx0 = vx;
    vy0 = vy;
    x0=z;
    y0 = l;
    g = system_scale*9.8;
    n=0;


    p_time = new QTimer;
    default_movement = new QTimer;
    timer = new QTimer;
    timer_osc= new  QTimer;
    connect(timer_osc,SIGNAL(timeout()),this,SLOT(oscillatory_movement()));
    connect(timer,SIGNAL(timeout()), this,SLOT(MCU()));
    connect(p_time,SIGNAL(timeout()),this,SLOT(parabolic_shoot()));
    connect(default_movement,SIGNAL(timeout()),this,SLOT(MRU()));
    default_movement->start(time_step);
}

fisicas::~fisicas()
{
    delete p_time;
}

void fisicas::start_parabolic_movement()
{

    default_movement->stop();
    set_starting_parameters(z,l,0,-800);
    p_time->start(time_step);
}

void fisicas::start_MRU()
{
    default_movement->stop();
    set_starting_parameters(z,l,0,-800);
    p_time->start(time_step);
}


void fisicas::set_vx()
{
    vx+=system_scale*2;
}

void fisicas::right()
{
    item->setPos(item->x()+10, item->y());
}

void fisicas::startCircularMovement()
{
    timer->start(16);
}

void fisicas::stopCircularMovement()
{
    timer->stop();
}

void fisicas::start_oscillation()
{
    timer_osc->start(16);
}


void fisicas::set_pos_item()
{
    item->setX(z);
    item->setY(h-l);
}

/*bool fisicas::verificar()
{
    bool salto;
    if(l-90 <=0){
        salto=true;
    }else{
        salto=false;
    }
    return salto;
}*/

void fisicas::parabolic_shoot()
{

        float t = ((time_step/1000.0)*n);
        vx = vx0;
        vy = vy-g*t;
        z = x0+vx0*t;
        l = y0-vy0*t-(g*t*t)/2;
        n++;
        set_pos_item();

    /*if(l-90 <=0) {
        set_starting_parameters(z,l,vx,100);
        p_time->stop();
        default_movement->start(time_step);
        p_time->stop();
        default_movement->stop();
    }*/
}

void fisicas::MRU()
{
    float t = ((time_step/1000.0)*n);
    z = x0+vx0*t;
    l = y0+vy0*t;
    n++;
    set_pos_item();
}

void fisicas::set_starting_parameters(int z, int l, int vx, int vy)
{
    x0 = z;
    y0 = l;
    vx0 = vx;
    vy0 = vy;
    n=0;
}

void fisicas::MCU()
{
    angle += 0.05; // Increment angle
    if (angle >= 2 * M_PI) {
        angle = 0; // Reset angle to keep it within 0 to 2*PI
    }
    z = centerX + radius * std::cos(angle);
    l = centerY + radius * std::sin(angle);
    set_pos_item();
}

void fisicas::oscillatory_movement()
{
    float t = time.elapsed() / 1000.0; // Tiempo en segundos
    z = amplitude * std::cos(2 * M_PI * frequency * t + phase);
    l = startY + amplitude * sin(2 * M_PI * frequency * t);
    set_pos_item();
}
