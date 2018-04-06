//main.c
#include "TAB.h"

int main(){
    TAB *raiz;
    raiz = init_ABB();
    int height = altura(raiz);
    printf("Altura = %d", height);
    return 0;
}
