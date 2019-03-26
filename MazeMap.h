#pragma once
#include "public.h"


class MazeMap
{
public:
    MazeMap();                                              //Ĭ�Ϲ��캯��
    MazeMap(int* mapData, int row, int column);             //���ι��캯������ŵ�ͼ���ݵĶ�ά���飬�Թ��������Թ�����
    ~MazeMap();                                             //��������
    void setMazeWall(char wallChar='*');                    //���ñ�ʾǽ���ַ�
    void setMazeRoad(char roadChar=' ');					//���ñ�ʾ·���ַ�
    void drawMap() const;                                   //�����Թ���ͼ
    static bool isWall(int x, int y);
    static char getRoadChar();          //��̬��Ա����ֻ�ܷ��ʾ�̬��Ա�����;�̬��Ա����

private:
    static char wallChar;      //����ǽ���ַ����� *#@
    static char roadChar;      //�����˵��ַ����� R
    static int  mazeHeight;    //�Թ��ĸ߶�
    static int  mazeWidth;     //�Թ��Ŀ��
    static int* mazeMapData;   //�Թ�������
};

