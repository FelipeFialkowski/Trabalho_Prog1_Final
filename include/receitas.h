#ifndef RECEITAS_H
#define RECEITAS_H

typedef struct receita{

    int id;
    char nome[50];
    char ingredientes[3][50];
    int operacoes;
    int pre_requisitos;


} receita;

void montar_receitas();

#endif