#include "Communication Protocol.hpp"

std::string MessageHandler::JSONFromBounds(std::vector<Bounds*> objects){
    rapidjson::Document document;
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    
    //define the document as an object
    document.SetObject();
    
    //the list of all of the entries for the game objects
    rapidjson::Value boundsArray(rapidjson::kArrayType);
    for(auto a : objects){
        //one gameobject's data
        rapidjson::Value object(rapidjson::kObjectType);
        object.AddMember("x", a->getX(), allocator);
        object.AddMember("y", a->getY(), allocator);
        object.AddMember("width", a->getWidth(), allocator);
        object.AddMember("height", a->getHeight(), allocator);
        boundsArray.PushBack(object, allocator);
    }
    //add the list to the document under 'objects'
    document.AddMember("objects", boundsArray, allocator);
    
    //will also need to add the scores, but this will do for now
    
    
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);
    
   return strbuf.GetString();
    
}

MessageHandler::userInput MessageHandler::userInputFromJSON(std::string JSONInput){
    rapidjson::Document document;
    document.Parse(JSONInput.c_str());
    
    assert(document.IsObject());
    assert(document.HasMember("deltaX"));
    assert(document["deltaX"].IsFloat());
    
    userInput data;
    data.deltaX = document["deltaX"].GetFloat();
    
    return data;
    
}
