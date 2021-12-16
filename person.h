#ifndef __PERSON_H__
#define __PERSON_H__

#include "TXLib.h" //����������� �������� ����������
#include <random>


class Person
{
private:
    HDC photo; //��������� �� ����������� ��������

    int x; //��������� ������� �� ������ �� ��
    int y; //��������� ������� �� ������ �� ��
    int x1; //��������� ������� �� ��������� �� ��
    int y1; //��������� ������� �� ��������� �� ��
    int width; //����� ����� ����� �������
    int height; // ������ ����� ����� �������

    double scalex; //������ ��� ���������� ������� �� ��� ��
    double scaley; //������ ��� ���������� ������� �� ��� ��

    COLORREF color; //���� ������� ���������� �� �������

    int xa; //���������� ����� ��������� �� �����������
    int ya; //���������� ����� ��������� �� ���������

    Karta* karta;

    //������� ��� ���������

    int v; //�������� ���������

    char d; //������� � ������� �������� ���������� �������� ->
    char a; //������� � ������� �������� ���������� �������� <-
    char w; //������� � ������� �������� ���������� �������� (�����)
    char s; //������� � ������� �������� ���������� �������� (����)

    int k;  //��������� ��������� � ������ �� ������� �����
    int n;  //��������� ��������� � ������� �� ������� �����
    int c;
    int z;
    bool check;



public:
    Person(): //�����������
    photo(txLoadImage("fnafb.bmp")),x(265),y(374),x1(41),y1(6),width(134),height(197),scalex(0.3),scaley(0.3),color(TX_BLACK),xa(70),ya(8),v(5),d(VK_RIGHT),a(VK_LEFT),w(VK_UP),s(VK_DOWN),n(7),k(5),c(0),z(0),check(true)
    {
        if(!photo)
        {
            txMessageBox("�� ������ ���� � ����������","������ #3");
            exit(0);
        }
    }

    ~Person() //����������
    {
        txDeleteDC(photo); //�������� �������� �� ������
    }

    void init_karta(Karta* a) //������� ��� �������� ���������
    {
        karta=a;
    }

    void draw() //������� ���������
    {
        Win32::TransparentBlt (txDC(), x, y, width*scalex, height*scaley, photo, x1, y1, width, height, color); //���������
    }

    void up(int a, double b) //������� ��������� ��������� �����
    {
        y1=600;
        x1+=width+xa; //�������� ��  ����������� �������� ��� ��������� ��������� ��� � ���������
        y-=a*b; //�������� �� �����
        if(x1>=570) //����������� ����� �� ����������� ��������
        {
            x1=41;
        }
    }

    void left(int a, double b) //�������� �����
    {
        y1=205;
        x1-=width+xa; //�������� ��  ����������� �������� ��� ��������� ��������� ��� � ���������
        x-=a*b; //�������� �� �����
        if(x1<=29) //����������� ����� �� ����������� ��������
        {
            x1=427;
        }
    }

    void down(int a, double b) //�������� ����
    {
        y1=6;
        x1+=width+xa;//�������� ��  ����������� �������� ��� ��������� ��������� ��� � ���������
        y+=a*b;//�������� �� �����
        if(x1>=570) //����������� ����� �� ����������� ��������
        {
            x1=41;
        }
    }

    void right(int a, double b) //�������� ������
    {
        y1=405;
        x1+=width+xa;//�������� ��  ����������� �������� ��� ��������� ��������� ��� � ���������
        x+=a*b;//�������� �� �����
        if(x1>=570)//����������� ����� �� ����������� ��������
        {
            x1=41;
        }

    }

    void update()
    {
        if(GetAsyncKeyState(s) && karta->get_ground(n+1,k)!=0 && karta->get_ground(n+1,k)!=3) //�������� �� ������� ������ � �� ������� �����
        {
            down(karta->get_height(),karta->get_scalex()); //����� ������� ��� ��������� ���������
            n+=1; //�������� �� �������
            if(karta->get_ground(n-1,k)!=2)
                karta->set_ground(n-1,k,3);
            game_rand();
            c++;

        }
        else if(GetAsyncKeyState(d) && karta->get_ground(n,k+1)!=0 && karta->get_ground(n,k+1)!=3)//�������� �� ������� ������ � �� ������� �����
        {

            right(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            k+=1;//�������� �� �������
            if(karta->get_ground(n,k-1)!=2)
                karta->set_ground(n,k-1,3);
            game_rand();
            c++;
        }
        else if(GetAsyncKeyState(w) && karta->get_ground(n-1,k)!=0 && karta->get_ground(n-1,k)!=3)//�������� �� ������� ������ � �� ������� �����
        {

            up(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            n-=1;//�������� �� �������
            if(karta->get_ground(n+1,k)!=2)
                karta->set_ground(n+1,k,3);
            game_rand();
            c++;
        }
        else if(GetAsyncKeyState(a) && karta->get_ground(n,k-1)!=0 && karta->get_ground(n,k-1)!=3)//�������� �� ������� ������ � �� ������� �����
        {

            left(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            k-=1;//�������� �� �������
            if(karta->get_ground(n,k+1)!=2)
                karta->set_ground(n,k+1,3);
            game_rand();
            c++;
        }
    }

    void update_bot()
    {
        int a=rand()%4;
        if(a==1)
        {
            if(karta->get_ground(n+1,k)!=0 && karta->get_ground(n+1,k)!=3) //�������� �� ������� ������ � �� ������� �����
            {
                down(karta->get_height(),karta->get_scalex()); //����� ������� ��� ��������� ���������
                n+=1; //�������� �� �������
                if(karta->get_ground(n-1,k)!=2)
                    karta->set_ground(n-1,k,3);
                game_rand();
                z++;

            }
        }
        if(a==2)
        {
            if(karta->get_ground(n,k+1)!=0 && karta->get_ground(n,k+1)!=3)//�������� �� ������� ������ � �� ������� �����
            {

                right(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
                k+=1;//�������� �� �������
                if(karta->get_ground(n,k-1)!=2)
                    karta->set_ground(n,k-1,3);
                game_rand();
                z++;
            }
        }
        if(a==3)
        {
            if(karta->get_ground(n-1,k)!=0 && karta->get_ground(n-1,k)!=3)//�������� �� ������� ������ � �� ������� �����
            {

                up(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
                n-=1;//�������� �� �������
                if(karta->get_ground(n+1,k)!=2)
                    karta->set_ground(n+1,k,3);
                game_rand();
                z++;
            }
        }
        if(a==0)
        {
            if(karta->get_ground(n,k-1)!=0 && karta->get_ground(n,k-1)!=3)//�������� �� ������� ������ � �� ������� �����
            {

                left(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
                k-=1;//�������� �� �������
                if(karta->get_ground(n,k+1)!=2)
                    karta->set_ground(n,k+1,3);
                game_rand();
                z++;
            }
        }
    }
    int checking()
    {
        if((karta->get_ground(n,k+1)==3||(karta->get_ground(n,k+1)==0)) &&( karta->get_ground(n+1,k)==3|| karta->get_ground(n,k+1)==0) && (karta->get_ground(n,k-1)==3||karta->get_ground(n,k-1)==0) && (karta->get_ground(n-1,k)==3||karta->get_ground(n-1,k)==3))
        {
            check=false;
        }
    }

    bool get_check(){return check;}

    void set_check(bool a){check=a;}

    void game_rand()
    {

        int a=rand()%13;
        int b=rand()%13;

        if(karta->get_ground(a,b)==1)
            karta->set_ground(a,b,3);
    }

    int get_c(){return c;}
    int get_z(){return z;}
};
#endif
