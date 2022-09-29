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
    return (Fila.frente == Fila.tras);
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

void Desenfileirar (TFila *Fila, TProduto *x)
{
    if(!Vazia(*Fila)){
        TCelula *Aux;
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *x = Aux->item;
        free(Aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    } else
        x->codigo = -1;
}

void LerProduto(TProduto *x)
{
    printf("|| Informe um codigo: ");
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("|| Informe o nome: ");
    fflush(stdin);
    fgets(x->nome,100,stdin);

    printf("|| Informe a quantidade: ");
    fflush(stdin);
    scanf("%d", &x->quantidade);

    printf("|| Informe o preco: ");
    fflush(stdin);
    scanf("%d", &x->preco);
}

void ImprimirProduto(TProduto x)
{
    printf("\n|| Codigo: %d\n", x.codigo);
    printf("|| Nome: %s", x.nome);
    printf("|| Quantidade: %d\n", x.quantidade);
    printf("|| Preco: %d\n\n", x.preco);
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

void Imprimir (TFila *Fila)
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

TProduto Pesquisar (TFila *Fila1, TProduto x) {
    int n = Tamanho(*Fila1);
    TProduto y, aux;
    while (n != 0) {
        Desenfileirar(Fila1, &x);
        if(y.codigo == x.codigo)
            aux.codigo = x.codigo;
        Enfileirar (y, Fila1);
        n--;
    }
    return aux;
}


TProduto Pesquisar2(TFila *Fila, TProduto x){
    TProduto y;
    int n = GetTamanho(*Fila);
    while (n!=0){
        TCelula *Aux;
        Aux = Fila->frente->prox;
        Desenfileirar(Fila, &y);
        if(Aux->item.codigo == x.codigo){
            return Aux->item;
        }
        Enfileirar(y,Fila);
        n--;
    }
}

void Liberar (TFila *Fila)
{
    TProduto item;
    while (!Vazia(*Fila))
    {
        Desenfileirar(Fila, &item);
    }
    free(Fila->frente);
}
