#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedidos.h"
#include "receitas.h"


void inicializa_fila(fila *pedidos){

    pedidos->primeiro = NULL;
    pedidos->ultimo = NULL;
}

void insere(fila *pedidos, int id, char prato[50], int turno, int prazo, int pontuacao){

    fila_no *novo = malloc(sizeof(fila_no));
    novo->id = id;
    strncpy(novo->prato, prato, sizeof(novo->prato) - 1);
    novo->turno = turno;
    novo->prazo = prazo;
    novo->pontuacao = pontuacao;

    if (pedidos->ultimo == NULL){
        pedidos->primeiro = novo;
    }
    pedidos->ultimo->prox = novo;
    pedidos->ultimo = novo;
    
}

fila_no* remover(fila *pedidos){

    fila_no *novo = pedidos->primeiro;
    if (pedidos->primeiro == NULL){
        pedidos->ultimo = NULL;
    }   
    pedidos->primeiro = pedidos->primeiro->prox;
    free(pedidos->primeiro);

    return novo;
}

void libera_nos(fila *pedidos){

    fila_no *remove = pedidos->primeiro;
    
    while(remove != NULL){
        fila_no *prox = remove->prox;
        free(remove);
        remove = prox;
    }

    pedidos->primeiro = NULL;
    pedidos->ultimo = NULL;
}
//Tem que ver isso ainda
/*
void gerar_pedido(fila *pedidos, int turno, int id, int prato, int prazo, int pontuacao){
    if(turno % 3 == 0){
        insere(pedidos, id, prato, turno, prazo, pontuacao);
    }
}
*/