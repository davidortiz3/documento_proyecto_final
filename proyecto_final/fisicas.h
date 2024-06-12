#ifndef FISICAS_H
#define FISICAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <cmath>
#include <QElapsedTimer>
#include <QKeyEvent>
#define time_step 1
#define system_scale 50

class fisicas : public QObject
{
    Q_OBJECT
public:
    fisicas(int z, int l, int h, QGraphicsPixmapItem *item);
    ~fisicas();
    int get_x();
    int get_y();
    void start_parabolic_movement(int largo, int alto);
    void start_MRU();
    void set_vx();
    void right();
    void set_vy();
    void start_zigzag_movement();
    void start_harmonic_movement(float amplitude, float frequency);
    void start_pendulum_motion(float length, float initial_angle);
    float z, l, vx, vy, ax, ay, g, x0, y0, vx0, vy0, n,r;
private:
    void set_pos_item();
    QGraphicsPixmapItem *item;
    QElapsedTimer time;
    QTimer *p_time, *default_movement;
    QTimer *z_time;
    QTimer *harmonic_time;
    QTimer *pendulum_time;
    double theta0=0.0, A=200.0;
    int h;
    void mover();
    int zigzag_counter;
    float amplitude;
    float frequency;
    float pendulum_length;
    float pendulum_angle;

private slots:
    void parabolic_shoot();
    void parabolic_shoot_bomba();
    void MRU();
    void set_starting_parameters(int x, int y, int vx, int vy);
    void zigzag();
    void mover_bala();
    void bomba();
    void harmonic_motion();
    void pendulum_motion();
};

#endif // FISICAS_H
