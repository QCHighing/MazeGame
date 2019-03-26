#pragma once
#include "public.h"


class MazeMap
{
public:
    MazeMap();                                              //默认构造函数
    MazeMap(int* mapData, int row, int column);             //含参构造函数：存放地图数据的二维数组，迷宫行数，迷宫列数
    ~MazeMap();                                             //析构函数
    void setMazeWall(char wallChar='*');                    //设置表示墙的字符
    void setMazeRoad(char roadChar=' ');					//设置表示路的字符
    void drawMap() const;                                   //绘制迷宫地图
    static bool isWall(int x, int y);
    static char getRoadChar();          //静态成员函数只能访问静态成员变量和静态成员函数

private:
    static char wallChar;      //代表墙的字符，如 *#@
    static char roadChar;      //代表人的字符，如 R
    static int  mazeHeight;    //迷宫的高度
    static int  mazeWidth;     //迷宫的宽度
    static int* mazeMapData;   //迷宫的数据
};

