#include "ingredientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ingredientes com quantidade igual a 0(zero) permanecem na estoque

//começamos o jogo ja com uma quantia aleatória de cada ingrediente,sendo possivel adicionar mais

lista_simples* cria_lista(void){
    lista_simples *estoque = malloc(sizeof(lista_simples));
    estoque->inicio = NULL;
    estoque->tamanho = 0;
    return estoque;
}

void destroi_lista(lista_simples *estoque){
    if (estoque == NULL) //por agum motivo isso para o segmentation fault
        return; 
    ingrediente *atual = estoque->inicio; //vamos destruir a lista pelo inicio
    while(atual !=NULL){
        ingrediente *proximo = atual->prox; //salva o proximo pra não perder o ponteiro
        free(atual);
        atual = proximo;
    }
    free(estoque);//acaba com toda a lista depois de esvaziar ela
}

int insere_ingrediente(lista_simples *estoque,int id,const char *nome,int quantidade){
    ingrediente *novo = malloc(sizeof(ingrediente)); //cria um novo nó

    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';  // garante que termina com \0
    novo->quantidade = quantidade;
    novo->prox = NULL;

    /*por ser mais facil de implementar, os elementos vão ser inseridos no
    inicio da lista*/

    novo->prox = estoque->inicio; //a struct novo aponta para onde era o inicio original
    estoque->inicio = novo; //o struct novo se torna o novo inciio

    estoque->tamanho++;

    return 1;
}

ingrediente* busca_ingrediente(lista_simples *estoque, int id){
    ingrediente *atual = estoque->inicio;
    while(atual != NULL){ //verifica se ja não é o ultimo elemento da estoque
        if (atual->id == id)
            return atual;
        atual = atual->prox; //avança para o proximo nó caso não ache
    }
    return NULL; //se chega no final sem ter encontrado
}

int consome_ingrediente(lista_simples *estoque,int id, int quantidade){
    //retorna 1 se conseguir consumir
    if (estoque == NULL || quantidade <= 0)
        return 0; //deu pau na hora de procurar
    
    ingrediente *atual = estoque->inicio; 

    while(atual != NULL){ //até chegar no ultimo elemento da estoque
        if(atual->id == id){
            if(atual->quantidade >= quantidade){ //eu realmente odeio que não da pra colocar =>
                atual->quantidade =-quantidade;
                return 1;
            }  
            else{
                printf("Falta ingredientes");
                return 0; //conseguiu achar o ingrediente mas não tinha quantidade o bastante
            }
        }
        atual = atual->prox;
    }
    return 0; //não encontrou o id
}

int remove_da_lista(lista_simples *estoque,int id){
    ingrediente *atual = estoque->inicio;
    ingrediente *anterior = NULL;

    while(atual != NULL && atual->id != id){ //avança na estoque enquanto não achar
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0; //passou por toda a estoque e não encontrou

    //graças a adição do *anterior é preciso separar em 2 casos:
    //1-Elemento no incio
    if (anterior == NULL)
        estoque->inicio = atual->prox;
    //2-Elemento em qualquer outra posição
    else
        anterior->prox = atual->prox;

    free(atual);
    estoque->tamanho--;

    return 1;
}

int checa_vazia(lista_simples *estoque){
    if(estoque->inicio == NULL)
        return 1; //é vazia
    return 0; //não é vazia
}

void imprime_lista(lista_simples *estoque){
    ingrediente *atual = estoque->inicio;
    printf("Os ingredientes presentes na estoque são:\n");
    while(atual != NULL){
        printf("ID: %d | Nome: %s | Quantidade: %d\n",atual->id, atual->nome, atual->quantidade);
        atual = atual->prox;
    }
}

//depos implementar a função eh_vazia em todas as funções que precisam dela
