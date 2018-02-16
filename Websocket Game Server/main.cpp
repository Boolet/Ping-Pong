//
//  main.cpp
//  Learning Sockets
//
//  Created by Avi Miller on 2/15/18.
//  Copyright © 2018 Avi Miller. All rights reserved.
//

#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <map>
#include <sstream>
#include <chrono>
#include "websocket.hpp"
#include "Game Engine.hpp"
#include "Communication Protocol.hpp"

#define PORT 8888
#define PLAY_WIDTH 500
#define PLAY_HEIGHT 500
#define MAX_PLAYERS 1

webSocket server;
GameEngine* engine;

void initGameEngine(){
    engine = new GameEngine(PLAY_WIDTH, PLAY_HEIGHT);
}

void stepGameEngine(double deltaTime){
    engine->ManualTick(deltaTime);
}

std::string gameDataJSON(){
    return MessageHandler::JSONFromBoundsWithScores(engine->getColliderData(), Score::getScores());
    //return MessageHandler::JSONFromBounds(engine->getColliderData());
}

void sendGameData(){
    std::string data = gameDataJSON();
    
    std::vector<int> clientIDs = server.getClientIDs();
    for (int i = 0; i < clientIDs.size(); i++)
        server.wsSend(clientIDs[i], data);
}

void sendTime(time_t current){
    std::ostringstream os;
    std::string timestring = ctime(&current);
    timestring = timestring.substr(0, timestring.size() - 1);
    os << timestring;
    
    std::vector<int> clientIDs = server.getClientIDs();
    for (int i = 0; i < clientIDs.size(); i++)
        server.wsSend(clientIDs[i], os.str());
}


void recieveMessage(int clientID, std::string message){
    std::ostringstream os;
    os << "Stranger " << clientID << " says: " << message;
    
    std::vector<int> clientIDs = server.getClientIDs();
    for (int i = 0; i < clientIDs.size(); i++){
        if (clientIDs[i] != clientID)
            server.wsSend(clientIDs[i], os.str());
    }
}

void updateGameData(std::string dataJSON){
    MessageHandler::userInput input =  MessageHandler::userInputFromJSON(dataJSON);
    engine->UserInput(input.deltaY);
}



/* called when a client connects */
void openHandler(int clientID){
    std::vector<int> clientIDs = server.getClientIDs();
    
    if(clientIDs.size() > MAX_PLAYERS){
        server.wsClose(clientID);
    }
}

/* called when a client disconnects */
void closeHandler(int clientID){
    std::ostringstream os;
    os << "Stranger " << clientID << " has leaved.";
    
    std::vector<int> clientIDs = server.getClientIDs();
    for (int i = 0; i < clientIDs.size(); i++){
        if (clientIDs[i] != clientID)
            server.wsSend(clientIDs[i], os.str());
    }
}

/* called when a client sends a message to the server */
void messageHandler(int clientID, std::string message){
    std::cout << "Input from " << clientID << "containing: " << message << std::endl;
    updateGameData(message);
}

/* called once per select() loop */
void periodicHandler(){
    static double next = std::chrono::duration_cast< std::chrono::milliseconds >(
                        std::chrono::system_clock::now().time_since_epoch()).count() + 500;
    double current = std::chrono::duration_cast< std::chrono::milliseconds >(
                        std::chrono::system_clock::now().time_since_epoch()).count();
    
    std::vector<int> clientIDs = server.getClientIDs();
    if(clientIDs.size() > 0)
        engine->ManualTick();
    else
        engine->Suspend();
    
    if (current >= next){   //send a message every 1 seconds
        std::cout << "Number of clients: " << clientIDs.size() << std::endl;
        sendGameData();
        
        next = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()).count() + 500;
    }
}

int main(int argc, char *argv[]){
    
    initGameEngine();
    
    /* set event handler */
    server.setOpenHandler(openHandler);
    server.setCloseHandler(closeHandler);
    server.setMessageHandler(messageHandler);
    server.setPeriodicHandler(periodicHandler);
    
    /* start the chatroom server, listen to ip '127.0.0.1' and port '8888' */
    server.startServer(PORT);
    
    return 1;
}

