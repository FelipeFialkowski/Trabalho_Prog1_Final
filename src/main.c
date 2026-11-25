#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
#include "menu.h"
#include "time.h"
#include "pedidos.h"    

int main(){
    
    srand(time(NULL));

    int proximo_id = 1;
    lista_dupla estacoes;
    fila pedidos;
    jogador j;
    char entrada[50];
    cria_lista_dupla(&estacoes, &j);
    int turno = 0;
    int pontuacao = 0;
    int vidas = 3;

    int opcao = -1;
    while (opcao != 0 && pontuacao < 500 && vidas > 0){

        if(pontuacao < 0){
            pontuacao = 0;
        }

        imprime_menu(&j, turno, pontuacao, vidas);
       
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

            //Consultar pedidos pendentes
            case 1:
                consultar_pedidos(&pedidos);
                break;

            case 2:

                break;

            // Avança uma estação
            case 3:
                if (avancar(&j)){
                    turno++;
                    gerar_pedido(&pedidos, turno, &proximo_id);
                    break;
                }
                printf("Não é possível avançar de estação\n");
                break;

            // Volta uma estação
            case 4:
                if(voltar(&j)){
                    turno++;
                    gerar_pedido(&pedidos, turno, &proximo_id);
                    break;
                }
                printf("Não é possível voltar de estação\n");
                break;

            //Entregar pedido
            case 5:
                fila_no* entregue = consultar_primeiro(&pedidos);
                if(entregue == NULL){
                    printf("Não há nenhum pedido para entregar\n");
                }
                else{
                    if(turno > entregue->prazo){
                        printf("O turno atual ultrapassou o prazo maximo para esse pedido, e ele foi perdido :(\n"
                               "-50 Pontos\n"
                               "1 Vida perdida\n");
                        pontuacao = pontuacao - 50;
                        vidas--;
                    }
                    else{
                        int bonus = (entregue->prazo - turno) * 10;
                        pontuacao = pontuacao + 100 + bonus;
                        printf("O pedido número %d foi entregue | Adicionado %d pontos + %d pontos bonus\n", entregue->id, entregue->pontuacao, bonus);
                    }
                }
                remover(&pedidos);
                free(entregue);
                turno++;
                break;
 
            case 6:
                break;

            //Deixa turno passar
            case 7:
                printf("Passou o turno\n");
                turno++;
                gerar_pedido(&pedidos, turno, &proximo_id);
                break;

            //Caso digite um número errado
            default:
                printf("Por favor, digite um numero de 0 a 7\n");
                break;
        }
    }
    liberar_nos(&pedidos);
    if (pontuacao >= 500) {
        printf("Parabéns você venceu!");
    }
    else if (vidas <= 0){
        printf("Parabéns você perdeu!");
    }
    else{
        printf("Parabéns você desistiu!");
    }
}