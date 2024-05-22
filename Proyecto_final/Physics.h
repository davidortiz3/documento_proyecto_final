#ifndef PHYSICS_H
#define PHYSICS_H

class Physics
{
public:
    float const gravity;
    float const friction;
    Physics(): gravity(9.8), friction(0.99) {}

    void applyGravity(float& velocityY){
        velocityY += gravity;
    }
    void applyFriction(float& velocityX){
        velocityX *= friction;
    }
    void applyParabolicMotion(float& posX, float& posY, float startVelocity, float angle, float time) {
        posX = startVelocity * cos(angle) * time;
        posY = startVelocity * sin(angle) * time - 0.5 * gravity * pow(time, 2);
    }
    void applyCircularMotion(float& posX, float& posY, float radio, float angle) {
        posX = radio * cos(angle);
        posY = radio * sin(angle);
    }
    void applyUniformMotion(float& posX, float velocity, float time) {
        posX += velocity * time;
    }
    void applySimpleHarmonicMotion(float& posX, float amplitude, float frequency, float time){
        posX = amplitude * cos(2*M_PI*frequency*time);
    }
};
#endif // PHYSICS_H
