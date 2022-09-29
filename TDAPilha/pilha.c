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
    while(!Vazia(*P1)){
        Desempilhar(&P1,&x);
        Empilhar(x,Pilha);
    }
}
