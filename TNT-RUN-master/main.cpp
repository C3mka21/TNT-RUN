///@author postnikov

#include "TXRIP.h" //����� ���������
#include "person.h" //����� ���������


int main()
{
    txCreateWindow(WINDOWX, WINDOWY); //�������� ����
    txSetFillColor(TX_BLACK); //����� �����
    txClear(); //������� ��� ������
    Karta karta_t; //
    Person person_t; //
    person_t.init_karta(&karta_t); //����� ������� ��� ������ ���������
    karta_t.init(); //������������� �����
    person_t.init_pers();
    person_t.norm_xny(karta_t.get_width(),karta_t.get_scalex(),karta_t.get_height()); //������ ��������� ��� ���������
    while(!GetAsyncKeyState(VK_ESCAPE)) //����
    {
        karta_t.draw(); //��������� �����
        person_t.draw(); //��������� ���������
        person_t.update(); //���������� ��������� ���������
        txSleep(150); //�������� ����� ���������� �����
    }
    return 0;
}
