//TAB.h
#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

typedef struct tree{
	int info;
	struct tree *esq, *dir;
} Tree;

Tree* init_ABB(); //Inicializa a árvore (NULL)
int treeIsEmpty(Tree *root); //Verifica se a árvore está vazia (Retorna 1 se estiver vazia e 0 caso contrário)
void printTreePre(Tree *root); //Imprime todos os elementos da árvore seguindo a Pré-Ordem
void printTreeSim(Tree *root); //Imprime todos os elementos da árvore seguindo a Ordem Simétrica
void printTreePos(Tree *root); //Imprime todos os elementos da árvore seguindo a Pós-Ordem
Tree* busca(Tree *root, int x); //Retorna ponteiro para o nó que contém info == x (NULL caso não haja)
Tree* insere(Tree *root, int x); //Insere elemento com info == x na árvore (Sem repetições)(Retorna ponteiro da árvore modificada)
Tree* retira(Tree *root, int x); //Remove elemento da árvore (Retorna ponteiro da árvore modificada)
int altura(Tree *a); //Retorna a altura da árvore
void libera(Tree *root); //Libera a estrutura (usar após o uso)





#endif //TAB_H_INCLUDED
