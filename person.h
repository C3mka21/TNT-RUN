#ifndef __PERSON_H__
#define __PERSON_H__

#include "TXLib.h"
#include "TXRIP.h"

class Person
{
private:
    HDC photo; // указатель на загруженную картинку
    int x; // положение спрайта на экране по ох
    int y; // положение спрайта на экране по оу
    int x1; // положение спрайта на источнике по ох
    int y1; // положение спрайта на источнике по оу
    int width; //длина одной части спрайта
    int height; // высота одной части спрайта
    double scalex; //сжатие или раст€жение спрайта по оси ох
    double scaley; //сжатие или раст€жение спрайта по оси оу
    COLORREF color; //цвет который стираетьс€ со спрайта
    int xa; //рассто€ние между спрайтами по горизонтали
    int ya; //рассто€ние между спрайтами по вертикали

    //команды дл€ персонажа
    int v; //скорость персонажа
    char d; //стрелка в сторону которого двигаетьс€ персонаж ->
    char a; //стрелка в сторону которого двигаетьс€ персонаж <-
    char w; //стрелка в сторону которого двигаетьс€ персонаж (вверх)
    char s; //стрелка в сторону которого двигаетьс€ персонаж (вниз)
    int i;
    int j;
    int pers[8][8];
public:
    Person():
    photo(txLoadImage("fnafb.bmp")),x(320),y(400),x1(41),y1(6),width(134),height(197),scalex(0.3),scaley(0.3),color(TX_BLACK),xa(70),ya(8),v(5),d(VK_RIGHT),a(VK_LEFT),w(VK_UP),s(VK_DOWN)
    {
        if(!photo)
        {
            txMessageBox("Ќе найден файл с персонажем","ќшибка #3");
            exit(0);
        }
    }
    ~Person()
    {
        txDeleteDC(photo);
    }

    void draw() //функци€ отрисовки
    {
        Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, x1, y1, width, height, color);
    }

    void up() //функци€ изменени€ положени€ вверх
    {
        y1=600;
        x1+=width+xa;
        y-=v;
        if(x1>=570)
        {
            x1=41;
        }
    }

    void left() //движение влево
    {
        y1=205;
        x1-=width+xa;
        x-=v;


        if(x1<=29)
        {
            x1=427;
        }
    }

    void down() // движение вниз
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

    void right() //движение вправо
    {
        y1=405;
        x1+=width+xa;
        x+=v;
        if(x1>=570)
        {
            x1=41;
        }

    }

    void update() //отрисовка и обновление положени€
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
