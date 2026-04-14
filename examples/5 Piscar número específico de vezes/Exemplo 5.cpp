/*
Faz o LED piscar 5 vezes em 2 Hz e depois parar desligado.
*/
#include "LED.h"

Led led(13);

void setup()
{
    led.piscar(2, 5); // 5 piscadas em 2 Hz
}

void loop()
{
    led.update();
}