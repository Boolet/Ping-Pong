//
//  Collision Behavior.cpp
//  Websocket Game Server
//
//  Created by Avi Miller on 2/15/18.
//  Copyright © 2018 Avi Miller. All rights reserved.
//

#include "Bound.hpp"

void Bounds::ResetScore::OnCollision(Bounds* other){
    if(other->getName() == "ball"){
        targetScore->score = 0;
    }
}
