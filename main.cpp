///@author postnikov

#include "TXRIP.h"
#include "person.h"

int main()
{
    txCreateWindow(WINDOWX, WINDOWY);
    txSetFillColor(TX_BLACK);
    txClear();
    Karta karta_t;
    Person person_t;
    karta_t.init();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        karta_t.draw();
        person_t.draw();
        person_t.update();
        txSleep(50);
    }
    return 0;
}

