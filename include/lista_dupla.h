#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

// Representa cada estação
typedef struct lista_dupla_no{
    int id;
    char nome[50];
    struct lista_dupla_no *prox;
    struct lista_dupla_no *ant;

}lista_dupla_no;

// Representa a lista de estações
typedef struct {
    lista_dupla_no *inicio;
    lista_dupla_no *fim;
    int tamanho;

}lista_dupla;

// Funções para a lista dupla
void cria_lista_dupla(lista_dupla *lista);
void insere_inicio(lista_dupla *lista, int id, char nome[50]);
void insere_fim(lista_dupla *lista, int id, char nome[50]);
void insere_meio(lista_dupla *lista, int id, char nome[50]);
void remove_estacao(lista_dupla *lista, int id);
lista_dupla_no* localiza_estacao(lista_dupla *lista, int id);
void movimento(lista_dupla *lista, int decisao);

#endif