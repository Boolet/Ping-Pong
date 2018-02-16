#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include "Bound.hpp"
#include "Score.hpp"

class Paddle : public Bounds{
public:
    Paddle(float x, float y, float w, float h):Bounds(x,y,w,h){paddleScore = new Score();}
    void onCollision(Bounds* other, side onSide) override;
    
    int getScoreValue(){return paddleScore->score;}
    Score* getScoreRef(){return paddleScore;}
private:
    Score* paddleScore;
};

#endif /* Paddle_hpp */
