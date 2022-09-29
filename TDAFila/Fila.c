
#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void FFVazia(TFila *Fila){
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->tras->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila){
    return (Fila.frente == Fila.tras);
}

int GetTamanho(TFila Fila){
    return Fila.tamanho;
}

void INQUEUE(TFila *Fila, TProduto x){
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void DEQUEUE(TFila *Fila, TProduto *x){
    if(!Vazia(*Fila)){
        TCelula *Aux;
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *x = Aux->item;
        free(Aux);
        if(Fila->frente->prox = NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

void LerProduto(TProduto *x)
{

    printf("\n|| Informe um codigo:");
    fflush(stdin);
    scanf("%d", &x->codigo);

}

//Função Auxiliar, visto que o utilzia o produto
void ImprimirProduto(TProduto x)
{
    printf("\n|| Codigo: %d\n", x.codigo);
}

void Imprimir(TFila *F1){
    int n = GetTamanho(*F1);
    TProduto x;
    while(n!=0){
        DEQUEUE(F1,&x);
        ImprimirProduto(x);
        INQUEUE(F1,x);
        n--;
    }
}

void Imprimir2(TFila *F1){
    TProduto x;
    TFila F2;
    FFVazia(&F2);
    while(!Vazia(*F1)){
        DEQUEUE(F1,&x);
        INQUEUE(&F2,x);
    }
    while(!Vazia(F2)){
        DEQUEUE(&F2,&x);
        ImprimirProduto(x);
        INQUEUE(F1,x);
    }
    free(F2.frente);
}

TProduto Pesquisar(TFila *Fila, TProduto Item){
    int n = GetTamanho(*Fila);
    TProduto x, aux;
    while (n != 0){
        DEQUEUE(Fila,&x);
        if(x.codigo == Item.codigo)
            aux.codigo = Item.codigo;
        INQUEUE(Fila,x);
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
        DEQUEUE(Fila,&y);
        if(Aux->item.codigo == x.codigo){
            return Aux->item;
        }
        INQUEUE(Fila,y);
        n--;
    }
}


void Liberar(TFila *Fila){
    TProduto item;
    while(!Vazia(*Fila)){
        DEQUEUE(Fila,&item);
    }
    free(Fila->frente);
}
