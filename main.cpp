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
    txMessageBox("УПРАВЛЕНИЕ:\nCтрелочками","УРОВЕНЬ 1");

    while(person.get_check()==true) //уровень 1
    {
        karta.draw(); //отрисовка карты


        person.update(); //обновление положения персонажа
        person.checking();
        person.draw(); //отрисовка персонажа

        txSleep(200); //задержка перед выполением цикла
        txClear();

    }
    person.set_check(true);
    txMessageBox("ОКЕЙ, ЛЕТС ГОООО","УРОВЕНЬ 2");

    karta.init2(); //инициализация карты
    while(person.get_check()==true) //уровень 2
    {
        karta.draw(); //отрисовка карты


        person.update(); //обновление положения персонажа
        person.checking();
        person.draw(); //отрисовка персонажа

        txSleep(200); //задержка перед выполением цикла
        txClear();
    }
    txMessageBox("УРААА, ТЫ ПРОИГРАЛ","ЛОШОК");
    return 0;
}
