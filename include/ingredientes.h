/*
Autor: Felipe e Kojima
Ultima modificação: 12-11-2026
Lista Simples Encadeada
*/

#ifndef INGREDIENTES_H
#define INGREDIENTES_H

//Lembrete:essa struct é de um dos nós
typedef struct ingrediente{
    int id;
    char nome[20];
    int quantidade; //fazer um rand para começar com uma quantidade aleatória de cada item
    struct ingrediente* prox;
}ingrediente;

//Lembrete:essa struct é da estoque em si
typedef struct lista_simples{
    ingrediente *inicio;
    int tamanho;
}lista_simples;

lista_simples* cria_lista(void);
void destroi_lista(lista_simples *estoque); //destroi a lista TODA(usar no final do programa)
int insere_ingrediente(lista_simples *estoque,int id,const char *nome,int quantidade);
ingrediente* busca_ingrediente(lista_simples *estoque, int id);
int consome_ingrediente(lista_simples *estoque,int id, int quantidade); //retorna 1 se conseguir consumir
int remove_da_lista(lista_simples *estoque,int id);
int checa_vazia(lista_simples *estoque);
void imprime_lista(lista_simples *estoque);

#endif

//tava pensando, se um ingrediente tiver quantidade = 0 vamos mantes na lista e dizer que precisa
//reestocar.

