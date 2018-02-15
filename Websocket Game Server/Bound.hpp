#ifndef Bound_hpp
#define Bound_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

#define DEFAULT_NAME "Default"

class Bounds{
public:
    Bounds(double x, double y, double w, double h, std::string newName = DEFAULT_NAME){
        //top left corner coordinates
        xPos = x;
        yPos = y;
        
        //bottom right offset
        width = w;
        height = h;
        
        name = newName;
    }
    
    enum axis{
        xAxis, yAxis
    };
    
    enum side{
        top, bottom, right, left, none
    };
    
    //getters
    std::string getName(){return name;}
    double getX(){return xPos;}
    double getY(){return yPos;}
    double getWidth(){return width;}
    double getHeight(){return height;}
    
    //setters
    void setX(float newX){xPos = newX;}
    void setY(float newY){yPos = newY;}
    void setWidth(float newWidth){width = newWidth;}
    void setHeight(float newHeight){height = newHeight;}
    
    //game engine stuff
    bool isIntersecting(Bounds* other);
    side intersectionSide(Bounds* other);
    virtual void onCollision(Bounds* other, side onSide);
    virtual void onTick(double deltaTime){};
    void onEndFrame();
    
protected:
    double xPos, yPos, width, height;
    std::string name = DEFAULT_NAME;
    std::vector<Bounds*> intersectLastFrame;
    std::vector<Bounds*> intersectors;
    
    Bounds intersectionArea(Bounds* other);
    
    
    
};

#endif /* Bound_hpp */
