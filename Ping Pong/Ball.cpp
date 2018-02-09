#include "Ball.hpp"

void Ball::onTick(double deltaTime){
    xPos += xVelocity * deltaTime;
    yPos += yVelocity * deltaTime;
}

void Ball::onCollision(Bounds* other, side onSide){
    Bounds::onCollision(other, onSide);
    switch (onSide) {
        case Bounds::top:
            yVelocity = -std::abs(yVelocity);
            break;
        case Bounds::right:
            xVelocity = -std::abs(xVelocity);
            break;
        case Bounds::bottom:
            yVelocity = std::abs(yVelocity);
            break;
        case Bounds::left:
            xVelocity = std::abs(xVelocity);
            break;
        default:
            break;
    }
}
