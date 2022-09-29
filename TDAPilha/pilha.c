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



TProduto Pesquisar(TProduto Item, TPilha *Pilha){
    TPilha P1;
    FPVazia(&P1);
    TProduto y,x;
    while(!Vazia(*Pilha)){
        Desempilhar(Pilha,&y);
        if(y.codigo == Item.codigo)
            x.codigo = Item.codigo;
        Empilhar(y,&P1);
    }
    while(!Vazia(*P1)){
        Desempilhar(&P1,&y);
        Empilhar(y,Pilha);
    }
    return x;
}
