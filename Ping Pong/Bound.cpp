#include "Bound.hpp"

bool Bounds::isIntersecting(Bounds* other){
    return !(other->xPos + other->width < xPos ||
            other->yPos + other->height < yPos ||
            xPos + width < other->xPos ||
            yPos + height < other->yPos);
}

Bounds Bounds::intersectionArea(Bounds* other){
    return Bounds(std::max(xPos, other->xPos),
                  std::max(yPos, other->yPos),
                  std::min(xPos+width,other->xPos+other->width),
                  std::min(yPos+height,other->yPos+other->height));
}

Bounds::side Bounds::intersectionSide(Bounds* other){
    if(!isIntersecting(other))
        return none;
    
    Bounds collisionArea = intersectionArea(other);
    
    if(collisionArea.width > collisionArea.height){
        //top or bottom
        if(collisionArea.yPos == yPos)
            return top;
        else return bottom;
    } else {
        //right or left
        if(collisionArea.xPos == xPos)
            return left;
        else return right;
    }
}

void Bounds::onCollision(Bounds* other, side onSide){
    intersectors.push_back(other);
}

void Bounds::onEndFrame(){
    intersectLastFrame = intersectors;
    intersectors.clear();
}
