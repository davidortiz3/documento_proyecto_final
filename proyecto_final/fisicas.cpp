#include "fisicas.h"

fisicas::fisicas(int z, int l, int h, QGraphicsPixmapItem *item):angle(0), radius(100), centerX(200), centerY(200),amplitude(100), frequency(1), phase(0),angularAcceleration(0), angularVelocity(1)
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
    connect(timer,SIGNAL(timeout()), this,SLOT(movimiento_circular()));
    connect(p_time,SIGNAL(timeout()),this,SLOT(parabolic_shoot()));
    connect(default_movement,SIGNAL(timeout()),this,SLOT(MRU()));
    connect(timer_osc,SIGNAL(timeout()),this,SLOT(updatePosition()));
    default_movement->start(time_step);

}

fisicas::~fisicas()
{
    delete p_time;
    delete default_movement;
    delete timer_osc;
    delete timer;
}

void fisicas::start_parabolic_movement(int largo, int alto)
{

    default_movement->stop();
    timer->stop();
    timer_osc->stop();
    set_starting_parameters(z,l,largo,alto);
    p_time->start(time_step);

}

void fisicas::set_starting_parameters_MCU(int z, int l)
{
    centerX = z;
    centerY = l;
}

void fisicas::start_MRU()
{

    default_movement->stop();
    stopCircularMovement();
    timer_osc->stop();
    set_starting_parameters(z,l,-600,0);
    p_time->start(time_step);
}


void fisicas::set_vx()
{
    vx+=system_scale*2;
}

void fisicas::right()
{
    default_movement->stop();
    item->setPos(item->x()+10, item->y());
}

void fisicas::startCircularMovement()
{
    set_starting_parameters_MCU(z,l);
    timer->stop();
    default_movement->stop();
    p_time->stop();
    timer->start(16);
}

void fisicas::stopCircularMovement()
{
    timer->stop();
}

void fisicas::start_oscillation()
{
    set_starting_parameters_MCU(z,l);
    timer->stop();
    default_movement->stop();
    p_time->stop();
    timer->stop();
    timer_osc->start(time_step);
}

void fisicas::movimiento_circular()
{
    qreal dt = 0.016;
    angularVelocity += angularAcceleration * dt;

    angle += angularVelocity * dt;
    z= 700 +radius * cos(angle);
    l= 330 +radius * sin(angle);
    if (angularVelocity >= 20) {
        angularVelocity = 1;
    }
    set_pos_item();

}


void fisicas::set_pos_item()
{
    item->setX(z);
    item->setY(h-l);
}

void fisicas::mover_bala()
{
    default_movement->stop();
    timer->stop();
    timer_osc->stop();
    set_starting_parameters(z,l,100,-150);
    p_time->start(time_step);
}


void fisicas::parabolic_shoot()
{

        float t = ((time_step/1000.0)*n);
        vx = vx0;
        vy = vy-g*t;
        z = x0+vx0*t;
        l = y0-vy0*t-(g*t*t)/2;
        n++;
        set_pos_item();

        if(l-323 <=0 ) {
                default_movement->stop();
                timer_osc->stop();
                p_time->stop();
                l=324;
        }
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
    angle += 0.05;
    if (angle >= 2 * M_PI) {
        angle = 0;
    }

    z = centerX + radius * std::cos(angle);
    l = centerY + radius * std::sin(angle);
    set_pos_item();


}

void fisicas::updatePosition()
{
    qreal angularAcceleration = (-9.81 / length) * std::sin(angle1 * M_PI / 180); // Aceleración angular
    angularVelocity += angularAcceleration * 0.016; // Incremento de velocidad angular en segundos (16 ms)
    angle1 += angularVelocity * 0.016; // Incremento de ángulo en segundos (16 ms)

    z = 200+length * sin(angle1 * M_PI / 180);
    l=347+length * cos(angle1 * M_PI / 180);
    set_pos_item();
}

