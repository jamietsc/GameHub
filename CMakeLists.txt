cmake_minimum_required(VERSION 3.27)
project(Zahlenraten_Spiel)

set(CMAKE_CXX_STANDARD 20)

add_executable(Zahlenraten_Spiel main.cpp
        games/Blackjack.cpp
        games/Blackjack.h
        games/NumberGuessing.cpp
        games/NumberGuessing.h
        includes/UserInput.cpp
        includes/UserInput.h)
