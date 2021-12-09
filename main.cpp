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

    while(!GetAsyncKeyState(VK_ESCAPE)) //����
    {
        karta.draw(); //��������� �����
        person.draw(); //��������� ���������

        person.update(); //���������� ��������� ���������
        person.check();

        txSleep(150); //�������� ����� ���������� �����
        txClear();

    }
    return 0;
}
