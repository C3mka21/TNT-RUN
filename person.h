#ifndef __PERSON_H__
#define __PERSON_H__

#include "TXLib.h" //����������� �������� ����������


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

    int pers[10][10];  //������ ������� ��������� ������ ������� �������

    HDC photo1;
public:
    Person(): //�����������
    photo(txLoadImage("fnafb.bmp")),photo1(txLoadImage("karta.bmp")),x(370),y(370),x1(41),y1(6),width(134),height(197),scalex(0.3),scaley(0.3),color(TX_BLACK),xa(70),ya(8),v(5),d(VK_RIGHT),a(VK_LEFT),w(VK_UP),s(VK_DOWN),n(7),k(7)
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
        txDeleteDC(photo1);
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

    void update() //��������� � ���������� ���������
    {
        if(GetAsyncKeyState(VK_LBUTTON))
            printf("%d",pers[n-1][k]);
        if(GetAsyncKeyState(VK_RBUTTON))
            printf("%d",pers[n+1][k]);

        if(GetAsyncKeyState(s) && pers[n+1][k]<0 && pers[n+1][k]!=-3) //�������� �� ������� ������ � �� ������� �����
        {
            //Win32::TransparentBlt (txDC(), x, y, karta->get_width()*karta->get_scalex(),karta->get_height()*karta->get_scalex(), photo1, 980, 650, karta->get_width(), karta->get_height(), TX_WHITE); //���������
            down(karta->get_height(),karta->get_scalex()); //����� ������� ��� ��������� ���������
            n+=1; //�������� �� �������

            if(pers[n-1][k]!=-2)
                pers[n-1][k]=-3;
        }
        else if(GetAsyncKeyState(d) && pers[n][k+1]<0 && pers[n][k+1]!=-3)//�������� �� ������� ������ � �� ������� �����
        {
            //Win32::TransparentBlt (txDC(), x, y, karta->get_width()*karta->get_scalex(),karta->get_height()*karta->get_scalex(), photo1, 980, 650, karta->get_width(), karta->get_height(), TX_WHITE); //���������
            right(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            k+=1;//�������� �� �������
            if(pers[n][k-1]!=-2)
                pers[n][k-1]=-3;
        }
        else if(GetAsyncKeyState(w) && pers[n-1][k]<0 && pers[n-1][k]!=-3)//�������� �� ������� ������ � �� ������� �����
        {
            //Win32::TransparentBlt (txDC(), x, y, karta->get_width()*karta->get_scalex(),karta->get_height()*karta->get_scalex(), photo1, 980, 650, karta->get_width(), karta->get_height(), TX_WHITE); //���������
            up(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            n-=1;//�������� �� �������
            if(pers[n+1][k]!=-2)
                pers[n+1][k]=-3;
        }
        else if(GetAsyncKeyState(a) && pers[n][k-1]<0 && pers[n][k-1]!=-3)//�������� �� ������� ������ � �� ������� �����
        {
            //Win32::TransparentBlt (txDC(), x, y, karta->get_width()*karta->get_scalex(),karta->get_height()*karta->get_scalex(), photo1, 980, 650, karta->get_width(), karta->get_height(), TX_WHITE); //���������
            left(karta->get_height(),karta->get_scalex());//����� ������� ��� ��������� ���������
            k-=1;//�������� �� �������
            if(pers[n][k+1]!=-2)
                pers[n][k+1]=-3;
        }
    }

    int init_pers()
    {
        FILE* f;
        f = fopen("karta.txt", "r"); //�������� ����� karta.txt
        if (f==NULL) //�������� �� ������� ����� � ��������
        {
            txMessageBox("�� ������ ���� � ������","������ #1");
            return 1;
        }
        fscanf(f,"\n");
        for (int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                fscanf(f, "%d", &pers[i][j]); //���������� ������ �������
            }
            fscanf(f,"\n");
        }
        fclose(f); //�������� �����

        return 0;
    }


};
#endif
