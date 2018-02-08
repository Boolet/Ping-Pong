#include "Ball.hpp"

void Ball::Move(float deltaTime){
    xPos += xVelocity * deltaTime;
    yPos += yVelocity * deltaTime;
}
