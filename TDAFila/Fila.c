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

int GetTamanho(TFila Fila)
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
    }
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
    scanf("%f", &x->preco);
}

void ImprimirProduto(TProduto x)
{
    printf("\n|| Codigo: %d\n", x.codigo);
    printf("|| Nome: %s", x.nome);
    printf("|| Quantidade: %d\n", x.quantidade);
    printf("|| Preco: %.2f\n\n", x.preco);
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
    int n = GetTamanho(*Fila);
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
    Aux.codigo = -1;
    int n = GetTamanho(*Fila1);
    while (n != 0) {
        Desenfileirar(Fila1, &x);
        if(x.codigo == Item.codigo)
            Aux = Item;
            //Aux.codigo = Item.codigo;
        //else
           //Aux.codigo = -1;
        Enfileirar (x, Fila1);
        n--;
    }
    return Aux;
}


TProduto Pesquisar3(TFila *F1, TProduto x){
    TFila F2;
    FFVazia(&F2);
    TProduto y, z;
    int flag = 0;
    while(!Vazia(*F1)){
        Desenfileirar(F1,&y);
        Enfileirar(y,&F2);
        if(y.codigo == x.codigo){
            flag = 1;
            z=y;
        }
    }
    //Devolvendo F2 para F1
    while(!Vazia(F2)){
        Desenfileirar(&F2,&y);
        Enfileirar(y,F1);
    }
    if(flag == 1)
        return z;
    else{
        z.codigo = -1;
        return z;
    }
    
}


TProduto Pesquisar2(TFila *Fila, TProduto x){
    int n = GetTamanho(*Fila);
    TProduto y;
    TCelula *Aux;
    while (n!=0){
        Aux = Fila->frente->prox;
        Desenfileirar(Fila, &y);
        if(Aux->item.codigo == x.codigo){
            y.codigo = x.codigo;
        }
        Enfileirar(y,Fila);
        n--;
    }
    return y;
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
