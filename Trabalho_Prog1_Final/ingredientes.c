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

int insere_ingrediente(lista_simples *lista,int id,const char *nome,int quantidade){
    ingredientes *novo = malloc(sizeof(ingredientes)); //cria um novo nó

    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0';  // garante que termina com \0
    novo->quantidade = quantidade;
    novo->prox = NULL;

    /*por ser mais facil de implementar, os elementos vão ser inseridos no
    inicio da lista*/

    novo->prox = lista->inicio; //a struct novo aponta para onde era o inicio original
    lista->inicio = novo; //o struct novo se torna o novo inciio

    lista->tamanho++;

    return 1;
}

ingredientes* busca_ingrediente(lista_simples *lista, int id){
    ingredientes *atual = lista->inicio;
    while(atual != NULL){ //verifica se ja não é o ultimo elemento da lista
        if (atual->id == id)
            return atual;
        atual = atual->prox; //avança para o proximo nó caso não ache
    }
    return NULL; //se chega no final sem ter encontrado
}

int consome_ingrediente(lista_simples *lista,int id, int quantidade){
    //retorna 1 se conseguir consumir
    if (lista == NULL || quantidade <= 0)
        return 0; //deu pau na hora de procurar
    
    ingredientes *atual = lista->inicio; 

    while(atual != NULL){ //até chegar no ultimo elemento da lista
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

int remove_da_lista(lista_simples *lista,int id){
    ingredientes *atual = lista->inicio;
    ingredientes *anterior = NULL;

    while(atual != NULL && atual->id != id){ //avança na lista enquanto não achar
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0; //passou por toda a lista e não encontrou

    //graças a adição do *anterior é preciso separar em 2 casos:
    //1-Elemento no incio
    if (anterior == NULL)
        lista->inicio = atual->prox;
    //2-Elemento em qualquer outra posição
    else
        anterior->prox = atual->prox;

    free(atual);
    lista->tamanho--;

    return 1;
}

int checa_vazia(lista_simples *lista){
    if(lista->inicio == NULL)
        return 1; //é vazia
    return 0; //não é vazia
}

void imprime_lista(lista_simples *lista){
    ingredientes *atual = lista->inicio;
    printf("Os ingredientes presentes na lista são:\n");
    while(atual != NULL){
        printf("ID: %d | Nome: %s | Quantidade: %d\n",atual->id, atual->nome, atual->quantidade);
        atual = atual->prox;
    }
}

//depos implementar a função eh_vazia em todas as funções que precisam dela