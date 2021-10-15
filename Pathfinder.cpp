#include "Pathfinder.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

Pathfinder::Pathfinder(){
    for(int floor = 0; floor < FLOOR_SIZE; floor++){
        for(int col = 0; col < COL_SIZE; col++){
            for(int row = 0; row < ROW_SIZE; row++){
                THE_MAZE[row][col][floor] = 1;
            }
        }
    }
}
Pathfinder::~Pathfinder(){}

bool Pathfinder::importMaze(string file_name){
    int floor, col, row;
    int testVal;
    
    ifstream inFile(file_name);

    for(floor = 0; floor < FLOOR_SIZE; floor++){
        for(col = 0; col < COL_SIZE; col++){
            for(row = 0; row < ROW_SIZE; row++){
                tempMaze[row][col][floor] = -1;
            }
        }
    }
    
    for(floor = 0; floor < FLOOR_SIZE; floor++){
        for(col = 0; col < COL_SIZE; col++){
            for(row = 0; row < ROW_SIZE; row++){
                if(inFile.eof()){
                    return false;
                }

                inFile >> testVal;

                if(testVal == 0 || testVal == 1){
                    tempMaze[row][col][floor] = testVal;
                }

                else{
                    return false;
                }
            }
        }
    }
    if(tempMaze[0][0][0] != 1 || tempMaze[ROW_SIZE - 1][COL_SIZE - 1][FLOOR_SIZE - 1] != 1){
        return false;
    }

    testVal = -1;
    inFile >> testVal;
        
    if(testVal != -1){
        return false;
    }

    for(floor = 0; floor < FLOOR_SIZE; floor++){
        for(col = 0; col < COL_SIZE; col++){
            for(row = 0; row < ROW_SIZE; row++){
                THE_MAZE[row][col][floor] = tempMaze [row][col][floor];
            }
        }
    }

    inFile.close();
    return true;
}

string Pathfinder::toString() const{
    int row;
    int col;
    int floor;
    int valid = 1;

    string retStr;
    stringstream tempStream;

    for(floor = 0; floor < FLOOR_SIZE; floor++){
        for(col = 0; col < COL_SIZE; col++){
            for(row = 0; row < ROW_SIZE; row++){
                if(row == ROW_SIZE - 1){
                    tempStream << THE_MAZE[row][col][floor];
                }

                else{
                    tempStream << THE_MAZE[row][col][floor] << " ";
                }
            }
            tempStream << endl;
        }
        if(floor < FLOOR_SIZE - 1){
            tempStream << endl;
        }
    }

    retStr = tempStream.str();
    return retStr;
}

void Pathfinder::createRandomMaze(){
    int row;
    int col;
    int floor;

    for(floor = 0; floor < FLOOR_SIZE; floor++){
        for(col = 0; col < COL_SIZE; col++){
            for(row = 0; row < ROW_SIZE; row++){
                THE_MAZE[row][col][floor] = rand() % 2;
            }
        }
    }

    THE_MAZE[0][0][0] = 1;
    THE_MAZE[4][4][4] = 1;
}

vector<string>Pathfinder::solveMaze(){
    // int row;
    // int col;
    // int floor;
    // int tempInt;

    // solution.clear();
    // foundSolution = false;
    // foundSolution = findPath(0,0,0, solution);

    // for(floor = 0; floor < FLOOR_SIZE; floor++){
    //     for(col = 0; col < COL_SIZE; col++){
    //         for(row = 0; row < ROW_SIZE; row++){
    //             if(THE_MAZE[row][col][floor] == 2){
    //                 THE_MAZE[row][col][floor] = 1;
    //             }
    //         }
    //     }
    // }

    return solution;
}