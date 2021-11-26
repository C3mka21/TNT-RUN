///@author postnikov

#include "TXRIP.h"
#include "person.h"

int main()
{
    Karta karta_t;
    Person person_t;
    txCreateWindow(karta_t.width*8*karta_t.scalex, karta_t.height*8*karta_t.scaley);
    txSetFillColor(TX_BLACK);
    txClear();

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
