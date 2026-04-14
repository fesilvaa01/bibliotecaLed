/*
Faz o LED piscar continuamente a 2 Hz (2 ciclos por segundo), de forma automática.
*/
#include "LED.h"

Led led(13);

void setup()
{
    led.piscar(2); // 2 Hz
}

void loop()
{
    led.update();
}