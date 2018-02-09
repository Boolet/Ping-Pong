#include "Game Engine.hpp"

GameEngine::GameEngine(float width, float height):
gameWidth(width),
gameHeight(height),
leftWall(0, 0, 1, height),
topWall(0,0,width,1),
rightWall(width, 0, 1, height),
bottomWall(0, height, width, 1),
playerOne(width-1, height-1, 3, 1),
ball(width, height)
{
    ballColliders.push_back(&leftWall);
    ballColliders.push_back(&topWall);
    ballColliders.push_back(&rightWall);
    ballColliders.push_back(&bottomWall);
    ballColliders.push_back(&playerOne);
    ballColliders.push_back(&ball);
    
}

void GameEngine::Run(){
    localTime = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
    while(true){
        timeLastFrame = localTime;
        usleep(1000);
        localTime = std::chrono::duration_cast< std::chrono::milliseconds >(
                    std::chrono::system_clock::now().time_since_epoch()).count();
        GameTick((localTime - timeLastFrame) * MILLISECONDS_TO_SECONDS);
    }
}

void GameEngine::GameTick(double deltaTime){
    RunCollisions();
    Update(deltaTime);
    Cleanup();
}

void GameEngine::RunCollisions(){
    for(int i = 0; i < ballColliders.size(); ++i){
        for(int j = i+1; j < ballColliders.size(); ++j){
            Bounds::side hitSide = ballColliders[i]->intersectionSide(ballColliders[j]);
            if(hitSide != Bounds::none){
                ballColliders[i]->onCollision(ballColliders[j], hitSide);
            }
        }
    }
}

void GameEngine::Update(double deltaTime){
    for(int i = 0; i < ballColliders.size(); ++i){
        ballColliders[i]->onTick(deltaTime);
    }
}

void GameEngine::Cleanup(){
    for(int i = 0; i < ballColliders.size(); ++i){
        ballColliders[i]->onEndFrame();
    }
}
