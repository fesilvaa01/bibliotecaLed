/*
Liga o LED continuamente assim que o programa inicia. Nenhuma automação, só fica ligado até alguém mandar desligar.
*/
#include "LED.h"

Led led(13);

void setup()
{
  led.acender();
}

void loop()
{
  led.update();
}