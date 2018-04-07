//TAB.c
#include "TAB.h"

Tree* init_ABB(){
    return NULL;
}

int treeIsEmpty(Tree *root){
    return (root == NULL); //Verifica se a �rvore est� vazia (Retorna 1 se estiver vazia e 0 caso contr�rio)
}

//Pr�-Ordem
void printTreePre(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printf("%d ",root->info); //Imprime a raiz
        printTreePre(root->esq); //Visita a sub-�rvore da esquerda
        printTreePre(root->dir); //Visita a sub-�rvore da direita
    }
    printf("> ");
}

//Simetria
void printTreeSim(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreeSim(root->esq); //Visita a sub-�rvore da esquerda
        printf("%d ",root->info); //Imprime a raiz
        printTreeSim(root->dir); //Visita a sub-�rvore da direita
    }
    printf("> ");
}

//P�s-Ordem
void printTreePos(Tree *root){
    printf("<");
    if (!treeIsEmpty(root)){
        printTreePos(root->esq); //Visita a sub-�rvore da esquerda
        printTreePos(root->dir); //Visita a sub-�rvore da direita
        printf("%d ",root->info); //Imprime a raiz
    }
    printf("> ");
}

Tree* busca(Tree *root, int x){ //Fun��o de busca
    if((x == root->info)||(!root)) return root;
    if(x < root->info) return busca(root->esq, x);
    return busca(root->dir, x);
}

Tree* criaFolha(int x){ //Fun��o necess�ria apenas para a fun��o de inser��o (privada)
    Tree *novo = (Tree*)malloc(sizeof(Tree));
    novo->info = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Tree* insere(Tree *root, int x){ //Fun��o de Inser��o
    if(!root) return criaFolha(x); //Cria a folha se a �rvore ou sub-�rvore est� vazia
    if(x < root->info) root->esq = insere(root->esq, x);
    else if(x > root->info) root->dir = insere(root->dir, x);
    return root;
}

Tree* retira(Tree* root, int x){ //Func�o de Remo��o
    if(!root) return root; //�rvore vazia, n�o h� o que remover
    if(x < root->info) root->esq = retira(root->esq, x);
    else if(x > root->info) root->dir = retira(root->dir, x);
    else{ //Encontrou o elemento a ser removido
        if((!root->esq)&&(!root->dir)){ //Caso 1: � uma folha
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
            while(aux->dir) aux = aux->dir; //Encontra o maior n�mero da �rvore que seja menor que o n�mero a ser removido
            root->info = aux->info;
            aux->info = x; //Troca a informa��o a ser removida para uma folha
            root->esq = retira(root->esq, x);
        }
    }
    return root; //Retorna a �rvore
}

int maior(int x, int y){ //Fun��o b�sica que retorna o maior inteiro para facilitar o c�lculo da altura (privada)
    if (x>y) return x;
    return y;
}

int altura(Tree *a){ //Calcula a altura da �rvore
    if (!a) return -1; //Altura = -1 se a �rvore est� vazia
    return 1 + maior(altura(a->esq), altura(a->dir)); //Altura da maior das sub-�rvores +1 da raiz
}
