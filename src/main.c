#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
#include "menu.h"
#include "time.h"

int main(){
    
    srand(time(NULL));

    lista_dupla estacoes;
    jogador j;
    char entrada[50];
    cria_lista_dupla(&estacoes, &j);
    int turno = 0;

    int opcao = -1;
    while (opcao != 0){

        imprime_menu(&j, turno);
       
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        char *fim;
        long numero = strtol(entrada, &fim, 10);

        // Verifica se foi digitado um numero valido
        if (fim == entrada || (*fim != '\n' && *fim != '\0')) {
            printf("Digite apenas números\n");
            continue;
        }

        opcao = (int) numero;

        switch(opcao){

            case 0:
                printf("Encerrando jogo....");
                break;

            case 1:

                break;

            case 2:

                break;

            // Avança uma estação
            case 3:
                if (avancar(&j)){
                    turno++;
                    break;
                }
                printf("Não é possível avançar de estação\n");
                break;

            // Volta uma estação
            case 4:
                if(voltar(&j)){
                    turno++;
                    break;
                }
                printf("Não é possível voltar de estação\n");
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