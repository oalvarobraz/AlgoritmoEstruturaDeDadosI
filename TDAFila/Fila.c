#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void FFVazia(TFila *Fila){
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->tras->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila){
  return (Fila.primeiro == Fila.ultimo);
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
    *Item = Aux->item;
    free(Aux);
    if(Fila->frente->prox = NULL)
      Fila->tras = Fila->frente;
    Fila->tamanho--;
  }
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
  while(!Vazia(*F2)){
    DEQUEUE(&F2,&X);
    ImprimirProduto(x);
    INQUEUE(F1,x);
  }
  free(F2.frente);
}


void LerProduto(TProduto *x)
{

    printf("\n|| Informe um codigo: ");
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


//Função Auxiliar, visto que o utilzia o produto
void ImprimirProduto(TProduto *x)
{

    printf("\n|| Codigo: %d\n", x->codigo);
    printf("|| Nome: %s", x->nome);
    printf("|| Quantidade: %d\n", x->quantidade);
    printf("|| Preco: %.2f\n", x->preco);
}
