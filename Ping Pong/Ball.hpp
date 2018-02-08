#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "Bound.hpp"

class Ball : Bounds{
public:
    void Move(float deltaTime);
    
private:
    float xVelocity, yVelocity;
};

#endif /* Ball_hpp */
