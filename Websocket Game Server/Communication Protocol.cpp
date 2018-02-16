#include "Communication Protocol.hpp"

std::string MessageHandler::JSONFromBoundsWithScores(std::vector<Bounds*> objects, std::vector<Score*> scores){
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
    
    //the list of all of the scores
    rapidjson::Value scoresArray(rapidjson::kArrayType);
    for(auto a : scores){
        //one gameobject's data
        rapidjson::Value object(rapidjson::kObjectType);
        object.AddMember("score", a->score, allocator);
        scoresArray.PushBack(object, allocator);
    }
    //add the list to the document under 'objects'
    document.AddMember("scores", scoresArray, allocator);
    
    
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);
    
   return strbuf.GetString();
    
}

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
    
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    document.Accept(writer);
    
    return strbuf.GetString();
    
}

MessageHandler::userInput MessageHandler::userInputFromJSON(std::string JSONInput){
    rapidjson::Document document;
    document.Parse(JSONInput.c_str());
    
    assert(document.IsObject());
    assert(document.HasMember("deltaY"));
    assert(document["deltaY"].IsFloat());
    
    userInput data;
    data.deltaY = document["deltaY"].GetFloat();
    
    return data;
    
}
