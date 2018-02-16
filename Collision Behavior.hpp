//
//  Collision Behavior.hpp
//  Websocket Game Server
//
//  Created by Avi Miller on 2/15/18.
//  Copyright © 2018 Avi Miller. All rights reserved.
//

#ifndef Collision_Behavior_hpp
#define Collision_Behavior_hpp

#include <stdio.h>
#include "Score.hpp"

class Bounds;

class CollisionBehavior{
public:
    virtual void OnCollision(Bounds* other){}
};

class ResetScore : public CollisionBehavior{
public:
    ResetScore(Score* target):targetScore(target){};
    
    void OnCollision(Bounds* other) override;
    
    Score* targetScore;
};

#endif /* Collision_Behavior_hpp */
