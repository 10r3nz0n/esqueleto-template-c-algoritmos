#ifndef IOUTILS_H
#define IOUTILS_H

#include "apputils.h"

void printLn();

void    printInt       (const int valor);
int     scanInt        (const char *mensagem);

float   scanFloat      (const char *mensagem);
void    printFloat     (const float valor);

void    printDouble    (const double valor);
double  scanfDouble    (const char *mensagem);

void    printChar      (const char valor);
char    scanChar       (const char *mensagem);

void    printString    (const char *mensagem);
void    printStringLn  (const char *mensagem);
int     scanString     (const char *mensagem, char *texto, int tamanho);
//char *scanString(const char *mensagem, int tamanho); guardado

#endif