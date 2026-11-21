#include <stdio.h>
#include "lista_dupla.h"

void imprime_menu(jogador *j, int turno){

    printf("\nPontos:\n"
           "Vidas restantes:\n"
           "Pedidos pendentes:\n"
           "Estoque:\n"
           "Bancada:\n");

    printf("Turno atual: %d\n", turno);
    printf("Estação atual: %s\n", &j->estacao_atual->nome );
    printf("______________________________\n");

    printf("\n [1] Consultar pedidos\n"
               " [2] Consultar estoque\n"
               " [3] Ir para proxima estacao\n"
               " [4] Ir para estacao anterior\n"
               " [5] Entregar prato\n"
               " [6] A definir\n"
               " [0] Sair do jogo\n\n");
    printf("Escolha uma opcao: ");

    }
