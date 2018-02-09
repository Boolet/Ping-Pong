#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <cmath>
#include "Bound.hpp"

class Ball : public Bounds{
public:
    Ball(float x, float y):Bounds(x,y,1,1){}
    void onTick(double deltaTime) override;
    void onCollision(Bounds* other, side onSide) override;
    
private:
    float xVelocity, yVelocity;
};

#endif /* Ball_hpp */
