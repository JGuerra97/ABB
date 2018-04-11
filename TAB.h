//TAB.h
#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

typedef struct tree{
	int info;
	struct tree *esq, *dir;
} Tree;

Tree* init_ABB(); //Inicializa a �rvore (NULL)
int treeIsEmpty(Tree *root); //Verifica se a �rvore est� vazia (Retorna 1 se estiver vazia e 0 caso contr�rio)
void printTreePre(Tree *root); //Imprime todos os elementos da �rvore seguindo a Pr�-Ordem
void printTreeSim(Tree *root); //Imprime todos os elementos da �rvore seguindo a Ordem Sim�trica
void printTreePos(Tree *root); //Imprime todos os elementos da �rvore seguindo a P�s-Ordem
Tree* busca(Tree *root, int x); //Retorna ponteiro para o n� que cont�m info == x (NULL caso n�o haja)
Tree* insere(Tree *root, int x); //Insere elemento com info == x na �rvore (Sem repeti��es)(Retorna ponteiro da �rvore modificada)
Tree* retira(Tree *root, int x); //Remove elemento da �rvore (Retorna ponteiro da �rvore modificada)
int altura(Tree *a); //Retorna a altura da �rvore
void libera(Tree *root); //Libera a estrutura (usar ap�s o uso)





#endif //TAB_H_INCLUDED
