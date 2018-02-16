#ifndef Game_Engine_hpp
#define Game_Engine_hpp

#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include <stdio.h>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Score.hpp"
#include <chrono>
#include <iostream>

#define MILLISECONDS_TO_SECONDS 0.001

class GameEngine{
public:
    GameEngine(float width, float height);
    void Run();
    void ManualTick(double manualDeltaTime);
    void ManualTick();
    
    void UserInput(float deltaX);    //JUST using one value for now; this is a crummy way to implement this
    
    std::vector<Bounds*> getColliderData(){return ballColliders;}
    //std::vector<score*> getScores(){return Paddle::getScores();}
    
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
