//body
#include "apputils.h"
#include <stdio.h>
#include <stdlib.h>

void cabecalho (char *titulo){
     printLn (titulo);
};

void fim(){
     printLn ("Fim de execucao do programa!");
};



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
    printLn();
    printString ("Pressione <ENTER> para continuar...");
    getchar();
}