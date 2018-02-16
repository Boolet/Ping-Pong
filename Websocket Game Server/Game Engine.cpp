#include "Game Engine.hpp"

GameEngine::GameEngine(float width, float height):
gameWidth(width),
gameHeight(height),
leftWall(0, 0, 5, height),
topWall(0,0,width,5),
rightWall(width, 0, 5, height),
bottomWall(0, height, width, 5),
playerOne(10, height/2, 5, height/6),
ball(width/2, height/2)
{
    leftWall.addCollisionBehavior(new Bounds::ResetScore(playerOne.getScoreRef()));
    
    ballColliders.push_back(&leftWall);
    ballColliders.push_back(&topWall);
    ballColliders.push_back(&rightWall);
    ballColliders.push_back(&bottomWall);
    ballColliders.push_back(&playerOne);
    ballColliders.push_back(&ball);
    
    startTime = localTime = timeLastFrame = std::chrono::duration_cast< std::chrono::milliseconds >(
               std::chrono::system_clock::now().time_since_epoch()).count();
    
}

void GameEngine::Run(){
    startTime = localTime = timeLastFrame = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
    
    while(true){
        if(deltaTime > 0)   //if there was an update last frame, then update the time of last frame
            timeLastFrame = localTime;
        
        //Sleep(1);
        usleep(100);
        localTime = std::chrono::duration_cast< std::chrono::milliseconds >(
                    std::chrono::system_clock::now().time_since_epoch()).count();
        deltaTime = localTime - timeLastFrame;
        //std::cout << (localTime - startTime) * MILLISECONDS_TO_SECONDS << " : " << deltaTime * MILLISECONDS_TO_SECONDS << std::endl;
        
        if(deltaTime > 0)   //will need to also prevent 'timeLastFrame' from being updated when not in this case
            GameTick(deltaTime * MILLISECONDS_TO_SECONDS);
    }
}

void GameEngine::ManualTick(){
    localTime = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
    
    deltaTime = localTime - timeLastFrame;
    if(deltaTime > 0)   //will need to also prevent 'timeLastFrame' from being updated when not in this case
        GameTick(deltaTime * MILLISECONDS_TO_SECONDS);
    
    timeLastFrame = std::chrono::duration_cast< std::chrono::milliseconds >(
                    std::chrono::system_clock::now().time_since_epoch()).count();
}

void GameEngine::Suspend(){
    localTime = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
    
    timeLastFrame = std::chrono::duration_cast< std::chrono::milliseconds >(
                std::chrono::system_clock::now().time_since_epoch()).count();
}

void GameEngine::ManualTick(double manualDeltaTime){
    GameTick(deltaTime * MILLISECONDS_TO_SECONDS);
}

void GameEngine::GameTick(double deltaTime){
    RunCollisions();
    Update(deltaTime);
    Cleanup();
}

void GameEngine::RunCollisions(){
    for(int i = 0; i < ballColliders.size(); ++i){
        for(int j = i+1; j < ballColliders.size(); ++j){
            Bounds::side hitSideA = ballColliders[i]->intersectionSide(ballColliders[j]);
            Bounds::side hitSideB = ballColliders[j]->intersectionSide(ballColliders[i]);
            if(hitSideA != Bounds::none){
                ballColliders[i]->onCollision(ballColliders[j], hitSideA);
            }
            if(hitSideB != Bounds::none){
                ballColliders[j]->onCollision(ballColliders[i], hitSideB);
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

void GameEngine::UserInput(float deltaY){
    playerOne.setY(playerOne.getY() + deltaY);
}
