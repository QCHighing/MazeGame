#include "MazeWalker.h"
#include "MazeMap.h"
#include <iostream>
#include <windows.h>

using namespace std;

MazeWalker::MazeWalker()
{
}


MazeWalker::MazeWalker(int entryX, int entryY, int exitX, int exitY)
{
    personChar = 'R';
    preX = 0;
    preY = 0;
    curX = entryX;
    curY = entryY;
    this->entryX = entryX;
    this->entryY = entryY;
    this->exitX = exitX;
    this->exitY = exitY;
    forward = NORTH;
    isOut = false;
}


MazeWalker::~MazeWalker()
{
}


void MazeWalker::run()
{
    //�����ʼλ���Ƿ���ȷ
    if (MazeMap::isWall(curX, curY))
    {
        gotoXY(entryX + 2, 0);
        cout << "��⵽��ǰ�趨����ʼλ����ǽ�ڣ��������趨...\n" << endl;
        return;
    }
    //��ʼ
    for(int i=0; i<100 && !isOut; i++)
    {
        drawPerson();
        checkExit();        //�����ڣ�����isOut��־λ
        if (leftIsWall())   //���ַ�������һֱ��ǽ
        {
            while (forwardIsWall())
            {
                turnRight();
            }
        }
        else
        {
            turnLeft();
        }
        goAhead();
    }
    gotoXY(entryX + 2, 0);
    cout << "���ڳ�����������\n" << endl;
}


void MazeWalker::goAhead()
{
    switch (forward)
    {
    case NORTH: moveNorth(); break;
    case WEST:  moveWest();  break;
    case SOUTH: moveSouth(); break;
    case EAST:  moveEast();  break;
    default: cout << "���������޷�ǰ��" << endl;
    }
}


void MazeWalker::turnRight()
{
    switch (forward)
    {
    case NORTH: forward = EAST;  break;
    case WEST:  forward = NORTH; break;
    case SOUTH: forward = WEST;  break;
    case EAST:  forward = SOUTH; break;
    default: cout << "���������޷���ת" << endl;
    }
}


void MazeWalker::turnLeft()
{
    switch (forward)
    {
    case EAST:  forward = NORTH; break;
    case WEST:  forward = SOUTH; break;
    case SOUTH: forward = EAST;  break;
    case NORTH: forward = WEST;  break;
    default: cout << "���������޷���ת" << endl;
    }
}


void MazeWalker::moveNorth()
{
    savePrePosition();
    curX = curX - 1;
    curY = curY;
}

void MazeWalker::moveSouth()
{
    savePrePosition();
    curX = curX + 1;
    curY = curY;
}

void MazeWalker::moveWest()
{
    savePrePosition();
    curX = curX;
    curY = curY - 1;
}

void MazeWalker::moveEast()
{
    savePrePosition();
    curX = curX;
    curY = curY + 1;
}

void MazeWalker::checkExit()
{
    if (curX==exitX && curY==exitY)
    {
        isOut = true;
    }
}

void MazeWalker::savePrePosition()
{
    preX = curX;
    preY = curY;
}

bool MazeWalker::forwardIsWall()
{
    int forwardX;
    int forwardY;

    switch (forward)
    {
    case EAST:  forwardX = curX; forwardY = curY + 1; break;
    case WEST:  forwardX = curX; forwardY = curY - 1; break;
    case SOUTH: forwardX = curX + 1; forwardY = curY; break;
    case NORTH: forwardX = curX - 1; forwardY = curY; break;
    }
    return MazeMap::isWall(forwardX, forwardY);
}

bool MazeWalker::leftIsWall()
{
    int leftX;
    int leftY;

    switch (forward)
    {
    case EAST:  leftX = curX - 1; leftY = curY; break;
    case WEST:  leftX = curX + 1; leftY = curY; break;
    case SOUTH: leftX = curX; leftY = curY + 1; break;
    case NORTH: leftX = curX; leftY = curY - 1; break;
    }
    return MazeMap::isWall(leftX, leftY);
}

void MazeWalker::drawPerson()
{
    char roadChar = MazeMap::getRoadChar();
    gotoXY(preX, preY);
    cout << roadChar;
    gotoXY(curX, curY);
    cout << personChar;
    Sleep(1000);            //ms��
}

void MazeWalker::gotoXY(int x, int y)
{
    COORD cd;
    cd.X = y;
    cd.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cd);
}
