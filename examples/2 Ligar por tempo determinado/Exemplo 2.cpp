/*
Liga o LED por 3 segundos e depois desliga automaticamente, sem travar o programa.
*/
#include "LED.h"

Led led(13);

void setup()
{
    led.acender(3000); // liga por 3 segundos
}

void loop()
{
    led.update();
}