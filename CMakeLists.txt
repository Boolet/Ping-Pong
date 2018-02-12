cmake_minimum_required(VERSION 3.8)
project(Ping_Pong)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        "Ping Pong/Ball.cpp"
        "Ping Pong/Ball.hpp"
        "Ping Pong/Bound.cpp"
        "Ping Pong/Bound.hpp"
        "Ping Pong/Communication Protocol.cpp"
        "Ping Pong/Communication Protocol.hpp"
        "Ping Pong/Game Engine.cpp"
        "Ping Pong/Game Engine.hpp"
        "Ping Pong/main.cpp"
        "Ping Pong/Paddle.cpp"
        "Ping Pong/Paddle.hpp"
        chatroom_client.html)

add_executable(Ping_Pong ${SOURCE_FILES})