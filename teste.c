#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

Lista* create(){
    return NULL;
}

Lista* insere(Lista*l,int i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}
void imprimir(Lista* l){
    Lista* p; //Auxiliar na hora de percorrer a lista
    for(p = l; p!=NULL; p = p->prox){
        printf("\nInfo: %d\n",p->info);
    }
}
int tamanholista(Lista *l){
    Lista *aux = l;
	int tam = 0;

	do{
        tam++;
        aux = aux->prox;
    }while(aux != NULL);
        printf("\nTamanho da Lista: %d\n", tam);
	    return tam;
}
Lista* concatena(Lista *l1,Lista *l2){
    do{
        l2 = l2->prox;
    }
    while(l2->prox != NULL);
	    l2->prox = l1;
}
int main(int argc, char const *argv[])
{
    Lista* lista1;
    lista1 = create();

    Lista* lista2;
    lista2 = create();

    lista1 = insere(lista1,1);
    lista1 = insere(lista1,2);
    lista1 = insere(lista1,3);
    lista1 = insere(lista1,4);
    tamanholista(lista1);
    
    printf("-----------------------------------");
    lista2 = insere(lista2,5);
    lista2 = insere(lista2,6);
    lista2 = insere(lista2,7);
    lista2 = insere(lista2,8);
    tamanholista(lista2);

    printf("-----------------------------------");

    concatena(lista1,lista2);

    imprimir(lista2);

    printf("-----------------------------------");

    
    return 0;
}

