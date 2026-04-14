
# Biblioteca LED (Arduino / ESP32)

Classe para controle **não bloqueante** de LED utilizando `millis()`, evitando o uso de `delay()` e permitindo que o restante do programa continue executando normalmente.

## Descrição

A classe `Led` encapsula o controle de um LED digital, oferecendo funcionalidades como acionamento simples, temporizado e modos de piscada com controle de frequência e repetição.

O funcionamento é baseado em atualização contínua via `update()`, que deve ser chamada dentro do `loop()`.

---

## Uso básico

```cpp
#include "LED.h"

Led led(13);

void setup() {
  led.piscar(2, 5);
}

void loop() {
  led.update();
}
```

---

## Métodos

* `acender()`
  Liga o LED continuamente.

* `acender(uint32_t tempoLigado)`
  Liga o LED por um tempo determinado (em milissegundos).

* `apagar()`
  Desliga o LED e cancela qualquer modo ativo.

* `alternar()`
  Inverte o estado atual do LED.

* `setEstado(bool estado)`
  Define manualmente o estado do LED.

* `piscar()`
  Pisca continuamente com frequência padrão (~1 Hz).

* `piscar(float freq)`
  Pisca continuamente com frequência definida (Hz).

* `piscar(float freq, uint16_t repeticoes)`
  Pisca um número específico de vezes.

* `update()`
  Atualiza o estado do LED. Deve ser chamado constantemente no `loop()`.

---

## Funcionamento interno

* Utiliza `millis()` para controle de tempo
* Não utiliza `delay()`
* O LED pode operar em dois modos principais:

  * Temporizado (ligado por um período)
  * Piscando (com controle de frequência)
* Ao ativar um modo, os demais são automaticamente cancelados
* O estado físico do pino é atualizado a cada chamada de `update()`

---

## Parâmetros e comportamento

* A frequência (`freq`) define quantas vezes o LED completa um ciclo por segundo
* O tempo de alternância é calculado internamente a partir da frequência
* O número de repetições considera ciclos completos (ligar + desligar)
* O controle interno usa variáveis de tempo para garantir precisão sem bloquear o código

---

## Estrutura

* `LED.h` → definição da classe
* `LED.cpp` → implementação dos métodos

---

## Exemplo adicional

```cpp
#include "LED.h"

Led led(13);

void setup() {
  led.acender(3000); // liga por 3 segundos
}

void loop() {
  led.update();
}
```

---

## Boas práticas

* Sempre chamar `update()` dentro do `loop()`
* Evitar múltiplas chamadas de métodos diferentes sem necessidade (um modo cancela o outro)
* Usar frequências coerentes (valores muito altos podem gerar comportamento inesperado dependendo do hardware)
* Manter o código organizado quando trabalhar com múltiplos LEDs (ex: arrays ou objetos separados)

---


