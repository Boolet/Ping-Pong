#ifndef Communication_Protocol_hpp
#define Communication_Protocol_hpp

#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Bound.hpp"
#include "Score.hpp"

class MessageHandler{
public:
    //this will need to be moved to its own file
    struct userInput{
        float deltaY;
    };
    
    static std::string JSONFromBoundsWithScores(std::vector<Bounds*> objects, std::vector<Score*> scores);
    static std::string JSONFromBounds(std::vector<Bounds*> objects);
    static userInput userInputFromJSON(std::string JSONInput);
};

#endif /* Communication_Protocol_hpp */
