#ifndef PILHA_H
#define PILHA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct pilha_no{

    int prato;
    struct pilha_no *prox;
    
} pilha_no;

typedef struct pilha{

    pilha_no *topo;
    int tamanho;
    
} pilha;


void inicializa_pilha(pilha *pratos);
void push(pilha *pratos, int numero);
void pop(pilha *pratos);
pilha_no pek(pilha *pratos);
bool pilha_vazia(pilha *pratos);
void libera_no(pilha *pratos);


#endif