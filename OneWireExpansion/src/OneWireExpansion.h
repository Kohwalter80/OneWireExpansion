#ifndef OneWireExpansion_h
#define OneWireExpansion_h

#include <Arduino.h>

// Envia um conjunto de 7 bits a cada 2,2 ms.

class OneWireExpansion {
  public:
    OneWireExpansion(int pino);
    void enviarByte(uint8_t b, bool LSF = true);
  private:
    int _pino;
    void resetar();
};

#endif
