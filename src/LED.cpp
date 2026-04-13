#include "LED.h"
Led::Led(uint8_t pin) :
  pino(pin),
  estado(LOW),
  apagarNoTempo(false),
  apagarNoMomento(false),
  estadoPiscar(false),
  tempoEspera(0),
  tempoAnteriorPiscar(0),
  repeticoes(0)
{
  pinMode(pino, OUTPUT);
}

void Led::acender()
{
  estado = HIGH;
  estadoPiscar = false;
  apagarNoTempo = false;
}

void Led::acender(uint32_t tempoLigado)
{
  estado = HIGH;
  apagarNoTempo = true;
  apagarNoMomento = millis() + tempoLigado;
  estadoPiscar = false;
}

void Led::apagar()
{
  estado = LOW;
  estadoPiscar = false;
  apagarNoTempo = false;
}

void Led::alternar()
{
  estado = !estado;
  estadoPiscar = false;
  apagarNoTempo = false;
}

void Led::setEstado(bool estado)
{
  this->estado = estado;
  estadoPiscar = false;
  apagarNoTempo = false;
}

uint8_t Led::getPino()
{
  return pino;
}

void Led::update()
{
  if (apagarNoTempo) 
  {
    funcaoApagarNoTempo();
  }
  
  if(estadoPiscar)
  {
    funcaoPiscar();
  }
  
  digitalWrite(pino, estado);

}

void Led::piscar()
{
  estadoPiscar = true;
  tempoEspera = 500;
  tempoAnteriorPiscar = millis();
  estado = HIGH;
  apagarNoTempo = false;
  repeticoes = -1;
}

void Led::piscar(float freq)
{
 if(freq == 0)
 {
  return;
 }
 
  estadoPiscar = true;
  tempoEspera = 1000.0f / (2.0f * freq); 
  tempoAnteriorPiscar = millis();
  estado = HIGH;
  apagarNoTempo = false;
  repeticoes = -1;
}

void Led::piscar(float freq, uint16_t repeticoes)
{
  if(freq == 0)
 {
  return;
 }
  
  estadoPiscar = true;
  tempoEspera = 1000.0f / (2.0f * freq); // Converte frequência para tempo em milissegundos
  tempoAnteriorPiscar = millis();
  estado = HIGH;
  apagarNoTempo = false;

  this->repeticoes = repeticoes * 2;
}

void Led::funcaoApagarNoTempo()
{
  if (millis() >= apagarNoMomento) 
    {
      estado = LOW;
      apagarNoTempo = false;
    }
}


void Led::funcaoPiscar()
{
  if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
      estado = !estado;
      tempoAnteriorPiscar = millis();
      if(repeticoes > 0)
      {
        repeticoes--;
        if(repeticoes == 0)
        {
          estadoPiscar = false;
          estado = LOW;
        }
      }
    }
}