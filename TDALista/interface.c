#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TLista *lista1){
    TProduto produto;
    int opcao=0;
    int i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                printf("\n<<<<<<<<<LENDO O PRODUTO>>>>>>>>>>\n");
                LerProduto(&produto);
                Inserir(produto, lista1);
                /**
                    Código para opção de menu Inserir
                */
                break;
            case 2:
                printf("\n\t-> Informe o codigo que voce deseja pesquisar: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                if(Pesquisar(*lista1, produto) != NULL)
                    printf("\n-> O produto esta na lista\n");
                else
                    printf("\n-> O produto nao esta na lista\n");



                //Ler o codigo, testar o que for pesquisar
                /**
                    Código para opção de menu Pesquisar
                */
                break;
            case 3:

                printf("\n-> Informe o codigo que voce deseja exluir: ");
                fflush(stdin);
                scanf("%d", &produto.codigo);

                Excluir(lista1, &produto);
                if(produto.codigo != -1)
                    printf("\n Produto excluido com sucesso! \n");
                else
                    printf("\n Produto nao esta na lista! \n");

                /**
                    Código para opção de menu Excluir
                */
                break;
            case 4:

                Imprimir(*lista1);

                /**
                    Código para opção de menu Imprimir
                */
                break;
            case 5:
                Liberar(lista1);
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!!\n <<<<<<");
                system("PAUSE");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!!\n <<<<<<");
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}
