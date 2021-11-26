#ifndef __PERSON_H__
#define __PERSON_H__

#include "TXLib.h"
#include "TXRIP.h"

class Person
{
private:
    HDC photo; // ��������� �� ����������� ��������
    int x; // ��������� ������� �� ������ �� ��
    int y; // ��������� ������� �� ������ �� ��
    int x1; // ��������� ������� �� ��������� �� ��
    int y1; // ��������� ������� �� ��������� �� ��
    int width; //����� ����� ����� �������
    int height; // ������ ����� ����� �������
    double scalex; //������ ��� ���������� ������� �� ��� ��
    double scaley; //������ ��� ���������� ������� �� ��� ��
    COLORREF color; //���� ������� ���������� �� �������
    int xa; //���������� ����� ��������� �� �����������
    int ya; //���������� ����� ��������� �� ���������

    //������� ��� ���������
    int v; //�������� ���������
    char d; //������� � ������� �������� ���������� �������� ->
    char a; //������� � ������� �������� ���������� �������� <-
    char w; //������� � ������� �������� ���������� �������� (�����)
    char s; //������� � ������� �������� ���������� �������� (����)
    int i;
    int j;
    int pers[8][8];
public:
    Person():
    photo(txLoadImage("fnafb.bmp")),x(320),y(400),x1(41),y1(6),width(134),height(197),scalex(0.3),scaley(0.3),color(TX_BLACK),xa(70),ya(8),v(5),d(VK_RIGHT),a(VK_LEFT),w(VK_UP),s(VK_DOWN)
    {
        if(!photo)
        {
            txMessageBox("�� ������ ���� � ����������","������ #3");
            exit(0);
        }
    }
    ~Person()
    {
        txDeleteDC(photo);
    }

    void draw() //������� ���������
    {
        Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, x1, y1, width, height, color);
    }

    void up() //������� ��������� ��������� �����
    {
        y1=600;
        x1+=width+xa;
        y-=v;
        if(x1>=570)
        {
            x1=41;
        }
    }

    void left() //�������� �����
    {
        y1=205;
        x1-=width+xa;
        x-=v;


        if(x1<=29)
        {
            x1=427;
        }
    }

    void down() // �������� ����
    {
        y1=6;
        x1+=width+xa;
        i-=1;
        y+=v;
        if(x1>=570)
        {
            x1=41;
        }
    }

    void right() //�������� ������
    {
        y1=405;
        x1+=width+xa;
        x+=v;
        if(x1>=570)
        {
            x1=41;
        }

    }

    void update() //��������� � ���������� ���������
    {
        if(GetAsyncKeyState(s) && txGetPixel (x, y+height*scaley) != TX_BLACK)// && // ground[i-1][j]!=3)
        {
            down();
        }
        else if(GetAsyncKeyState(d) && txGetPixel (x+width*scalex, y) != TX_BLACK) //&& //ground[i][j+1]!=3)
        {
            right();
        }
        else if(GetAsyncKeyState(w) && txGetPixel (x, y) != TX_BLACK) //&& //ground[i+1][j]!=3)
        {
            up();
        }
        else if(GetAsyncKeyState(a) && txGetPixel (x, y) != TX_BLACK) //&& ground[i][j-1]!=3)
        {
            left();
        }
    }
};
#endif
