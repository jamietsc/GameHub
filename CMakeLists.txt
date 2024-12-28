cmake_minimum_required(VERSION 3.27)
project(Zahlenraten_Spiel)

set(CMAKE_CXX_STANDARD 20)

add_executable(Zahlenraten_Spiel main.cpp
        games/blackjack/Blackjack.cpp
        games/blackjack/Blackjack.h
        games/numberGuessing/NumberGuessing.cpp
        games/numberGuessing/NumberGuessing.h
        includes/UserInput.cpp
        includes/UserInput.h)
