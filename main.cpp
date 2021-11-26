///@author postnikov

#include "TXRIP.h"
#include "person.h"

int main()
{
    Karta karta_t;
    Person person_t;
    txCreateWindow(480, 480);
    txSetFillColor(TX_BLACK);
    txClear();
    person_t.norm_x(karta_t.get_width(),karta_t.get_scalex());
    person_t.init_karta(&karta_t);
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
