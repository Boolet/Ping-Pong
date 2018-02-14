#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#include <stdio.h>
#include <unistd.h>
#include "Paddle.hpp"
#include "Ball.hpp"
#include <chrono>
#include <iostream>

#define MILLISECONDS_TO_SECONDS 0.001

class GameEngine{
public:
    GameEngine(float width, float height);
    void Run();
    
    std::vector<Bounds*> getColliderData(){return ballColliders;}
    
private:
    float gameWidth, gameHeight;
    Paddle playerOne;
    Bounds rightWall, topWall, leftWall, bottomWall;
    Ball ball;
  
    std::vector<Bounds*> ballColliders;
    
    time_t timer;
    double startTime = 0;
    double localTime = 0;
    double timeLastFrame = 0;
    double deltaTime = 0;
    
    void GameTick(double deltaTime);
    
    void Update(double deltaTime);
    void RunCollisions();
    void Cleanup();
};

#endif /* Game_Engine_hpp */
