#include <stdio.h>
#include <stdlib.h>
#include "ingredientes.h"
#include "lista_dupla.h"
#include "menu.h"
#include "time.h"
#include "pedidos.h"    

int main(){
    
    srand(time(NULL));

    lista_simples *estoque = cria_lista();
    inicializa_estoque(estoque);

    fila pedidos;
    inicializa_fila(&pedidos);

    lista_dupla estacoes;
    jogador j;
    cria_lista_dupla(&estacoes, &j);
    
    char entrada[50];
    int turno = 0;
    int pontuacao = 0;
    int vidas = 3;
    int proximo_id = 1;

    int opcao = -1;
    while (opcao != 0 && pontuacao < 500 && vidas > 0){

        if(pontuacao < 0)
            pontuacao = 0;

        imprime_menu(&j, turno, pontuacao, vidas);
       
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) 
            break;

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
            //consultar estoque
            case 2:
                if(j.estacao_atual->id != 1)
                    printf("\nNão é possivel ver o estoque...fora do estoque\n");
                imprime_lista(estoque);
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
                    break;
                }
                if(j.estacao_atual->id != 5){
                    printf("Estação errada");
                    break;
                }
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
    if (pontuacao >= 500) {
        printf("Parabéns você venceu!");
    }
    else if (vidas <= 0){
        printf("Parabéns você perdeu!");
    }
    else{
        printf("Parabéns você desistiu!");
    }
    liberar_nos(&pedidos);
    for (int i = 1; i < 6; i++)
        remove_estacao(&estacoes, i);
    destroi_lista(estoque);
}