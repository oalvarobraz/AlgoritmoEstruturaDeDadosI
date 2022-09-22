#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main()
{

    int i;
    TLista L1;
    //TProduto x;
    FLVazia(&L1);

    MENU(&L1);

    /*
    for(i=0; i<2; i++)
    {
        LerProduto(&x);
        Inserir(x, &L1);

    }

    Imprimir(L1);

    printf("\n Informe o codigo que voce deseja saber se esta na lista: ");
    scanf("%d", &x.codigo);

    if(Pesquisar(L1,x) != NULL)
        printf("\n-> O produto esta na lista\n");
    else
        printf("\n-> O produto nao esta na lista\n");


    printf("\n Informe o codigo do produto que voce deseja retirar: ");
    scanf("%d", &x.codigo);


    if(Pesquisar2(L1,x) == 1)
        printf("\n-> O produto esta na lista\n");
    else
        printf("\n-> O produto nao esta na lista\n");

    Excluir(&L1, &x);


    if(x.codigo != -1)
        printf("\n Produto foi retirado na lista\n");
    else
        printf("\n Produto nao esta na lista\n");

    Imprimir(L1);*/

    return 0;
}
