/*
Alterna o estado do LED a cada 2 segundos, criando um efeito de pisca controlado manualmente.
*/
#include "LED.h"

Led led(13);
unsigned long tempoAnterior = 0;

void setup() {}

void loop()
{
    if (millis() - tempoAnterior >= 2000)
    {
        tempoAnterior = millis();
        led.alternar();
    }

    led.update();
}