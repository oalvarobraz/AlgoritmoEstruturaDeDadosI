#include <stdlib.h>
#include <stdio.h>

#include "fila.h"


void FFVazia (TFila *Fila)
{
    Fila->frente = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.tras == Fila.frente);
}

int Tamanho(TFila Fila)
{
    return Fila.tamanho;
}

void Enfileirar (TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula*)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar (TFila *Fila, TProduto *Item)
{
    if(!Vazia(*Fila))
    {
        TCelula *Aux;
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if (Fila->frente->prox == NULL)
        {
            Fila->tras = Fila->frente; // Tratamento de excessao
        }
        Fila->tamanho--;
    } else {
        Item->codigo = -1;
    }
}

void LerProduto(TProduto *x)
{
    printf("->Digite codigo do produto: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("->Digite o nome do produto: ");
    //__fpurge(stdin);
    fflush(stdin);
    fgets(x->nome,100,stdin);

    printf("->Digite a quantidade: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->quantidade);

    printf("->Digite o preco: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->preco);
    printf("\n");
}

void ImprimirProduto(TProduto x)
{
    printf("\n|| Codigo: %d\n", x.codigo);
    printf("|| Nome: %s", x.nome);
    printf("|| Quantidade: %d\n", x.quantidade);
    printf("|| Preco: %d\n\n", x.preco);
}

void Liberar (TFila *Fila)
{
    TProduto x;
    while (!Vazia(*Fila))
    {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

void Imprimir1 (TFila *Fila1)
{
    TProduto x;
    TFila Fila2;
    FFVazia(&Fila2);
    while (!Vazia(*Fila1))
    {
        Desenfileirar(Fila1, &x);
        Enfileirar(x, &Fila2);
    }
    while (!Vazia(Fila2))
    {
        Desenfileirar(&Fila2, &x);
        ImprimirProduto(x);
        Enfileirar(x, Fila1);
    }
    Liberar(&Fila2);
}

void Imprimir2 (TFila *Fila)
{
    int n = Tamanho(*Fila);
    TProduto x;
    while (n != 0)
    {
        Desenfileirar (Fila, &x);
        ImprimirProduto(x);
        Enfileirar (x, Fila);
        n--;
    }
}

TProduto Pesquisar (TFila *Fila1, TProduto Item) {
    TProduto x, Aux;
    int n = Tamanho(*Fila1);
    while (n != 0) {
        Desenfileirar(Fila1, &x);
        if(x.codigo == Item.codigo)
            Aux.codigo = Item.codigo;
        Enfileirar (x, Fila1);
        n--;
    }
    return Aux;
}
