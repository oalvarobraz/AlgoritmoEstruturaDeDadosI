#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU( )
{
    //system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t(1) ENFILEIRAR");
    printf("  \n\t(2) PESQUISAR");
    printf("  \n\t(3) DESENFILEIRAR");
    printf("  \n\t(4) IMPRIMIR");
    printf("  \n\t(5) SAIR");
}

void MENU(TFila *fila){
    TProduto produto;
    int opcao=0;
    do
    {
        MSG_MENU();
        printf("\n\n|| Digite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("\n\t___________LENDO O PRODUTO___________\n");
                LerProduto(&produto);
                Enfileirar(produto,fila);

                break;
            case 2:
                printf("\n|| Informe o codigo que voce deseja pesquisar: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                TProduto y = Pesquisar(fila,produto);
                if(y.codigo == produto.codigo)
                    printf("\n| O produto esta na fila!");
                else
                    printf("\n| O produto nao esta na fila!");

                break;
            case 3:
                Desenfileirar(fila,&produto);

                ImprimirProduto(produto);

                break;
            case 4:
                printf("\n\t\t|| IMPRIMINDO FILA ||\n");
                Imprimir(fila);

                break;
            case 5:
                Liberar(fila);
                //system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!!\n <<<<<<");
                system("PAUSE");
                break;
            default:
                //system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!!\n <<<<<<");
                system("PAUSE");
        } // fim do bloco switch
    } while(opcao != 5);
}
