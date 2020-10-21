#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct noh
{
	int info;
	struct noh* esq;
	struct noh* dir;
};
typedef struct noh arvore;

arvore* arv_cria(int c, arvore* sae, arvore* sad){
	arvore* p = (arvore*)malloc(sizeof(arvore));
	if(p==NULL) exit(1);
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

arvore* arv_criavazia(void){
	return NULL;
}

arvore* abb_insere(arvore* a, int v){
	if(a==NULL){
		a= (arvore*)malloc(sizeof(arvore));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else if(v < a->info) a->esq = abb_insere(a->esq, v);
	else a->dir = abb_insere(a->dir, v);
	return a;
}

arvore* abb_retira(arvore* r, int v){
	if(r==NULL) return NULL;
	else if(r->info > v) r->esq=abb_retira(r->esq, v);
	else if(r->info < v) r->dir=abb_retira(r->dir, v);
	else{
		if(r->esq==NULL && r->dir==NULL){
			free(r);
			r = NULL;
		}
		else if(r->esq==NULL){
			arvore* t = r;
			r = r->dir;
			free(t);
		}
		else if(r->dir==NULL){
			arvore* t = r;
			r = r->esq;
			free(t);
		}
		else{
			arvore* f = r->esq;
			while(f->dir != NULL){
				f = f->dir;
			}
			r->info = f->info;
			f->info = v;
			r->esq = abb_retira(r->esq, v);
		}
	}
	return r;
}

int arv_vazia(arvore* a){
	return a == NULL;
}

void arv_imprime_ordem(arvore* a){
	if(!arv_vazia(a)){
		arv_imprime_ordem(a->esq);
		cout << a->info << " ";
		arv_imprime_ordem(a->dir);
	}
}

int main(){
	int op, val;
	
	cout << "Raiz da Arvore: ";
	cin >> val;
	cout << endl;
	arvore* A1 = arv_cria(val, arv_criavazia(), arv_criavazia());
	
	do{
		cout << "1 - IMPRIMIR EM ORDEM" << endl;
		cout << "2 - INSERIR" << endl;
		cout << "3 - EXCLUIR" << endl;
		cout << "4 - SAIR" << endl;		
		cin >> op;
		
		switch(op)
		{
		case 2:
			cout << "Valor a ser inserido: ";
			cin >> val;
			cout << endl;
			abb_insere(A1, val);			
			break;
		case 1:
			arv_imprime_ordem(A1);
			cout << endl;
			break;
		case 3:
			cout << "Valor a ser excluido: ";
			cin >> val;
			cout << endl;
			abb_retira(A1, val);
			break;
		default:
			break;
		}
		
	}while(op != 4);
	
	return 0;
}

























