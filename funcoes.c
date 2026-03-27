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

int dividirInteiro (float dividendo, float divisor){
    
    //quociente int
    return (int) ((int) dividendo / (int) divisor);
    
}

float dividirDecimal (float dividendo, float divisor){
    
    //quociente float - cuidar double - se volta pra int trunca
    return (float) ((float) dividendo / (float) divisor);
    
}