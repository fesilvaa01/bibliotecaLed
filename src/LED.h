#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueantes de um LED.
 * 
 * Permite ligar, desligar, ligar por um tempo,
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note O método update() deve ser chamado dentro do loop().
 */
class Led
{

private:

uint8_t pino;
bool estado;

bool apagarNoTempo;
uint32_t apagarNoMomento;
bool estadoPiscar;

uint32_t tempoEspera;
uint32_t tempoAnteriorPiscar;
uint16_t repeticoes;


/**
 * @brief Processa o desligamento temporizado do LED.
 */
void funcaoApagarNoTempo();

/** 
 * @brief Processa a lógica de piscada do LED.
*/
void funcaoPiscar();

public:

/**
 * @brief Constrói um objeto LED.
 * @param pin Número do pino digital onde o LED está conectado.
 */
Led(uint8_t pin); //* METODO CONSTRUTOR

/**
 * @brief Liga o LED continuamente.
 */
void acender();

/**
 * @brief Liga o LED por um tempo determinado.
 * @param tempoLigado Tempo, em milissegundos, que o LED permanecerá aceso.
 */
void acender(uint32_t tempoLigado);

/**
 * @brief Desliga o LED e cancela modos automáticos.
 */
void apagar();

/**
 * @brief Pisca o LED continuamente e cancela modos automáticos.
 */
void piscar();

/**
 * @brief Faz o LED piscar continuamente em uma frequência específica.
 * @param freq Frequência de piscada em Hz.
 */
void piscar(float freq);

/**
 * @brief Faz o LED piscar por um número específico de vezes em uma frequência específica.
 * @param freq Frequência de piscada em Hz.
 * @param repeticoes Número de vezes que o LED deve piscar.
 */
void piscar(float freq, uint16_t repeticoes);

/**
 * @brief Alterna o estado do LED (ligado/desligado) e cancela modos automáticos.
 */
void alternar();

/**
 * @brief Define o estado do LED (ligado/desligado) e cancela modos automáticos.
 * @param estado true para ligar o LED, false para desligar.
 */
void setEstado(bool estado);

/**
 * @brief Retorna o número do pino digital onde o LED está conectado.
 */
uint8_t getPino();

/**
 * @brief Atualiza o estado do LED. Deve ser chamado dentro do loop() para processar modos automáticos.
 */
void update();




};




#endif