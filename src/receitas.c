#include "receitas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

receita receitas[3];

void montar_receitas(){
    receitas[0].id = 23;
    strcpy(receitas[0].nome, "Hamburguer");
    strcpy(receitas[0].ingredientes[0], "Pao");
    strcpy(receitas[0].ingredientes[1], "Carne");
    strcpy(receitas[0].ingredientes[2], "Queijo");

    receitas[1].id = 13;
    strcpy(receitas[1].nome, "Salada");
    strcpy(receitas[1].ingredientes[0], "Alface");
    strcpy(receitas[1].ingredientes[1], "Tomate");

    receitas[2].id = 21;
    strcpy(receitas[2].nome, "Sopa");
    strcpy(receitas[2].ingredientes[0], "Agua");
    strcpy(receitas[2].ingredientes[1], "Tomate");
}
