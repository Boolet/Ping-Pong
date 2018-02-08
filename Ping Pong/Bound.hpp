#ifndef Bound_hpp
#define Bound_hpp

#include <stdio.h>
#include <vector>

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
    
    enum axis{
        xAxis, yAxis
    };
    
    enum side{
        top, bottom, right, left, none
    };
    
    bool isIntersecting(Bounds other);
    side intersectionSide(Bounds other);
    
protected:
    float xPos, yPos, width, height;
    Bounds intersectionArea(Bounds other);
    
    
    
};

#endif /* Bound_hpp */
