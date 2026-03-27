//body
#include "apputils.h"
#include <stdio.h>
#include <stdlib.h>

void cabecalho (char *titulo){
     printf ("\n%s\n", titulo);
};

void fim(){
     printf ("\n%s\n", "Fim de execucao do programa!");
};

void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
}

void limparTela(void) {
    int resultado;
    
    #ifdef _WIN32
        resultado = system("cls");
    #else
        resultado = system("clear");
    #endif

    if (resultado != 0) {
    }
}

void pausar(void) {
    printf("\nPressione <ENTER> para continuar...");
    getchar();
}