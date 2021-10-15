#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "PathfinderInterface.h"

#include <sstream>
#include <array>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Pathfinder : public PathfinderInterface {
private:
    bool foundSolution;
    static const int ROW_SIZE = 5;
    static const int COL_SIZE = 5;
    static const int FLOOR_SIZE = 5;
    static const int BACKGROUND = 1;
    static const int WALL = 0;
    static const int TEMPORARY = 2;
    static const int PATH = 3;
    int THE_MAZE[ROW_SIZE][COL_SIZE][FLOOR_SIZE];
    int tempMaze[ROW_SIZE][COL_SIZE][FLOOR_SIZE];
    vector<string> solution;

public:
    Pathfinder();
    ~Pathfinder();
    string toString() const;
    void createRandomMaze();
    bool importMaze(string file_name);
    vector<string> solveMaze();
    vector<string> findPath(int x, int y, int z, vector<string> sol);
};

#endif