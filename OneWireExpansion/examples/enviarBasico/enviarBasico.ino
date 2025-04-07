#include "OneWireExpansion.h"

OneWireExpansion saida(3);  // envia os dados pelo pino D3

void setup() {}

void loop() {
  byte i;
  for (i = 0; i < 128; i++) saida.enviarByte(i);
  for (i = 0; i < 128; i++) saida.enviarByte(i << 1, false);
}