#include <stdio.h>
#include "lista_dupla.h"

void imprime_menu(jogador *j, int turno, int pontuacao, int vidas){

    printf("\nPontos: %d\n"
           "Vidas restantes: %d\n",pontuacao, vidas);


    printf("Turno atual: %d\n", turno);
    printf("Estação atual: %s\n", j->estacao_atual->nome );
    printf("______________________________\n");

    printf("\n [1] Consultar pedidos\n"
               " [2] Consultar estoque\n"
               " [3] Ir para proxima estacao\n"
               " [4] Ir para estacao anterior\n"
               " [5] Pegar Ingredientes\n"
               " [6] Cortar\n"
               " [7] Cozinhar\n"
               " [8] Montar Prato\n"
               " [9] Entregar Prato\n"
               " [10] Aguradar voluntariamente\n"
               " [0] Sair do jogo\n\n");
    printf("Escolha uma opcao: \n");

    printf("______________________________\n");

    }
