#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <cmath>
#include "Bound.hpp"

class Ball : public Bounds{
public:
    Ball(double x, double y):Bounds(x,y,5,5,"ball"), xVelocity(50), yVelocity(30){}
    void onTick(double deltaTime) override;
    void onCollision(Bounds* other, side onSide) override;
    
private:
    double xVelocity, yVelocity;
};

#endif /* Ball_hpp */
