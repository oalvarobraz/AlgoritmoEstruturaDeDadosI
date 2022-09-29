#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


#include <stdlib.h>
#include <stdio.h>


typedef struct item
{
    int codigo;
    char nome[100];
    int quantidade;
    float preco;
} TProduto;

typedef struct celula
{

    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct fila
{

    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int Vazia(TFila Fila);

int GetTamanho(TFila Fila);

void INQUEUE(TFila *Fila, TProduto x);

void DEQUEUE(TFila *Fila, TProduto *x);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void Imprimir(TFila *Fila);

void Imprimir2(TFila *Fila);

TProduto Pesquisar(TFila *Fila, TProduto x);

TProduto Pesquisar2(TFila *Fila, TProduto x);

void Liberar(TFila *Fila);

#endif // FILA_H_INCLUDED
