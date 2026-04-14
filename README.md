# 📘 Biblioteca LED

Classe para controle **não bloqueante** de LED usando `millis()` (sem `delay()`).

## 🚀 Uso

#include "LED.h"

Led led(13);

void setup() {
  led.piscar(2, 5);
}

void loop() {
  led.update();
}
```

## ⚙️ Métodos

* 🔥 `acender()` → Liga
* ⏱️ `acender(ms)` → Liga por tempo
* ❌ `apagar()` → Desliga
* 🔁 `alternar()` → Inverte estado
* 🎛️ `setEstado(bool)` → Define estado
* ⚡ `piscar()` → Pisca contínuo (~1Hz)
* 📡 `piscar(freq)` → Pisca com frequência (Hz)
* 🔢 `piscar(freq, rep)` → Pisca X vezes

## ⚠️ Importante

* Sempre chamar `update()` no `loop()`
* Não usa `delay()`
* `freq` não pode ser 0


