#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#include"ListaValores.h" // Usando meu cabeçalho

Lista criaL()
{
	Lista *l = NULL; /* ponteiro pra lista */
	l = malloc(sizeof(Lista));
	l->tamanho=0;

	return l;
}

void destroiL(Lista l)
{
	
	EloL atual;

	atual->prox = l->Lista;

	while(atual->prox!= NULL)
	{
		atual = atual->prox;

		free(atual->valor);
		free(atual->prox);

	}

	free(l->tam);
	free(l->Lista);
	free(l);
}


Elemento * insereL(Lista l, Elemento *val);
{

	/* cria EloL */
	EloL *aux = malloc(sizeof(EloL));
	EloL *atual = l->Lista;
	aux->valor = val;
	aux->prox = NULL;

	if (buscaL(l, val) != NULL) return 0; 

	while ( atual != NULL && atual->prox != NULL) 
	{
		atual = atual->prox;
	}

	l->tam++;
	atual->prox = aux;
	return aux;

}

EloL *buscaL(Lista l, Elemento *val)
{
	EloL *atual = l->Lista;
	while(atual->prox != NULL)
	{
		if (atual->val == val)
			return atual;
		atual = atual->prox;
	}

	if (atual->val == val)
			return atual;
	return NULL;
}

Elemento *retiraL(Lista l, Elemento *val)
{
	EloL *atual = buscaL(l, val);
	EloL *anterior = l->Lista;

	while(anterior->prox != atual)
		anterior=anterior->prox;

	anterior->prox=atual->prox;

	free(atual->valor);
	free(atual->prox);
	free(atual);

}