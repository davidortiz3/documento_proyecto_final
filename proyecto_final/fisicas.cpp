#include "fisicas.h"

fisicas::fisicas(int z, int l, int h, QGraphicsPixmapItem *item)
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
    zigzag_counter = 0;
    amplitude = 0;
    frequency = 0;
    pendulum_length = 0;
    pendulum_angle = 0;


    p_time = new QTimer;
    default_movement = new QTimer;
    z_time = new QTimer;
    harmonic_time = new QTimer;
    pendulum_time = new QTimer;

    connect(p_time,SIGNAL(timeout()),this,SLOT(parabolic_shoot()));
    connect(default_movement,SIGNAL(timeout()),this,SLOT(MRU()));
    connect(z_time, SIGNAL(timeout()), this, SLOT(zigzag()));
    connect(harmonic_time, SIGNAL(timeout()), this, SLOT(harmonic_motion()));
    connect(pendulum_time, SIGNAL(timeout()), this, SLOT(pendulum_motion()));
    default_movement->start(time_step);
}

fisicas::~fisicas()
{
    delete p_time;
    delete default_movement;
    delete z_time;
    delete harmonic_time;
    delete pendulum_time;
}

void fisicas::start_parabolic_movement(int largo, int alto)
{

    default_movement->stop();
    set_starting_parameters(z,l,largo,alto);
    p_time->start(time_step);

}


void fisicas::start_MRU()
{

    default_movement->stop();
    set_starting_parameters(z,l,-200,0);
    p_time->start(time_step);
}


void fisicas::set_vx()
{
    vx+=system_scale*2;
}

void fisicas::right()
{
    default_movement->stop();
    item->setPos(item->x()-150, item->y());
}

void fisicas::set_pos_item()
{
    item->setX(z);
    item->setY(h-l);
}

void fisicas::mover_bala()
{
    default_movement->stop();
    set_starting_parameters(z,l,100,-150);
    p_time->start(time_step);
}

void fisicas::bomba()
{
    default_movement->stop();
    set_starting_parameters(z,l,0,-330);
    p_time->start(time_step);
}

void fisicas::zigzag()
{
    if (zigzag_counter % 200 < 100) {
        vx = 30;
    } else {
        vx = -30;
    }

    float t = (time_step / 20000.0) * n;
    z = x0 + vx * t;
    l = y0 + vy0 * t + 0.5 * g * t * t;
    n++;
    zigzag_counter++;
    set_pos_item();
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
        p_time->stop();
        l=324;
    }
}

void fisicas::parabolic_shoot_bomba()
{
    default_movement->stop();
    float t = ((time_step/1000.0)*n);
    vx = vx0;
    vy = vy-g*t;
    z = x0+vx0*t;
    l = y0-vy0*t-(g*t*t)/2;
    n++;
    set_pos_item();
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

void fisicas::harmonic_motion()
{
    float t = (time_step / 1000.0) * n;
    l = x0;
    z = y0 + amplitude * cos(frequency * t);
    n++;
    set_pos_item();
}

void fisicas::pendulum_motion()
{
    float t = (time_step / 60000.0) * n;
    float angular_frequency = sqrt(g / pendulum_length);
    pendulum_angle = pendulum_angle * cos(angular_frequency * t);
    z = x0 + pendulum_length * sin(pendulum_angle);
    l = y0 + pendulum_length * cos(pendulum_angle)+vy0 * t + 0.5 * g * t * t;
    n++;
    set_pos_item();
}

void fisicas::start_zigzag_movement()
{
    p_time->stop();
    harmonic_time->stop();
    pendulum_time->stop();
    default_movement->stop();
    p_time->stop();
    set_starting_parameters(z, l, 10, 0);
    zigzag_counter = 0;
    z_time->start(time_step);


}

void fisicas::start_harmonic_movement(float amplitude, float frequency)
{
    default_movement->stop();
    p_time->stop();
    z_time->stop();
    this->amplitude = -amplitude;
    this->frequency = frequency;
    set_starting_parameters(z, l, 0, 0);
    n = 0;
    harmonic_time->start(time_step);
}

void fisicas::start_pendulum_motion(float length, float initial_angle)
{
    default_movement->stop();
    p_time->stop();
    z_time->stop();
    harmonic_time->stop();

    this->pendulum_length = length;
    this->pendulum_angle = initial_angle;

    set_starting_parameters(z, l, 0, 0);
    n = 0;
    pendulum_time->start(time_step);
}
