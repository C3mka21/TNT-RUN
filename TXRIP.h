#ifndef __TXRIP_H__
#define __TXRIP_H__

#include "TXLib.h"
#define WINDOWX 197*8
#define WINDOWY

class Karta
{
private:
    HDC photo;
    COLORREF color;

    int x;
    int y;
    int x1;
    int y1;
    int type;
    int stx;
    int sty;
    int n;
    int m;
    int height; //13
    int width;  //17
    double scalex;
    double scaley;
    int ground [8][8];
public:
    Karta():
    photo(txLoadImage("karta.bmp")),color(TX_WHITE),height(312),width(308),scalex(0.2),scaley(0.2),x(0),y(0),x1(657),y1(656),type(0),stx(x),sty(y),n(8),m(8)
    {
        if(!photo)
        {
            txMessageBox("Не найден файл с картой","Ошибка #2");
            exit(0);
        }
    }

    ~Karta()
    {
        txDeleteDC(photo);
    }

    int init()
    {
        FILE* f;
        f = fopen("karta.txt", "r");
        if (f==NULL)
        {
            txMessageBox("Не найден файл с матрицей","Ошибка #1");
            return 1;
        }
        fscanf(f, "%d%d\n",&n,&m );
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                fscanf(f, "%d", &ground[i][j]);
            }
        }
        fclose(f);
        return 0;
    }

    void draw()
    {
        for (int i = 0; i < n; i++)
        {
            if(i>=1)
                y=y+height*scaley;
            for(int j = 0; j < m; j++)
            {
                if(j>=1)
                    x=x+width*scalex;
                if(ground[i][j]==2){
                    Win32::TransparentBlt (txDC(), x, y , width*scalex, height*scaley, photo, x1, y1, width, height, color);
                }
                else if(ground[i][j]==1){
                    Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, 3, 985 , width, height, color);
                }
                else if(ground[i][j]==3){
                    Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, 990, 985 , width, height, color);
                }
                if(j==m-1)
                {
                    x=stx;
                }
                if(i==n-1&&j==m-1)
                {
                    y=sty;

                }
            }
        }
    }
    int get_width() {return width;}
    double get_scalex() {return scalex;}
    void set_width(int n1){width=n1;}
};

#endif
