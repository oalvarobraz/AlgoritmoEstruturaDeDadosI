#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void FLVazia(TLista *Lista)
{

    Lista ->primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista ->ultimo = Lista ->primeiro;
    Lista ->primeiro ->prox = NULL;
    Lista ->tamanho = 0;
}

int Vazia(TLista Lista)
{

    return (Lista.primeiro == Lista.ultimo);
}

int GetTamanho(TLista Lista)
{

    return Lista.tamanho;
}

void Inserir(TProduto x, TLista *Lista)
{

    Lista ->ultimo->prox = (TCelula *) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}


//Função Auxiliar, visto que o utilzia o produto
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

void Imprimir(TLista Lista)
{

    TCelula* Aux;
    Aux = Lista.primeiro->prox;
    printf("\n\t\t\t|| Imprimindo Lista ||\n");
    while(Aux != NULL)
    {
        ImprimirProduto(&Aux->item);
        Aux = Aux->prox;
    }

}

int Pesquisar2(TLista Lista, TProduto x)
{

    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == x.codigo)
            return 1;
        Aux = Aux->prox;
    }
    return 0;
}

TCelula* Pesquisar(TLista Lista, TProduto x)
{

    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == x.codigo)
            return Aux; //retorna a celula antes do valor pesquisado
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *x)
{
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *x);
    if(Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *x = Aux2->item;
        if(Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
    else
        x->codigo = -1;
}

void Liberar(TLista *Lista)
{
    /*if(Vazia(*Lista) != 1)
    {
        TCelula *Aux;
        Aux = Lista->primeiro->prox;
        while(Aux != NULL)
        {
            Excluir(Lista, &Aux->item);
            Aux = Aux->primeiro->prox;
        }
    }
    free(Lista->primeiro);*/
    
    
    while(!Vazia(*Lista)){
        Excluir(Lista, &Lista->primeiro->prox->item);
    }
    free(Lista->primeiro);
    

    //enquanto a lista nao estiver vazia exclua, e no final devemos remover a cabeça utilização o lista->primeiro;
}
