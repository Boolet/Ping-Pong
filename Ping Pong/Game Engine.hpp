#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#include <stdio.h>
#include "Paddle.hpp"
#include "Ball.hpp"

class GameEngine{
public:
    GameEngine(float width, float height);
    void GameTick(float deltaTime);
    
private:
    float gameWidth, gameHeight;
    Paddle playerOne;
    Bounds rightWall, topWall, leftWall, bottomWall;
    Ball ball;
  
    Bounds** ballColliders;
    
    void RunCollisions();
};

#endif /* Game_Engine_hpp */
