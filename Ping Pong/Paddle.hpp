#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include "Bound.hpp"

class Paddle : public Bounds{
public:
    Paddle(float x, float y, float w, float h):Bounds(x,y,w,h){}
    
};

#endif /* Paddle_hpp */
