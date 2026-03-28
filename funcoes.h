#ifndef FUNCOES_H
#define FUNCOES_H

#include "lib.h"


void atribuirString (char *destino, const char *origem);
BOOLEAN stringIguais (const char *uma, const char *outra);

int dividirInteiro (const double dividendo, const double divisor);
float dividirDecimal (const double dividendo, const double divisor);

short int valorNaFaixa (const double inicio, const double fim, const double valor);
short int valorForaFaixa (const double inicio, const double fim, const double valor);

double valorSobrePercentual (const double valorBase, const float percentual);
double reduzirPercentualValor (const double valorBase, const float percentual);
double aumentarPercentualValor (const double valorBase, const float percentual);


#endif