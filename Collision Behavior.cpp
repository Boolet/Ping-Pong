//
//  Collision Behavior.cpp
//  Websocket Game Server
//
//  Created by Avi Miller on 2/15/18.
//  Copyright © 2018 Avi Miller. All rights reserved.
//

#include "Collision Behavior.hpp"

void ResetScore::OnCollision(Bounds* other){
    targetScore->score = 0;
}
