#include "receitas.h"

receita receitas[QTD_RECEITAS];

void montar_receitas(){
    receitas[0].id = 11;
    strcpy(receitas[0].nome, "Hamburguer");
    receitas[0].qtd_ingredientes = 3;

    receitas[0].ingredientes[0].id_ingrediente = 1;  // Pão
    receitas[0].ingredientes[0].quantidade = 1;

    receitas[0].ingredientes[1].id_ingrediente = 2;  // Carne
    receitas[0].ingredientes[1].quantidade = 1;

    receitas[0].ingredientes[2].id_ingrediente = 3;  // Queijo
    receitas[0].ingredientes[2].quantidade = 1;
    

    receitas[1].id = 12;
    strcpy(receitas[1].nome, "Salada");
    receitas[1].qtd_ingredientes = 2;

    receitas[1].ingredientes[0].id_ingrediente = 4;  // Alface
    receitas[1].ingredientes[0].quantidade = 1;

    receitas[1].ingredientes[1].id_ingrediente = 5;  // Tomate
    receitas[1].ingredientes[1].quantidade = 1;

    receitas[2].id = 13;
    strcpy(receitas[2].nome, "Sopa");
    receitas[2].qtd_ingredientes = 2;

    receitas[2].ingredientes[0].id_ingrediente = 6;  // Água
    receitas[2].ingredientes[0].quantidade = 1;

    receitas[2].ingredientes[1].id_ingrediente = 5;  // Tomate
    receitas[2].ingredientes[1].quantidade = 1;
}

receita* busca_receita(int id){
    for(int i = 0; i < 3; i++){
        if(receitas[i].id == id)
            return &receitas[i];
    }
    return NULL;
}
