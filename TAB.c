//TAB.c
#include "TAB.h"

Tree *createTree(){
    return NULL;
}

int treeIsEmpty(Tree *root){
    return (root == NULL);
}

//Pré-Ordem
void printTree1(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printf("%d ",root->info);
        printTree1(root->esq);
        printTree1(root->dir);
    }
    printf(">\n");
}

//Simetria
void printTree2(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTree1(root->esq);
        printf("%d ",root->info);
        printTree1(root->dir);
    }
    printf(">\n");
}

//Pós-Ordem
void printTree3(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTree1(root->esq);
        printTree1(root->dir);
        printf("%d ",root->info);
    }
    printf(">\n");
}

int maior(int x, int y){
    if (x>y) return x;
    return y;
}

int altura(Tree *a){
    if (!a) return -1;
    return 1 + maior(altura(a->esq), altura(a->dir));
}
