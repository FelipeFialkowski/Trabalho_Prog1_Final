#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedidos.h"
#include "receitas.h"


void inicializa_fila(fila *pedidos){
    pedidos->primeiro = NULL;
    pedidos->ultimo = NULL;
    pedidos->tamanho = 0;
}

void insere(fila *pedidos, int id, char prato[50], int turno, int prazo, int pontuacao){

    fila_no *novo = malloc(sizeof(fila_no));
    if (novo == NULL){
        printf("Erro na alocação da memoria");
        return;
    }
    novo->id = id;
    strncpy(novo->prato, prato, sizeof(novo->prato) - 1);
    novo->turno = turno;
    novo->prazo = prazo;
    novo->pontuacao = pontuacao;
    novo->prox = NULL;

    if (pedidos->ultimo == NULL){ //fila vazia
        pedidos->primeiro = novo;
        pedidos->ultimo = novo;
    }
    else{
        pedidos->ultimo->prox = novo;
        pedidos->ultimo = novo;
    }
    pedidos->tamanho++;
}

fila_no* remover(fila *pedidos){
    if (pedidos->primeiro == NULL)
        return NULL;

    fila_no *removido = pedidos->primeiro;
    pedidos->primeiro = removido->prox;

    if (pedidos->primeiro == NULL)
        pedidos->ultimo = NULL;

    removido->prox = NULL;
    pedidos->tamanho--;
    return removido;
}

void liberar_nos(fila *pedidos){

    fila_no *atual = pedidos->primeiro;
    
    while(atual != NULL){
        fila_no *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    pedidos->primeiro = NULL;
    pedidos->ultimo = NULL;
    pedidos->tamanho = 0;
}

void gerar_pedido(fila *pedidos, int turno, int *proximo_id){
    if(turno > 0 && turno % 3 == 0){
        char *pratos[] = {"Hamburguer", "Salada", "Sopa"};
        int escolhido = rand() % 3;
        insere(pedidos, *proximo_id, pratos[escolhido], turno, turno + 10, 100);
        (*proximo_id)++;
    }
}


void consultar_pedidos(fila *pedidos){

    if(pedidos->ultimo == NULL)
        printf("Não há nenhum pedido\n");
    
    for (fila_no *p = pedidos->primeiro; p != NULL; p = p->prox)
            printf("Pedido #%d - %s | Turno: %d | Prazo: %d | Pontos: %d\n", p->id, p->prato, p->turno, p->prazo, p->pontuacao);
}

fila_no* consultar_primeiro(fila *pedidos){
    if(pedidos->primeiro = NULL)
        return NULL;
    return pedidos->primeiro;
}