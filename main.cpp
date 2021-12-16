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
    txMessageBox("ПРИВЕТСВУЕМ ВАС В ИГРЕ TNT-RUN!","ДОБРО ПОЖАЛОВАТЬ")
    txMessageBox("Ваша задача двигаться и набирать очки на поле столько, пока не попадёте в тупик.\nПосле чего робот попробует побить ваш рекорд.","Правила");
    txMessageBox("УПРАВЛЕНИЕ\nСтрелочки","Billie Jean");
    txBegin();
    while(person.get_check()==true)
    {
        int a = 0;
        int b = 0;
        karta.init(); //инициализация карты
        while(person.get_check()==true) //уровень 1
        {

            person.update(); //обновление положения персонажа
            person.checking();
            karta.draw(); //отрисовка карты
            person.draw(); //отрисовка персонажа


            txSleep(200); //задержка перед выполением цикла
            txClear();
            a=person.get_c();
            system("cls");
            printf("\n\n\n Кол-во очков->%d", a);

        }

        txMessageBox("Молодец, ты держался как мог, надеюсь в следующем уровне. \nты покажешь результат по лучше.","СЛИВ");
        person.set_check(true);
        txMessageBox("Посмотрим как справиться с этим бот.","БОТ");
        txMessageBox("ХА-ХА, я наберу больше, смотри и учись!","БОТ");
        system("cls");
        karta.init();

        srand(time(NULL));
        while(person.get_check()==true) //уровень 2
        {
            karta.draw(); //отрисовка карты


            person.update_bot(); //обновление положения персонажа
            person.checking();
            person.draw(); //отрисовка персонажа
            b=person.get_z();
            txSleep(200); //задержка перед выполением цикла
            txClear();
            system("cls");
            printf("\n\n\n Кол-во очков->%d", b);
        }
        if(a>b)
            txMessageBox("Вау, ты смог победить робота!\nВозьми с полки пирожок.","Победа");
        if(a==b)
            txMessageBox("Неплохо, твой разум и удача на уровне робота.\nНормально в принципе.","Ничья");
        if(a<b)
            txMessageBox("Ты проиграл рандомному роботу...\nЛивай из игры чел!","Поражение");
        txMessageBox("Чтобы выйти из игры нажми escape.\nЧтобы начать игру заново нажми space!","ВЫХОД?");
        while(person.get_check()==false)
        {
            if(GetAsyncKeyState(VK_SPACE))
                person.set_check(true);
            else if(GetAsyncKeyState(VK_ESCAPE))
                return 0;
        }
    }
    txMessageBox("Заходите ещё, с уважением, Артём Постников 9 В","Автор игры")
    txEnd();
    return 0;
}
