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
    karta.init(); //������������� �����
    txMessageBox("����������:\nC����������","������� 1");

    while(person.get_check()==true) //������� 1
    {
        karta.draw(); //��������� �����


        person.update(); //���������� ��������� ���������
        person.checking();
        person.draw(); //��������� ���������

        txSleep(200); //�������� ����� ���������� �����
        txClear();

    }
    person.set_check(true);
    txMessageBox("����, ���� �����","������� 2");

    karta.init2(); //������������� �����
    while(person.get_check()==true) //������� 2
    {
        karta.draw(); //��������� �����


        person.update(); //���������� ��������� ���������
        person.checking();
        person.draw(); //��������� ���������

        txSleep(200); //�������� ����� ���������� �����
        txClear();
    }
    txMessageBox("�����, �� ��������","�����");
    return 0;
}
