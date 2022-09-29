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

void Enfileirar(TProduto x,TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *x);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void Imprimir1(TFila *Fila);

void Imprimir(TFila *Fila);

TProduto Pesquisar(TFila *Fila, TProduto x);

TProduto Pesquisar2(TFila *Fila, TProduto x);

void Liberar(TFila *Fila);

#endif // FILA_H_INCLUDED
