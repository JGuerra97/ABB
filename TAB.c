//TAB.c
#include "TAB.h"

Tree* init_ABB(){
    return NULL;
}

int treeIsEmpty(Tree *root){
    return (root == NULL); //Verifica se a árvore está vazia (Retorna 1 se estiver vazia e 0 caso contrário)
}

//Pré-Ordem
void printTreePre(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printf("%d ",root->info); //Imprime a raiz
        printTreePre(root->esq); //Visita a sub-árvore da esquerda
        printTreePre(root->dir); //Visita a sub-árvore da direita
    }
    printf("> ");
}

//Simetria
void printTreeSim(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreeSim(root->esq); //Visita a sub-árvore da esquerda
        printf("%d ",root->info); //Imprime a raiz
        printTreeSim(root->dir); //Visita a sub-árvore da direita
    }
    printf("> ");
}

//Pós-Ordem
void printTreePos(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreePos(root->esq); //Visita a sub-árvore da esquerda
        printTreePos(root->dir); //Visita a sub-árvore da direita
        printf("%d ",root->info); //Imprime a raiz
    }
    printf("> ");
}

Tree* busca(Tree *root, int x){ //Função de busca
    if((x == root->info)||(!root)) return root;
    if(x < root->info) return busca(root->esq, x);
    return busca(root->dir, x);
}

Tree* criaFolha(int x){ //Função necessária apenas para a função de inserção (privada)
    Tree *novo = (Tree*)malloc(sizeof(Tree));
    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Tree* insere(Tree *root, int x){ //Função de Inserção
    if(!root) return criaFolha(x); //Cria a folha se a árvore ou sub-árvore está vazia
    if(x < root->info) root->esq = insere(root->esq, x);
    else if(x > root->info) root->dir = insere(root->dir, x);
    return root;
}

Tree* retira(Tree* root, int x){ //Funcão de Remoção
    if(!root) return root; //Árvore vazia, não há o que remover
    if(x < root->info) root->esq = retira(root->esq, x);
    else if(x > root->info) root->dir = retira(root->dir, x);
    else{ //Encontrou o elemento a ser removido
        if((!root->esq)&&(!root->dir)){ //Caso 1: é uma folha
            free(root);
            root = NULL;
        }
        else if((!root->esq)||(!root->dir)){ //Caso 2: tem um filho
            Tree* temp = root;
            if(!root->esq) root = root->dir;
            else root = root->esq;
            free(temp);
        }
        else{ //Caso 3: tem dois filhos
            Tree* aux = root->esq;
            while(aux->dir) aux = aux->dir; //Encontra o maior número da árvore que seja menor que o número a ser removido
            root->info = aux->info;
            aux->info = x; //Troca a informação a ser removida para uma folha
            root->esq = retira(root->esq, x);
        }
    }
    return root; //Retorna a árvore
}

int maior(int x, int y){ //Função básica que retorna o maior inteiro para facilitar o cálculo da altura (privada)
    if (x>y) return x;
    return y;
}

int altura(Tree *a){ //Calcula a altura da árvore
    if (!a) return -1; //Altura = -1 se a árvore está vazia
    return 1 + maior(altura(a->esq), altura(a->dir)); //Altura da maior das sub-árvores +1 da raiz
}
