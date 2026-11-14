/*
Autor: Felipe e Kojima
Ultima modificação: 12-11-2026
Lista Simples Encadeada
*/

#ifndef INGREDIENTES_H
#define INGREDIENTES_H

//Lembrete:essa struct é de um dos nós
typedef struct ingredientes{
    int id;
    char nome[20];
    int quantidade; //fazer um rand para começar com uma quantidade aleatória de cada item
    struct ingredientes* prox;
}ingredientes;

//Lembrete:essa struct é da lista em si
typedef struct{
    ingredientes *inicio;
    int tamanho;
}lista;

lista* cria_lista(void);
void destroi_lista(lista *lista); //destroi a lista TODA(usar no final do programa)
int insere_ingrediente(lista *lista,int id,const char *nome,int quantidade);
ingredientes* busca_ingrediente(lista *lista, int id);
int consome_ingrediente(lista *lista,int id, int quantidade); //retorna 1 se conseguir consumir
int remove_da_lista(lista *lista,int id);
int checa_vazia(lista *lista);
void imprime_lista(lista *lista);

#endif

//tava pensando, se um ingrediente tiver quantidade = 0 vamos mantes na lista e dizer que precisa
//reestocar.

