///@author postnikov

#include "TXRIP.h"
#include "person.h"


int main()
{
    txCreateWindow(WINDOWX, WINDOWY); //�������� ����
    txSetFillColor(TX_BLACK); //����� �����
    txClear(); //������� ��� ������

    Karta karta; //
    Person person; //

    person.init_karta(&karta); //����� ������� ��� ������ ���������
    txMessageBox("����������� ��� � ���� TNT-RUN!","����� ����������")
    txMessageBox("���� ������ ��������� � �������� ���� �� ���� �������, ���� �� ������� � �����.\n����� ���� ����� ��������� ������ ��� ������.","�������");
    txMessageBox("����������\n���������","Billie Jean");
    txBegin();
    while(person.get_check()==true)
    {
        int a = 0;
        int b = 0;
        karta.init(); //������������� �����
        while(person.get_check()==true) //������� 1
        {

            person.update(); //���������� ��������� ���������
            person.checking();
            karta.draw(); //��������� �����
            person.draw(); //��������� ���������


            txSleep(200); //�������� ����� ���������� �����
            txClear();
            a=person.get_c();
            system("cls");
            printf("\n\n\n ���-�� �����->%d", a);

        }

        txMessageBox("�������, �� �������� ��� ���, ������� � ��������� ������. \n�� �������� ��������� �� �����.","����");
        person.set_check(true);
        txMessageBox("��������� ��� ���������� � ���� ���.","���");
        txMessageBox("��-��, � ������ ������, ������ � �����!","���");
        system("cls");
        karta.init();

        srand(time(NULL));
        while(person.get_check()==true) //������� 2
        {
            karta.draw(); //��������� �����


            person.update_bot(); //���������� ��������� ���������
            person.checking();
            person.draw(); //��������� ���������
            b=person.get_z();
            txSleep(200); //�������� ����� ���������� �����
            txClear();
            system("cls");
            printf("\n\n\n ���-�� �����->%d", b);
        }
        if(a>b)
            txMessageBox("���, �� ���� �������� ������!\n������ � ����� �������.","������");
        if(a==b)
            txMessageBox("�������, ���� ����� � ����� �� ������ ������.\n��������� � ��������.","�����");
        if(a<b)
            txMessageBox("�� �������� ���������� ������...\n����� �� ���� ���!","���������");
        txMessageBox("����� ����� �� ���� ����� escape.\n����� ������ ���� ������ ����� space!","�����?");
        while(person.get_check()==false)
        {
            if(GetAsyncKeyState(VK_SPACE))
                person.set_check(true);
            else if(GetAsyncKeyState(VK_ESCAPE))
                return 0;
        }
    }
    txMessageBox("�������� ���, � ���������, ���� ��������� 9 �","����� ����")
    txEnd();
    return 0;
}
