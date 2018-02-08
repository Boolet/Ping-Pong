#ifndef Bound_hpp
#define Bound_hpp

#include <stdio.h>

class Bounds{
public:
    Bounds(float x, float y, float w, float h){
        //top left corner coordinates
        xPos = x;
        yPos = y;
        
        //bottom right offset
        width = w;
        height = h;
    }
    
    bool isIntersecting(Bounds other);
    
private:
    float xPos, yPos, width, height;
    
    
    
};

#endif /* Bound_hpp */
