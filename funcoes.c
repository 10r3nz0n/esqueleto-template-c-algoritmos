#include "funcoes.h"
#include <string.h>
#include <math.h>

void atribuirString (char *destino, const char *origem){
    
    strcpy (destino, origem);
    
}

//retorna TRUE se forem iguais

BOOLEAN stringIguais (const char *uma, const char *outra){
    
    return strcmp (uma, outra) == 0;
    
}

int dividirInteiro (const double dividendo, const double divisor){
    
    //quociente int
    return (int) ((int) dividendo / (int) divisor);
    
}

float dividirDecimal (const double dividendo, const double divisor) {
    
    //quociente float - cuidar double - se volta pra int trunca
    return (float) ((float) dividendo / (float) divisor);
    
}


short int valorNaFaixa (const double inicio, const double fim, const double valor){
    
    return (valor >= inicio && valor <= fim ) ? TRUE : FALSE;
    
}


short int valorForaFaixa (const double inicio, const double fim, const double valor){
    
    return (valor < inicio || valor > fim ) ? TRUE : FALSE;
    
}

double valorSobrePercentual (const double valorBase, const float percentual){
    
    return ((valorBase * percentual) / 100);
    
}

double reduzirPercentualValor (const double valorBase, const float percentual){
    
    double aux = valorBase;
    aux = aux * (1 - (percentual/100));
    return aux;
    
}

double aumentarPercentualValor (const double valorBase, const float percentual){
    
    double parcial = (valorBase * percentual) / 100;
    return (valorBase + parcial);
    
}








