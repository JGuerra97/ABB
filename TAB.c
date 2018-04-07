//TAB.c
#include "TAB.h"

Tree* init_ABB(){
    return NULL;
}

int treeIsEmpty(Tree *root){
    return (root == NULL);
}

//Pré-Ordem
void printTreePre(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printf("%d ",root->info);
        printTreePre(root->esq);
        printTreePre(root->dir);
    }
    printf("> ");
}

//Simetria
void printTreeSim(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreeSim(root->esq);
        printf("%d ",root->info);
        printTreeSim(root->dir);
    }
    printf("> ");
}

//Pós-Ordem
void printTreePos(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreePos(root->esq);
        printTreePos(root->dir);
        printf("%d ",root->info);
    }
    printf("> ");
}

Tree* busca(Tree *root, int x){
    if((x == root->info)||(!root)) return root;
    if(x < root->info) return busca(root->esq, x);
    return busca(root->dir, x);
}

Tree* criaFolha(int x){
    Tree *novo = (Tree*)malloc(sizeof(Tree));
    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Tree* insere(Tree *root, int x){
    if(!root) return criaFolha(x);
    if(x < root->info) root->esq = insere(root->esq, x);
    else if(x > root->info) root->dir = insere(root->dir, x);
    return root;
}

Tree* retira(Tree* root, int x){
    if(!root) return root;
    if(x < root->info) root->esq = retira(root->esq, x);
    else if(x > root->info) root->dir = retira(root->dir, x);
    else{
        if((!root->esq)&&(!root->dir)){
            free(root);
            root = NULL;
        }
        else if((!root->esq)||(!root->dir)){
            Tree* temp = root;
            if(!root->esq) root = root->dir;
            else root = root->esq;
            free(temp);
        }
        else{
            Tree* aux = root->esq;
            while(aux->dir) aux = aux->dir;
            root->info = aux->info;
            aux->info = x;
            root->esq = retira(root->esq, x);
        }
    }
    return root;
}

int maior(int x, int y){
    if (x>y) return x;
    return y;
}

int altura(Tree *a){
    if (!a) return -1;
    return 1 + maior(altura(a->esq), altura(a->dir));
}
