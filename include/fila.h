#ifndef FILA_H
#define FILA_H

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

} fila;


void insere(fila *pedidos, int id, char prato[50], int turno, int prazo, int pontuacao);
void consultar(fila *pedidos);
fila_no* remover(fila *pedidos);
void liberar(fila *pedidos);


#endif