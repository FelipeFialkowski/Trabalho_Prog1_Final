/*
Nome: lista_simples.h
Descrição: Este arquivo define a estrutura para a lista simples e o protiotipo das funções da lista simples.
Autor: Felipe
Ultima modificação: 10-11-2026
*/

#ifndef MEU_CABECALHO_H
#define MEU_CABECALHO_H

//Estrutura do nó da lista encadeada

typedef struct node_lista{
    struct node_lista* prox;
    int id_ingrediente;
    int quantidade;
    char nome_ingrediente[50];

}node_lista;

//Prototipos das funcoes

void cria_lista(node_lista** cabeca);
void InsereInicio(node_lista** cabeca, int id_ingrediente, int quantidade, char* nome_ingrediente);

#endif