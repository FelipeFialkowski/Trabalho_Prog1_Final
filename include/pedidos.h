#ifndef PEDIDOS_H
#define PEDIDOS_H

typedef struct fila_no{

    int id;
    char prato[50];
    int turno;
    int prazo;
    int pontuacao;
    struct fila_no *prox;

} fila_no;

typedef struct fila{

    fila_no *primeiro;
    fila_no *ultimo;
    int tamanho;

} fila;

void inicializa_fila(fila *pedidos);
void insere(fila *pedidos, int id, char prato[50], int turno, int prazo, int pontuacao);
void consultar_pedidos(fila *pedidos);
fila_no* consultar_primeiro(fila *pedidos);
fila_no* remover(fila *pedidos);
void liberar_nos(fila *pedidos);
void gerar_pedido(fila *pedidos, int turno, int *proximo_id);

#endif