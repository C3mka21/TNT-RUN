///@author postnikov

#include "TXRIP.h" //вызов библиотек
#include "person.h" //вызов библиотек


int main()
{
    txCreateWindow(WINDOWX, WINDOWY); //создание окна
    txSetFillColor(TX_BLACK); //выбор цвета
    txClear(); //заливка все экрана
    Karta karta_t; //
    Person person_t; //
    person_t.init_karta(&karta_t); //вызов функции для задачи указателя
    karta_t.init(); //инициализация карты
    person_t.norm_xny(karta_t.get_width(),karta_t.get_scalex(),karta_t.get_height()); //задача координат для персонажа
    person_t.set_pers(); //передача данных новому массиву
    while(!GetAsyncKeyState(VK_ESCAPE)) //цикл
    {
        karta_t.draw(); //отрисовка карты
        person_t.draw(); //отрисовка персонажа
        person_t.update(); //обновление положения персонажа
        txSleep(150); //задержка перед выполением цикла
    }
    return 0;
}
