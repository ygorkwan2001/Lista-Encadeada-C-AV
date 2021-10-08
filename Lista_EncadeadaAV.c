#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaenc{
    int matricula;
    float media;
    char situacao;
    struct listaenc *prox;
};

typedef struct listaenc Listaenc;

Listaenc* create(void){
    return NULL;
}

int vazia(Listaenc *l){
    if(l == NULL){
        printf("Lista Vazia");
        return 1;
    }else{
        printf("Lista nao esta vazia");
        return 0;
    }
}
int tamanho_lista(Listaenc* l)
{
	Listaenc *c = l;
	int tamanho = 0;

	for(c; c != NULL; c = c->prox)
	{
		tamanho++;
	}
    printf("\nTamanho da Lista: %d\n", tamanho);
	return tamanho;
}
Listaenc* inserir_ordenado(Listaenc *l, int ma, float me){
    
    Listaenc* novo;
    Listaenc* ant = NULL; 
    Listaenc* p = l;
    while (p != NULL && p->matricula < ma){
        ant = p;
        p = p->prox;
    }
    novo = (Listaenc*)malloc(sizeof(Listaenc));
    novo->matricula = ma;
    novo->media = me;
    
    if(me >= 7) {
		novo->situacao = 'A';
	}
	else {
		novo->situacao = 'R';
	}

    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    printf("\nElemento Inserido com Sucesso\n");
    return l;
}

void imprimir(Listaenc *l){
    Listaenc *p;
    for(p = l; p!=NULL; p = p->prox){
        printf("\nMatricula: %d\n",p->matricula);
        printf("\nMedia: %f\n",p->media);
        printf("\nSituacao: %c\n",p->situacao);
    }
}

Listaenc* busca(Listaenc *l, int elem){
    Listaenc* p;
    for (p = l; p!=NULL; p = p->prox){
        if(p->matricula == elem){
            printf("\nO Elemento %d foi encontrado\n",p->matricula);
            return p;
        }
    }
    printf("\nElemento Buscado nao foi encontrado\n");
    return NULL;
}

Listaenc* remover(Listaenc *l, int elem){
    Listaenc* ant = NULL;
    Listaenc* p = l;

    while(p!=NULL && p->matricula!=elem){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){ 
        printf("\nNao tem esse elemento\n");
        return l;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}
Listaenc* liberar(Listaenc* l) {
	Listaenc *p = l;
	Listaenc* aux;

	while(p != NULL) {
		aux = p->prox;
		
        free(p);
		p = aux;
	}
    printf("\nLista Liberada com Sucesso\n");
	return p;
}
int main(int argc, char const *argv[]){
    
    Listaenc* exemplo;
    exemplo = create();


    vazia(exemplo);

    
    exemplo = inserir_ordenado(exemplo,3,8.0);
    exemplo = inserir_ordenado(exemplo,1,6.0);
    exemplo = inserir_ordenado(exemplo,2,9.0);
    exemplo = inserir_ordenado(exemplo,6,5.0);
    exemplo = inserir_ordenado(exemplo,5,2.5);
    exemplo = inserir_ordenado(exemplo,4,7.0);
    imprimir(exemplo);
    printf("----------------------------------");

    printf("----------------------------------");

    //busca(exemplo,2);
    //imprimir(exemplo);

    //printf("----------------------------------");

    exemplo = liberar(exemplo);
    imprimir(exemplo);
    //vazia(exemplo);
    

    // se nao fizer igual perde a referencia do l 
    exemplo = remover(exemplo,3);
    //tamanho_lista(exemplo);
    //imprimir(exemplo);
    printf("----------------------------------");

    //imprimir(exemplo);
    //printf("----------------------------------");

    //printf("----------------------------------");

    //imprimir(exemplo);

    //printf("----------------------------------");

    //exemplo = liberar(exemplo);

    //printf("----------------------------------");

    //imprimir(exemplo);

    
    

    



}
