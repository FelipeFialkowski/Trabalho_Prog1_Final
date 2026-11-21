#include <stdio.h>
#include "lista_dupla.h"

int main(){

    lista_dupla estacoes;
    cria_lista_dupla(&estacoes);

    int opcao = -1;

    while (opcao != 0){

        printf("\n [1] Consultar pedidos\n"
               " [2] Consultar estoque\n"
               " [3] Ir para proxima estacao\n"
               " [4] Ir para estacao anterior\n"
               " [5] Entregar prato\n"
               " [6] A definir\n"
               " [0] Sair do jogo\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 0:
                printf("Encerrando jogo....");
                break;

            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;

            case 6:

                break;

            default:
                printf("Por favor, digite um numero de 0 a 6\n");
                break;
        }
    }
}