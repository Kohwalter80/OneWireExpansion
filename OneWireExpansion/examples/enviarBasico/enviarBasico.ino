#include "OneWireExpansion.h"

OneWireExpansion saida(3); // envia os dados pelo pino D3

void setup() {}

void loop() {
  for (byte i = 0; i < 128; i++) saida.enviaByte(i);
}