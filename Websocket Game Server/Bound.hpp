#ifndef Bound_hpp
#define Bound_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Score.hpp"

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
    
    class CollisionBehavior{
    public:
        virtual void OnCollision(Bounds* other){}
    };
    
    class ResetScore : public CollisionBehavior{
    public:
        ResetScore(Score* target):targetScore(target){};
        
        void OnCollision(Bounds* other) override;
        
        Score* targetScore;
    };
    
    //getters
    std::string getName(){return name;}
    double getX(){return xPos;}
    double getY(){return yPos;}
    double getWidth(){return width;}
    double getHeight(){return height;}
    
    //setters
    void setName(std::string newName){name = newName;}
    void setX(float newX){xPos = newX;}
    void setY(float newY){yPos = newY;}
    void setWidth(float newWidth){width = newWidth;}
    void setHeight(float newHeight){height = newHeight;}
    
    //mutators
    void addCollisionBehavior(CollisionBehavior* behave);
    
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
    
    std::vector<CollisionBehavior*> onCollisionBehaviors;
    
    
};

#endif /* Bound_hpp */
