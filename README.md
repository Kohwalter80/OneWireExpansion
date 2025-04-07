# OneWireExpansion
Biblioteca para controlar um 74HC595 como expansão de saída digital de um Arduino, com 7 bits.

Pino do Arduino ligado no pino 11 do 74HC595. Pinos 13 e 8 no GND. Pino 16 no Vcc (5V). Pino 9 no 12. Entre o 10 e o 11, um resistor de 47k e um diodo 1N4148, com catodo ligado no pino 10. Entre o 14 e 11, um resistor de 2k2. Dois capacitores de 4n7, um entre o pino 10 e GND, e outro entre o pino 14 e GND.

As saídas são Qa (15), Qb (1), Qc (2), Qd (3), Qe (4), Qf (5) e Qg (6). A saída Qh (7) não é utilizada, e deve ser deixada flutuante.
