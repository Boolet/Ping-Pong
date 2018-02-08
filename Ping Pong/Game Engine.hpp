#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#include <stdio.h>
#include "Paddle.hpp"
#include "Ball.hpp"

class GameEngine{
public:
    GameEngine();
    void GameTick(float deltaTime);
    
private:
    Paddle playerOne;
    Bounds rightWall, topWall, leftWall, bottomWall;
    Ball ball;
    
};

#endif /* Game_Engine_hpp */
