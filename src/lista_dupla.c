#include "lista_dupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cria_lista_dupla(lista_dupla *lista){
    lista->inicio = NULL;
    lista->fim = NULL;

    insere_inicio(lista, 1, "Estoque");
    insere_inicio(lista, 2, "Corte");
    insere_inicio(lista, 3, "Fogão");
    insere_inicio(lista, 4, "Montagem_prato");
    insere_inicio(lista, 5, "Entrega");
}

void insere_inicio(lista_dupla *lista, int id, char nome[50]){

    lista_dupla_no *novo = malloc(sizeof(lista_dupla_no));

    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);

    novo->ant = NULL;
    novo->prox = lista->inicio;

    lista->inicio = novo;

}

void insere_fim(lista_dupla *lista, int id, char nome[50]){

    lista_dupla_no *novo = malloc(sizeof(lista_dupla_no));

    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);

    novo->ant = lista->inicio;
    novo->prox = NULL;

    lista->fim = novo;
    
}

lista_dupla_no* localiza_estacao(lista_dupla *lista, int id){

    lista_dupla_no *atual = lista->inicio;

    while(atual != NULL){
        if (atual->id == id){
            return atual;
        }
        atual = atual->prox;
    }
}