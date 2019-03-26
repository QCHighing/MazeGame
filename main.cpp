#include <iostream>
#include <stdlib.h>
#include "public.h"
#include "MazeMap.h"
#include "MazeWalker.h"

using namespace std;

int main()
{
    int map[8][9] = {
                    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL},
                    {WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
                    {WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
                    {WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
                    {WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL},
                    {WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,WALL},
                    {WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
                    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL}};

    MazeMap maze(&map[0][0], 8, 9);
    maze.setMazeWall();
    maze.setMazeRoad();
    maze.drawMap();

    //MazeWalker person(7, 0, 0, 7);  //错误入口
    MazeWalker person(7, 1, 0, 7);  //正确入口
    person.run();

    system("pause");
    return 0;
}