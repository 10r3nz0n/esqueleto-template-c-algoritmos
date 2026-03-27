/*2026-1: Lorenzon. Esqueleto para algoritmos.*/

//inclusao de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "apputils.h"
#include "ioutils.h"

#define SUCESSO 0
#define FALHA 1

//Macros #define ISSO aquilo

int main(void) { 
    limparTela();
	//Faça declarações no topo, organize o pensamento
	char nome[20];
	int exemplo;
	//Inicialize as variáveis na declaracao ou depois dela
	exemplo = 0;

    //Escreva a função do programa para o cabeçalho
    //O usuario precisa de informacao
    cabecalho("Bem vindo ao template 2.0 da disciplina!");

	//Entradas por teclado
	scanString ("Informe seu nome", nome, 20);
	printLn();
	//Realize processamentos e combine entradas ou saídas

	//Saidas de resultados no terminal
	printString ("Muito obrigado por me executar ");
	printString (nome);
	pausar();
	fim();
	return SUCESSO;
}






