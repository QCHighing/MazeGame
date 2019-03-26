#include "MazeMap.h"
#include <iostream>

using namespace std;

//初始化静态变量
char MazeMap::roadChar = ' ';
char MazeMap::wallChar = '*';
int  MazeMap::mazeWidth = 0;
int  MazeMap::mazeHeight = 0;
int* MazeMap::mazeMapData = NULL;


MazeMap::MazeMap()
{
}


MazeMap::MazeMap(int* mapData, int row, int column)
{
    mazeHeight = row;
    mazeWidth = column;
    mazeMapData = new int[row * column];
    for (int i = 0; i < row*column; i++)
    {
        mazeMapData[i] = *mapData;
        mapData++;
    }
}


MazeMap::~MazeMap()
{
    delete[]mazeMapData;
    mazeMapData = NULL;
}


void MazeMap::setMazeWall(char wallChar)
{
    this->wallChar = wallChar;
}


void MazeMap::setMazeRoad(char roadChar)
{
    this->roadChar = roadChar;
}


void MazeMap::drawMap() const
{
    for (int i=0; i<mazeHeight; i++)
    {
        for (int j=0; j<mazeWidth; j++)
        {
            int index = i * mazeWidth + j;
            if (mazeMapData[index] == WALL)
            {
                cout << wallChar;
            }
            else
            {
                cout << roadChar;
            }
        }
        cout << endl;
    }
}


bool MazeMap::isWall(int x, int y)
{
    int index = x * mazeWidth + y;
    if (mazeMapData[index] == WALL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


char MazeMap::getRoadChar()
{
    return roadChar;
}
