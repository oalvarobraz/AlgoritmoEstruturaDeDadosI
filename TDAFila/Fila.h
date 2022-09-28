#ifndef HEADER_FILA
#define HEADER_FILA

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[100];
    int codigo;
    int quantidade;
    float preco;
} TProduto;

typedef struct celula
{

    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct
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

void ImprimirProduto(TProduto *x);

void Imprimir(TLista Lista);

void Imprimir2(TLista Lista);

#endif // HEADER_FILA
