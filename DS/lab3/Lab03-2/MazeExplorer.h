//
//  MazeExplorer.h
//  Lab03
//
//  Modified by Jeman Park on 2024/10/01.
//



#ifndef MAZEEXPLORER_H
#define MAZEEXPLORER_H

#include "QueueType.h"
using namespace std;

#define MAZE_SIZE 6


void printLocation(location point);
bool mazeExplorer(char map[][MAZE_SIZE], location entryPoint, location exitPoint);

#endif /* CHECKMATCHING_H */
