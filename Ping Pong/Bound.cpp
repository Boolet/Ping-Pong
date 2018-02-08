#include "Bound.hpp"

bool Bounds::isIntersecting(Bounds other){
    return !(other.xPos + other.width < xPos ||
            other.yPos + other.height < yPos ||
            xPos + width < other.xPos ||
            yPos + height < other.yPos);
}
