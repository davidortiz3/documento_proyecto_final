#ifndef FISICAS_H
#define FISICAS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <cmath>
#include <QElapsedTimer>
#include <QKeyEvent>
#define time_step 1
#define system_scale 200

class fisicas : public QObject
{
    Q_OBJECT
public:
    fisicas(int z, int l, int h, QGraphicsPixmapItem *item);
    ~fisicas();
    int get_x();
    int get_y();
    void start_parabolic_movement();
    void set_starting_parameters_MCU(int z, int l);
    void start_MRU();
    void set_vx();
    void right();
    void startCircularMovement();
    void stopCircularMovement();
    void start_oscillation();
private:
    void set_pos_item();
    QGraphicsPixmapItem *item;
    QElapsedTimer time;
    QTimer *p_time, *default_movement, *timer, *timer_osc;
    float z, l, vx, vy, ax, ay, g, x0, y0, vx0, vy0, n,r;
    double g1=200*9.8, theta0=0.0, A=200.0;
    int h;
    bool verificar();
    qreal angle,phase, radius,centerX,centerY,amplitude,frequency, startY = 100;

private slots:
    void parabolic_shoot();
    void MRU();
    void set_starting_parameters(int x, int y, int vx, int vy);
    void MCU();
    void oscillatory_movement();
};

#endif // FISICAS_H
