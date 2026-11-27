#ifndef RECEITAS_H
#define RECEITAS_H
#define MAX_INGREDIENTES_RECEITA 3 //receitas só usam até no maximo 3 ingredientes
#define QTD_RECEITAS 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id_ingrediente;
    int quantidade;
}ingrediente_receita;

typedef struct{
    int id; //11,12,13
    char nome[50];
    int qtd_ingredientes;
    ingrediente_receita ingredientes[MAX_INGREDIENTES_RECEITA];
} receita;

//não tinha nenhum lugar melhor pra guardar essa struct que representa o prato atual sendo feito
typedef struct{
    int ativo; //nenhum prato sendo feito ativo = 0
    int id_receita; //11 = hamburger, 12 = salada, 13 = sopa
    int ingrediente_separado; //1 se ja saiu do estoque
    int corte; //1 se ja cortou
    int cozinhar; //1 se ja cozinhou
}preparo;

extern receita receitas[QTD_RECEITAS];

void montar_receitas();
receita* busca_receita( int id);

#endif