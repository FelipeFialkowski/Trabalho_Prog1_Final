#include "ingredientes.h"

//ingredientes com quantidade igual a 0(zero) permanecem na lista

//começamos o jogo ja com uma quantia aleatória de cada ingrediente,sendo possivel adicionar mais

lista_simples* cria_lista(void){
    lista_simples *lista = malloc(sizeof(lista_simples));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

void destroi_lista(lista_simples *lista){
    if (lista == NULL) //por agum motivo isso para o segmentation fault
        return; 
    ingredientes *atual = lista->inicio; //vamos destruir a lsita pelo inicio
    while(atual !=NULL){
        ingredientes *proximo = atual->prox; //salva o proximo pra não perder o ponteiro
        free(atual);
        atual = proximo;
    }
    free(lista);//acaba com toda a lista depois de esvaziar ela
}