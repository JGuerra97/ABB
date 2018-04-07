//main.c
#include "TAB.h"

void impressao(Tree* root){
    printTreePre(root);
    printf("\n");
    printTreeSim(root);
    printf("\n");
    printTreePos(root);
    printf("\n");
    printf("Altura = %d\n", altura(root));
}

int main(){
    Tree* raiz = init_ABB();
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 0);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 4);
    impressao(raiz);
    raiz = retira(raiz, 3);
    impressao(raiz);
    Tree* t = busca(raiz, 4);
    printf("%d\n", t->info);
    return 0;
}
