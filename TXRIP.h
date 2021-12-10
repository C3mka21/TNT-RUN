#ifndef __TXRIP_H__
#define __TXRIP_H__

#define WINDOWX 795
#define WINDOWY 800

#include "TXLib.h" //����������� ����������



class Karta //�������� ������
{
private:
    HDC photo; // ��������� �� ����������� ��������
    COLORREF color; // ����

    int x; //��������� ����������� �������� �� ������ �� ��� ��
    int y; //��������� ����������� �������� �� ������ �� ��� ��
    int x1; //��������� ������ �������� ���� �������������� ���������� ������� �� ��� ��
    int y1; //��������� ������ �������� ���� �������������� ���������� ������� �� ��� ��
    int stx; //��������� ��������� �������� �� ��� ��
    int sty; //��������� ��������� �������� �� ��� ��

    int height; //������ ���������� ������� � ��������
    int width; //������ ���������� ������� � ��������

    double scalex; //���������� ����������� �������� ������ �������� �� ������ �� ��� ��
    double scaley; //���������� ����������� �������� ������ �������� �� ������ �� ��� ��

    int n; //���������� �������� � �������
    int m;//���������� ����� � �������

    int ground[15][15]; //������ ����� ������� � karta.txt

public:
    Karta(): //����������� ������
    photo(txLoadImage("karta.bmp")),color(TX_WHITE),x(-60),y(-62),x1(657),y1(656),stx(x),sty(y),height(312),width(308),scalex(0.2),scaley(0.2),n(15),m(15)
    {
        if(!photo) //�������� �� ������� ����� �� ��������
        {
            txMessageBox("�� ������ ���� �� ��������� �����","������ #2");
            exit(0);
        }
    }

    ~Karta() //���������� ������
    {
        txDeleteDC(photo); //�������� �������� �� ������
    }

    int init() //������������� �����
    {
        FILE* f;
        f = fopen("level1.txt", "r"); //�������� ����� karta.txt
        if (f==NULL) //�������� �� ������� ����� � ��������
        {
            txMessageBox("�� ������ ���� � ������","������ #1");
            return 1;
        }
        fscanf(f, "%d%d\n",&n,&m ); //���������� ���-�� �������� � ����� � �������
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                fscanf(f, "%d", &ground[i][j]); //���������� ������ �������
            }
            fscanf(f,"\n");
        }
        fclose(f); //�������� �����

        return 0;
    }

    void draw() //��������� �����
    {
        for (int i = 0; i < n; i++)
        {
            if(i>=1) //������� �� ��������� ������� � �������
                y=y+height*scaley;  //�������� ��������� ������ ���������� ����� �� ��
            for(int j = 0; j < m; j++)
            {
                if(j>=1) //������� �� ��������� ������� � �������
                    x=x+width*scalex; //�������� ��������� ������ ���������� ����� �� ��
                if(ground[i][j]==2) //�������� �� ������� ����� � ������ � ��������� ������������� ����������
                {
                    Win32::TransparentBlt (txDC(), x, y , width*scalex, height*scaley, photo, x1, y1, width, height, color); //���������
                }
                else if(ground[i][j]==1) //�������� �� ������� ����� � ������ � ��������� ������������� ����������
                {
                    Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, 3, 985 , width, height, color); //���������
                }
                else if(ground[i][j]==3) //�������� �� ������� ����� � ������ � ��������� ������������� ����������
                {
                    Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, 990, 985 , width, height, color); //���������
                }
                if(j==m-1) //�������� �� ����� ������
                {
                    x=stx;
                }
                if(i==n-1 && j==m-1) //�������� �� ����� �������
                {
                    y=sty;

                }
            }
        }
    }

    int init2() //������������� �����
    {
        FILE* f;
        f = fopen("level2.txt", "r"); //�������� ����� karta.txt
        if (f==NULL) //�������� �� ������� ����� � ��������
        {
            txMessageBox("�� ������ ���� � ������","������ #1");
            return 1;
        }
        fscanf(f, "%d%d\n",&n,&m ); //���������� ���-�� �������� � ����� � �������
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                fscanf(f, "%d", &ground[i][j]); //���������� ������ �������
            }
            fscanf(f,"\n");
        }
        fclose(f); //�������� �����

        return 0;
    }

    int get_height() {return height;} //������� ������ ��� ������������� � ������ .h ����� ������ ����������� �������

    int get_width() {return width;} //������� ������ ��� ������������� � ������ .h ����� ������ ����������� �������

    double get_scalex() {return scalex;} //������� ������ ��� ��������� ������ �� ���������� ������� �� ������

    int get_x() {return x;}

    int get_y() {return y;}

    int get_ground(int i,int j) {return ground[i][j];}

    void set_ground(int i,int j,int type) {ground[i][j]=type;}



};

#endif
