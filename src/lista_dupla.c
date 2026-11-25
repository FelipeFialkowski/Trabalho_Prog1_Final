#include "lista_dupla.h"


void cria_lista_dupla(lista_dupla *lista, jogador *j){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    insere_inicio(lista, 1, "Estoque");
    insere_fim(lista, 2, "Corte");
    insere_fim(lista, 3, "Fogão");
    insere_fim(lista, 4, "Montagem");
    insere_fim(lista, 5, "Entrega");

    j->estacao_atual = lista->inicio;
}

void insere_inicio(lista_dupla *lista, int id, char nome[50]){

    lista_dupla_no *novo = malloc(sizeof(lista_dupla_no));

    if (novo == NULL){
        return;
    }

    novo->id = id;
    snprintf(novo->nome, sizeof(novo->nome), "%s", nome);
    
    novo->ant = NULL;
    
    if(lista->inicio == NULL){
        novo->prox = NULL;
        lista->fim = novo;
    }
    else{
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
    }

    lista->inicio = novo;
    lista->tamanho++;
}

// *Importante* A maneira que essa função funciona, é colocando a nova estação depois da estação representada pelo id
void insere_meio(lista_dupla *lista, int id, int id_nova, char nome[50]){

    lista_dupla_no *atual = lista->inicio;

    //Procura a estação
    while (atual != NULL && atual->id != id)
        atual = atual->prox;
    
    if(atual->prox == NULL){
        insere_fim(lista, id_nova, nome);
        return; //precisa desse return por que se não ele continua dando insert depois do fim
    }
    lista_dupla_no *novo = malloc(sizeof(lista_dupla_no));

    if (novo == NULL)
        return;

    novo->id = id_nova;
    snprintf(novo->nome, sizeof(novo->nome), "%s", nome);

    novo->ant = atual;
    novo->prox = atual->prox;

    atual->prox->ant = novo;
    atual->prox = novo;
    lista->tamanho++;
}

void insere_fim(lista_dupla *lista, int id, char nome[50]){

    lista_dupla_no *novo = malloc(sizeof(lista_dupla_no));

    if (novo == NULL){
        return;
    }

    novo->id = id;
    snprintf(novo->nome, sizeof(novo->nome), "%s", nome);

    novo->prox = NULL;
    novo->ant = lista->fim;

    if (lista->inicio == NULL){
        lista->inicio = novo;
    }

    else{
        lista->fim->prox = novo;
    }
    
    lista->fim = novo;
    lista->tamanho++;
}

lista_dupla_no* localiza_estacao(lista_dupla *lista, int id){

    lista_dupla_no *atual = lista->inicio;

    while(atual != NULL){
        if (atual->id == id){
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}
void remove_estacao(lista_dupla *lista, int id){

    lista_dupla_no *atual;
    atual = lista->inicio;
    while (atual != NULL && atual->id != id){
        atual = atual->prox;
    }
    if (atual == NULL){
        return;
    }
    if(atual == lista->inicio){
        lista->inicio = atual->prox;
    }
    else{
        atual->ant->prox = atual->prox;
    }

    if(atual->prox == NULL){
        lista->fim = atual->ant;
    }
    else{
        atual->prox->ant = atual->ant;
    }

    free(atual);
    lista->tamanho--;
}


bool avancar(jogador *j){

    if (j->estacao_atual->prox != NULL){
        j->estacao_atual = j->estacao_atual->prox;
        return true;
    }
    return false;
}

bool voltar(jogador *j){

    if (j->estacao_atual->ant != NULL){
        j->estacao_atual = j->estacao_atual->ant;
        return true;
    }
    return false;
}
