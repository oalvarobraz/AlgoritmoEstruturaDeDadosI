#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

void FPVazia(TPilha *Pilha){
    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->fundo->prox = NULL;
    Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha){
    return(Pilha.fundo == Pilha.topo);
}

int GetTamanho(TPilha Pilha){
    return Pilha.tamanho;
}

void Empilhar(TProduto x, TPilha *Pilha){
    TCelula *Aux;
    Aux = (TCelula*)malloc(sizeof(TCelula));
    Aux->prox = Pilha->topo;
    Pilha->topo->item = x;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *item){
    if(Vazia(*Pilha)){
        printf("\n|| ERRO || Pilha Vazia!");
        item->codigo = -1;
        return;
    }else{
        TCelula *Aux;
        Aux = Pilha->topo;
        Pilha->topo = Aux->prox;
        *item = Aux->prox->item;
        free(Aux);
        Pilha->tamanho--;
    }
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

void ImprimirProduto(TProduto x)
{
    printf("\n|| Codigo: %d\n", x.codigo);
    printf("|| Nome: %s", x.nome);
    printf("|| Quantidade: %d\n", x.quantidade);
    printf("|| Preco: %.2f\n\n", x.preco);
}

void Liberar(TPilha *Pilha){
    TProduto x;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha,&x);
    }
    free(Pilha->fundo);
}

void Imprimir(TPilha *Pilha){
    TPilha P1;
    FPVazia(&P1);
    TProduto x;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha,&x);
        ImprimirProduto(x);
        Empilhar(x,&P1);
    }
    while(!Vazia(P1)){
        Desempilhar(&P1,&x);
        Empilhar(x,Pilha);
    }
    free(P1.topo);
}

TProduto Pesquisar(TProduto Item, TPilha *Pilha){
    TPilha P1;
    FPVazia(&P1);
    TProduto y,x;
    x.codigo=-1;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha,&y);
        if(y.codigo == Item.codigo)
            x.codigo = Item.codigo;
        Empilhar(y,&P1);
    }
    while(!Vazia(P1)){
        Desempilhar(&P1,&y);
        Empilhar(y,Pilha);
    }
    free(P1.topo);
    return x;
}

void OrganizarPilha(TPilha *Pilha){
    if(!Vazia(*Pilha)){
        TProduto x,y;
        TPilha P1;
        FPVazia(&P1);

        while(!Vazia(*Pilha)){
            Desempilhar(Pilha,&y);
            while(!Vazia(P1) && P1.topo->prox->item.codigo > y.codigo){
                Desempilhar(&P1,&x);
                Empilhar(x,Pilha);
            }
            Empilhar(y,&P1);
        }
        while(!Vazia(P1)){
            Desempilhar(&P1,&y);
            Empilhar(y,Pilha);
        }
        free(P1.topo);
    }
}

void InverterPilha(TPilha *Pilha){
    if(!Vazia(*Pilha)){
        TProduto x,y;
        TPilha P1;
        FPVazia(&P1);
        int j = 1;
        int i=0;
        int n = GetTamanho(*Pilha);
        while(j<=(n-1)){
            i=0;
            Desempilhar(Pilha,&y);
            while(i<(n-j)){
                Desempilhar(Pilha,&x);
                Empilhar(x,&P1);
                i++;
            }
            Empilhar(y,Pilha);
            while(!Vazia(P1)){
                Desempilhar(&P1,&x);
                Empilhar(x,Pilha);
            }
            j++;
        }
        free(P1.topo);
    }
}
