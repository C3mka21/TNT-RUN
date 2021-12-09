///@author postnikov

#include "TXRIP.h"
#include "person.h"

int main()
{
    txCreateWindow(WINDOWX, WINDOWY); //создание окна
    txSetFillColor(TX_BLACK); //выбор цвета
    txClear(); //заливка все экрана

    Karta karta; //
    Person person; //

    person.init_karta(&karta); //вызов функции для задачи указателя
    karta.init(); //инициализация карты

    while(!GetAsyncKeyState(VK_ESCAPE)) //цикл
    {
        karta.draw(); //отрисовка карты
        person.draw(); //отрисовка персонажа

        person.update(); //обновление положения персонажа
        person.check();

        txSleep(150); //задержка перед выполением цикла
        txClear();

    }
    return 0;
}
