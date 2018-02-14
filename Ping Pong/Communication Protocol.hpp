#ifndef Communication_Protocol_hpp
#define Communication_Protocol_hpp

#include <stdio.h>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "Bound.hpp"

class MessageHandler{
public:
    static std::string JSONFromBounds(std::vector<Bounds*> objects);
};

#endif /* Communication_Protocol_hpp */
