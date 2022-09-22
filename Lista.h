#ifndef HEADER_LISTA
#define HEADER_LISTA

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

    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

int GetTamanho(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto *x);

void Imprimir(TLista Lista);

int Pesquisar2(TLista Lista, TProduto x);

TCelula* Pesquisar(TLista Lista, TProduto x);

void Excluir(TLista *Lista, TProduto *x);

#endif
