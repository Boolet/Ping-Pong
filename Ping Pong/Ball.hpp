#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "Bound.hpp"

class Ball : public Bounds{
public:
    Ball(float x, float y):Bounds(x,y,1,1){}
    void Move(float deltaTime);
    void OnCollision(side onSide);
    
private:
    float xVelocity, yVelocity;
};

#endif /* Ball_hpp */
