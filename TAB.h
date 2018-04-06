//TAB.h
#include <stdio.h>
#include <stdlib.h>

#ifndef TAB_H_INCLUDED
#define TAB_H_INCLUDED

typedef struct ab{
	int info;
	struct ab *esq, *dir;
} TAB;

TAB *init_ABB();
int altura(TAB *a);





#endif //TAB_H_INCLUDED
