#include "pilha.h"

void inicializa_pilha(pilha *pratos){

    pratos->topo = NULL;
    pratos->tamanho = 0;
    
}

void push(pilha *pratos, int numero){


    pilha_no *novo = malloc(sizeof(pilha_no));

    if (novo == NULL){
        return;

    }

    novo->prato = numero;
    novo->prox = pratos->topo;

    pratos->topo = novo;
    pratos->tamanho++;

}

void pop(pilha *pratos){

    if (pratos->topo == NULL){
        return;
    }

    pilha_no *aux = pratos->topo;
    pratos->topo = pratos->topo->prox;

    free(aux);
    pratos->tamanho--;
}

pilha_no peek(pilha *pratos){

    pilha_no *novo = pratos->topo;
    return *novo;

}

bool pilha_vazia(pilha *pratos){

    if (pratos->topo == NULL){
        return true;
    }
    else{
        return false;
    }
}

void libera_no(pilha *pratos){

    if(pratos->topo == NULL){
        return ;
    }

    pilha_no *aux;
    while (aux != NULL){
        aux = pratos->topo;
        pratos->topo = pratos->topo->prox;
        free(aux);
    }
    pratos->tamanho = 0;
}