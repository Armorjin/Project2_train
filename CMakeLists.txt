cmake_minimum_required(VERSION 3.5.0)

set(SOURCES
       
    ./src/train.h
    ./src/wagon.h
    ./src/train.cpp
    ./src/wagon.cpp
    

    )

include_directories(
    ./src/
    )
add_executable(ChoCho ./main.cpp ${SOURCES})
