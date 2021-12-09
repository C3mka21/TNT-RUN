#ifndef __PERSON_H__
#define __PERSON_H__

#include "TXLib.h" //подключение основной библиотеки


class Person
{
private:
    HDC photo; //указатель на загруженную картинку

    int x; //положение спрайта на экране по ох
    int y; //положение спрайта на экране по оу
    int x1; //положение спрайта на источнике по ох
    int y1; //положение спрайта на источнике по оу
    int width; //длина одной части спрайта
    int height; // высота одной части спрайта

    double scalex; //сжатие или растяжение спрайта по оси ох
    double scaley; //сжатие или растяжение спрайта по оси оу

    COLORREF color; //цвет который стираеться со спрайта

    int xa; //расстояние между спрайтами по горизонтали
    int ya; //расстояние между спрайтами по вертикали

    Karta* karta;

    //команды для персонажа

    int v; //скорость персонажа

    char d; //стрелка в сторону которого двигаеться персонаж ->
    char a; //стрелка в сторону которого двигаеться персонаж <-
    char w; //стрелка в сторону которого двигаеться персонаж (вверх)
    char s; //стрелка в сторону которого двигаеться персонаж (вниз)

    int k;  //положение персонажа в строке на массиве карты
    int n;  //положение персонажа в столбцу на массиве карты

    bool check;

public:
    Person(): //конструктор
    photo(txLoadImage("fnafb.bmp")),x(265),y(374),x1(41),y1(6),width(134),height(197),scalex(0.3),scaley(0.3),color(TX_BLACK),xa(70),ya(8),v(5),d(VK_RIGHT),a(VK_LEFT),w(VK_UP),s(VK_DOWN),n(7),k(5),check(true)
    {
        if(!photo)
        {
            txMessageBox("Не найден файл с персонажем","Ошибка #3");
            exit(0);
        }
    }

    ~Person() //деструктор
    {
        txDeleteDC(photo); //удаление картинки из памяти
    }

    void init_karta(Karta* a) //функция для создания указателя
    {
        karta=a;
    }

    void draw() //функция отрисовки
    {
        Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, x1, y1, width, height, color); //рисование
    }

    void up(int a, double b) //функция изменения положения вверх
    {
        y1=600;
        x1+=width+xa; //движение по  загруженной картинке для изменения положения рук у персонажа
        y-=a*b; //движение по карте
        if(x1>=570) //возвращение назад по загруженной картинке
        {
            x1=41;
        }
    }

    void left(int a, double b) //движение влево
    {
        y1=205;
        x1-=width+xa; //движение по  загруженной картинке для изменения положения рук у персонажа
        x-=a*b; //движение по карте
        if(x1<=29) //возвращение назад по загруженной картинке
        {
            x1=427;
        }
    }

    void down(int a, double b) //движение вниз
    {
        y1=6;
        x1+=width+xa;//движение по  загруженной картинке для изменения положения рук у персонажа
        y+=a*b;//движение по карте
        if(x1>=570) //возвращение назад по загруженной картинке
        {
            x1=41;
        }
    }

    void right(int a, double b) //движение вправо
    {
        y1=405;
        x1+=width+xa;//движение по  загруженной картинке для изменения положения рук у персонажа
        x+=a*b;//движение по карте
        if(x1>=570)//возвращение назад по загруженной картинке
        {
            x1=41;
        }

    }

    void update()
    {
        if(GetAsyncKeyState(s) && karta->get_ground(n+1,k)!=0 && karta->get_ground(n+1,k)!=3) //проверка на нажание кнопки и на границы карты
        {
            down(karta->get_height(),karta->get_scalex()); //вызов функции для изменение положение
            n+=1; //движение по массиву
            if(karta->get_ground(n-1,k)!=2)
                karta->set_ground(n-1,k,3);

        }
        else if(GetAsyncKeyState(d) && karta->get_ground(n,k+1)!=0 && karta->get_ground(n,k+1)!=3)//проверка на нажание кнопки и на границы карты
        {

            right(karta->get_height(),karta->get_scalex());//вызов функции для изменение положение
            k+=1;//движение по массиву
            if(karta->get_ground(n,k-1)!=2)
                karta->set_ground(n,k-1,3);
        }
        else if(GetAsyncKeyState(w) && karta->get_ground(n-1,k)!=0 && karta->get_ground(n-1,k)!=3)//проверка на нажание кнопки и на границы карты
        {

            up(karta->get_height(),karta->get_scalex());//вызов функции для изменение положение
            n-=1;//движение по массиву
            if(karta->get_ground(n+1,k)!=2)
                karta->set_ground(n+1,k,3);
        }
        else if(GetAsyncKeyState(a) && karta->get_ground(n,k-1)!=0 && karta->get_ground(n,k-1)!=3)//проверка на нажание кнопки и на границы карты
        {

            left(karta->get_height(),karta->get_scalex());//вызов функции для изменение положение
            k-=1;//движение по массиву
            if(karta->get_ground(n,k+1)!=2)
                karta->set_ground(n,k+1,3);
        }
    }

    int checking()
    {
        if(karta->get_ground(n,k+1)==3 && karta->get_ground(n+1,k)==3 && karta->get_ground(n,k-1)==3 && karta->get_ground(n-1,k)==3)
        {
            txMessageBox("БОЖЕ ЧЕЛ, ТЫ ТАКОЙ БОТ, ТЕБЕ НЕКУДА ИДТИ, ЗНАЧИТ ТЫ НУБИК","СЛИВ");
            check=false;
        }
    }
    bool get_check(){return check;}

    void set_check(bool a){check=a;}
};
#endif
