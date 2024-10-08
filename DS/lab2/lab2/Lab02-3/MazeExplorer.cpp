//
//  MazeExplorer.cpp
//  Lab02
//
//  Modified by Jeman Park on 2023/09/24.
//

#include "MazeExplorer.h"

void printLocation(location point){
    cout << "[" << point.row << "][" << point.col << "]" << endl;
}

bool mazeExplorer(char map[][MAZE_SIZE], location entryPoint, location exitPoint){
    StackType<location> tempStack;
    tempStack.push(entryPoint);
    
    /* Implement the function here (Lab 02-3) */
    // This function explores "map" to find the path from "entryPoint" to "exitPoint" using STACK
    // it should prints all visited points.
    // it returns true, if it successfully finds the path
    // otherwise, it returns false
    // When there are multiple possible paths from the current point, the priority is "upward ↑" -> "rightward →" -> "downward ↓" -> "leftward ←"
    //
    // For details, check the PDF slides!

    location pos = entryPoint;

    while (true) {
        location pos_arr[4];

        if (tempStack.isEmpty()) {
            return 0;
        }
        if (pos.col == exitPoint.col && pos.row == exitPoint.row) {
            return 1;
        }
        pos = tempStack.pop();
        printLocation(pos);

        map[pos.row][pos.col] = '.';
        pos_arr[3] = location(pos.row - 1, pos.col);
        pos_arr[2] = location(pos.row, pos.col + 1);
        pos_arr[1] = location(pos.row + 1, pos.col);
        pos_arr[0] = location(pos.row, pos.col - 1);

        for (int i = 0; i < 4; i++) {
            if (pos_arr[i].col >= 0 && pos_arr[i].col <= MAZE_SIZE - 1 && pos_arr[i].row >= 0 && pos_arr[i].row <= MAZE_SIZE - 1) {
                if (map[pos_arr[i].row][pos_arr[i].col] == '0') {
                    tempStack.push(pos_arr[i]);
                }
            }
        }
    }
}
