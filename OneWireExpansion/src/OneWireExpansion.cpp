#include "OneWireExpansion.h"

OneWireExpansion::OneWireExpansion(int pino) {
  _pino = pino;
  pinMode(_pino, OUTPUT);
  digitalWrite(_pino, 1);
  resetar();
}

void OneWireExpansion::resetar() {
  digitalWrite(_pino, 0);
  delayMicroseconds(350);
  digitalWrite(_pino, 1);
  delayMicroseconds(100);
}

void OneWireExpansion::enviarByte(uint8_t b, bool LSF = true) {
  digitalWrite(_pino, 0);
  digitalWrite(_pino, 1);
  byte tempos[14], cont, bt;
  bool ba = true;
  bool bit, pb;
  if (!LSF) {
    byte r = 0;
    for (cont = 0; cont < 8; cont++) r |= ((b >> cont) & 1) << (7 - cont);
    bt = r;
  } else bt = b;
  for (cont = 0; cont < 7; cont++) {
    bit = bool(bt & (1 << cont));
    pb = (cont == 6) ? true : bool(bt & (1 << (cont + 1)));

    if (bit) tempos[2 * cont] = 0;       // se o bit é 1, não precisa esperar pra mudar de valor de entrada
    else if (ba) tempos[2 * cont] = 20;  // se o bit é 0 e o anterior era 1, então tem q esperar descer
    else tempos[2 * cont] = 15;          // se o bit é 0 e o anterior era 0, tem que esperar um pouquinho.

    if (!pb) tempos[2 * cont + 1] = 0;        // se o próximo é 0, não tem que esperar
    else if (bit) tempos[2 * cont + 1] = 25;  // se o bit é 1 e o próximo é 1, tem que esperar TB1
    else tempos[2 * cont + 1] = 40;           // se o bit é 0 e o próximo é 1, tem que esperar TB0
    ba = bit;
  }
  for (cont = 0; cont < 7; cont++) {
    digitalWrite(_pino, 0);
    delayMicroseconds(tempos[2 * cont]);
    digitalWrite(_pino, 1);
    delayMicroseconds(tempos[2 * cont + 1]);
  }
  delayMicroseconds(300);
  resetar();
}