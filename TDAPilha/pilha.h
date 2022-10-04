#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

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

typedef struct pilha
{
    TCelula* fundo;
    TCelula* topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);

int Vazia(TPilha Pilha);

int GetTamanho(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *item);

void LerProduto(TProduto *x);

void ImprimirProduto(TProduto x);

void Liberar(TPilha *Pilha);

void Imprimir(TPilha *Pilha);

TProduto Pesquisar(TProduto Item, TPilha *Pilha);


#endif // PILHA_H_INCLUDED
