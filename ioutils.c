#include "ioutils.h"
#include <ctype.h>
#include <stdio.h>

#define TRUE 1

void limparBuffer(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {}
}

void printLn(void){
    printf ("\n");
}


void printInt(const int valor){
    printf ("%d", valor);
}

//por recursao, assumindo custo so pra manter pra exemplo didatico recursivo
int scanInt(const char *mensagem) {
    int valor;
    printf("\n%s: ", mensagem);
    if (scanf("%d", &valor) != TRUE) {
        limparBuffer();
        printf("\nErro de leitura, informe novamente!");
        return scanInt(mensagem);
    }
    limparBuffer();
    return valor;
}

void printFloat(float valor) {
    printf("%.2f", valor);
}

float scanFloat(const char *mensagem) {
    float valor;

    while (TRUE) {
        printf("\n%s: ", mensagem);

        if (scanf("%f", &valor) == TRUE) {
            limparBuffer();
            return valor;
        }

        limparBuffer();
        printf("\nErro de leitura, informe novamente!");
    }
}


void printfloat(const float valor){
    printf ("%.2f", valor);
}

double scanDouble(const char *mensagem) {
    double valor;

    while (TRUE) {
        printf("\n%s: ", mensagem);

        if (scanf("%lf", &valor) == TRUE) {
            limparBuffer();
            return valor;
        }

        limparBuffer();
        printf("\nErro de leitura, informe novamente!");
    }
}

void printDouble(const double valor) {
    printf("%.2lf", valor);
}

char scanChar(const char *mensagem) {
    int c;

    while (TRUE) {
        printf("\n%s: ", mensagem);

        c = getchar(); //char + <ENTER>, senão gecth()

        if (c != EOF) {
            limparBuffer();
            return (char)c;
        }

        limparBuffer();
        printf("\nErro de leitura, informe novamente!");
    }
}

void printChar(const char valor) {
    printf("%c", valor);
}

int scanString(const char *mensagem, char *texto, int tamanho) {
    int i;

    printf("%s: ", mensagem);

    if (fgets(texto, tamanho, stdin) == NULL) {
        return 0;
    }

    i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == '\n') {
            texto[i] = '\0';
            return 1;
        }
        i++;
    }

    limparBuffer();
    return TRUE;
}

void printString(const char *mensagem) {
    printf("%s", mensagem);
}

void printStringLn(const char *mensagem) {
    puts(mensagem);
}


//para caso de uso de ponteiro pra char

/*
 usos: char nome* = scanfString("...", 20);
 nao funciona para char nome[n] ou char[] = scanString


char *scanString(const char *mensagem, int tamanho) {
    char *texto;
    int i;

    texto = (char *) malloc(tamanho * sizeof(char));
    if (texto == NULL) {
        return NULL;
    }

    printf("\n%s: ", mensagem);

    if (fgets(texto, tamanho, stdin) == NULL) {
        free(texto);
        return NULL;
    }

    i = 0;
    while (texto[i] != '\0') {
        if (texto[i] == '\n') {
            texto[i] = '\0';
            return texto;
        }
        i++;
    }

    limparBuffer();
    return texto;
}*/







