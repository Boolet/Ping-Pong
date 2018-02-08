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
    ballColliders = new Bounds*[5];
    ballColliders[0] = &leftWall;
    ballColliders[1] = &topWall;
    ballColliders[2] = &rightWall;
    ballColliders[3] = &bottomWall;
    ballColliders[4] = &playerOne;
}

void GameEngine::GameTick(float deltaTime){
    ball.Move(deltaTime);
    RunCollisions();
}

void GameEngine::RunCollisions(){
    for(int i = 0; i < 5; ++i){
        Bounds::side hitSide = ball.intersectionSide(*ballColliders[i]);
        if(hitSide != Bounds::none){
            ball.OnCollision(hitSide);
        }
    }
}
