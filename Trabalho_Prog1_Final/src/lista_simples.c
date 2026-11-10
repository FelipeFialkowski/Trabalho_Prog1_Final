#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_simples.h"



void cria_lista(node_lista** cabeca){
    *cabeca = NULL;
}

void InsereInicio(node_lista** cabeca, int id_ingrediente, int quantidade, char* nome_ingrediente){

    node_lista* novo_no = malloc(sizeof(node_lista));

    strncpy(novo_no->nome_ingrediente, nome_ingrediente, sizeof(novo_no->nome_ingrediente) - 1);
    novo_no->nome_ingrediente[sizeof(novo_no->nome_ingrediente) - 1] = '\0'; 

    novo_no->quantidade = quantidade;
    novo_no->id_ingrediente = id_ingrediente;
    novo_no->prox = *cabeca;

    *cabeca = novo_no;
}

node_lista* Lista;

