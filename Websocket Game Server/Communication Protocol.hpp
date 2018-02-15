#ifndef Communication_Protocol_hpp
#define Communication_Protocol_hpp

#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Bound.hpp"

class MessageHandler{
public:
    struct userInput{
        float deltaX;
    };
    
    static std::string JSONFromBounds(std::vector<Bounds*> objects);
    static userInput userInputFromJSON(std::string JSONInput);
};

#endif /* Communication_Protocol_hpp */
