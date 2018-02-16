//
//  Score.hpp
//  Websocket Game Server
//
//  Created by Avi Miller on 2/15/18.
//  Copyright © 2018 Avi Miller. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include <vector>

class Score{
public:
    Score(){scores.push_back(this);}
    
    int score = 0;
    
    static std::vector<Score*> getScores(){return Score::scores;}
private:
    static std::vector<Score*> scores;
};

#endif /* Score_hpp */
