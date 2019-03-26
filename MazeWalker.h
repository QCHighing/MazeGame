#pragma once
#include "public.h"


class MazeWalker
{
public:
    MazeWalker();
    MazeWalker(int entryX, int entryY, int exitX, int exitY);
    ~MazeWalker();
    void run();

private:
    void goAhead();
    void turnRight();
    void turnLeft();
    void moveNorth();
    void moveSouth();
    void moveWest();
    void moveEast();
    void checkExit();
    void savePrePosition();

private:
    bool forwardIsWall();
    bool leftIsWall();
    void drawPerson();
    void gotoXY(int x, int y);

private:
    char personChar;
    int preX;
    int preY;
    int curX;
    int curY;
    int entryX;
    int entryY;
    int exitX;  //出口行标
    int exitY;  //出口列标
    objectiveDirections forward;    //正前方朝向：东西南北
    bool isOut;                     //是否走出迷宫的标志
};

