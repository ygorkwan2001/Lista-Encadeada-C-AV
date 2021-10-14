#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct listaDupla {
	int matricula;
	float media;
	char situacao;
	struct listaDupla* ant;
	struct listaDupla* prox;
};

typedef struct listaDupla ListaD;

ListaD* create() {
	return NULL;
}

int vazia(ListaD* l) {
	if(l == NULL) {
		printf("\n---Lista vazia---\n");
		return 1;
	} else {
		printf("\n---Lista nao vazia---\n");
		return 0;
	}
}

/*ListaD* adicionar(ListaD* l, int mat, float med) {
	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
	novo->matricula = mat;
	novo->media = med;
	novo->prox = l;
	novo->ant = NULL;
	
	if(l != NULL) {
		l->ant = novo;
	}
	
	if(med >= 7) {
		novo->situacao = 'A';
	} else {
		novo->situacao = 'R';
	}
	printf("\n---Adicionado---\n");
	return novo;
}*/

void imprimir(ListaD* l) {
	
	if(l == NULL) {
		printf("\n---Lista vazia---\n");
	} else {
		ListaD* p;
		
		for(p = l; p != NULL; p = p->prox) {
			printf("----------------------\n");
			printf("Matricula: %d\n", p->matricula);
			printf("Media: %.2f\n", p->media);
			printf("Situacao: %c\n", p->situacao);
		}	
	}	
}

ListaD* procurar(ListaD* l, int mat) {
	ListaD* p;
	
	for(p = l; p != NULL; p = p->prox) {
		if(p->matricula == mat) {
			printf("\n---Matricula %d encontrada---\n", mat);
			return p;
		}
	}
	printf("\n---Matricula %d nao encontrada---\n", mat);
	return NULL;
}

ListaD* remover(ListaD* l, int mat) {
	
	printf("\n---Removendo matricula %d---\n", mat);
	ListaD* p = procurar(l, mat);
	
	if(p != NULL) {
		if(p->ant == NULL && p->prox != NULL) {
			l = p->prox;
		}
		if(p->ant != NULL && p->prox != NULL) {
			p->ant->prox = p->prox;
			p->prox->ant = p->ant;
		}
		if(p->ant != NULL && p->prox == NULL) {
			p->ant->prox = NULL;
		}
		printf("\n---Matricula %d removida---\n", mat);
		free(p);
	}
	
	return l;
}

ListaD* liberar(ListaD* l) {
	ListaD *p = l;
	ListaD* aux;

	while(p != NULL) {
		aux = p->prox;
		free(p);
		p = aux;
	}
	
	printf("\n---Matriculas da lista removidas com sucesso---\n");
	
	return p;
}

ListaD* adicionarOrdernado(ListaD* l, int mat, float med) {

	ListaD* novo = (ListaD*)malloc(sizeof(ListaD));
    novo->matricula = mat;
    novo->media = med;
    
    if(med >= 7) {
		novo->situacao = 'A';
	}
	else {
		novo->situacao = 'R';
	}
	
	if(l == NULL) {
		novo->prox = NULL;
		novo->ant = NULL;
		l = novo;
		
	} else {
		ListaD* aux = l;
    	ListaD* p = l;
    
	    while(p != NULL && p->matricula < mat){
	        aux = p;
	        p = p->prox;
    	}
    	if(p == l) {
    		novo->ant = NULL;
    		//l->ant = novo;
    		novo->prox = l;
    		l = novo;
		} else {
			novo->prox = aux->prox;
			novo->ant = aux;
			aux->prox = novo;
			if(p != NULL) {
				p->ant = novo;
			}
		}
	}
	printf("\n---Matricula %d adicionada com sucesso---\n", mat);
	return l;
}

int quantMat(ListaD* l) {
	int quant;
	ListaD* p = l;
	
	while(p != NULL) {
		quant++;
		p = p->prox;
	}
	printf("\n---Quantidade de matriculas: %d---\n", quant);
	return quant;
}

int main(int argc, char *argv[]) {
	
	ListaD* t;
	t = create();
	
	imprimir(t);
	
	vazia(t);
	
	t = adicionarOrdernado(t, 12, 6);
	t = adicionarOrdernado(t, 14, 7);
	t = adicionarOrdernado(t, 42, 2);
	t = adicionarOrdernado(t, 22, 9);
	t = adicionarOrdernado(t, 8, 5);
	t = adicionarOrdernado(t, 41, 4);
	t = adicionarOrdernado(t, 3, 10);
	
	quantMat(t);
	
	imprimir(t);
	
	vazia(t);
	
	procurar(t, 14);
	
	t = remover(t, 8);
	
	t = remover(t, 1000);
	
	t = adicionarOrdernado(t, 13, 7);
	
	quantMat(t);
	
	imprimir(t);
	
	t = liberar(t);
	
	imprimir(t);
	
	quantMat(t);
	
	vazia(t);
	
	return 0;
}