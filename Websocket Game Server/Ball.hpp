#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <cmath>
#include "Bound.hpp"

class Ball : public Bounds{
public:
    Ball(double x, double y):Bounds(x,y,1,1,"ball"), xVelocity(0), yVelocity(50){}
    void onTick(double deltaTime) override;
    void onCollision(Bounds* other, side onSide) override;
    
private:
    double xVelocity, yVelocity;
};

#endif /* Ball_hpp */
