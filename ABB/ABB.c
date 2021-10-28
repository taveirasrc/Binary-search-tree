#include <stdio.h>
#include <stdlib.h>
//#include "fila_abb.h"

typedef struct tree {
    int info;
    struct tree *esq;
    struct tree *dir;
} Tree;

/*
void insere(struct tree **raiz, int info)
{
    if (*raiz == NULL)
        *raiz = criaNo(info);
    else {
        if ((*raiz)->info < info)
        {
            if ((*raiz)->dir == NULL)
                (*raiz)->dir = criaNo(info);
            else
                insere(&(*raiz)->dir, info);
        }
        else
        {
            if ((*raiz)->esq == NULL)
                (*raiz)->esq = criaNo(info);
            else
                insere(&(*raiz)->esq, info);
        }
    }
}
*/

void insere(struct tree **no, int info)
{
    if (*no == NULL)
        *no = novoNo (info);
    else 
    {
        if (info < (*no)->info)
            insereRecursivo (&(*no)->esq, info);
        else
            insereRecursivo (&(*no)->dir, info);
    }
}

void buscaRecursiva(struct tree *raiz, int info, struct tree **aux)
{
    if (raiz != NULL)
    {
        if (info == raiz->info)
            *aux = raiz;
        else
            if (info < raiz->info)
                buscaRecursiva(raiz->esq, info, &*aux);
            else
                buscaRecursiva(raiz->esq, info, &*aux);
    }
    else
        *aux = NULL;
}


////////////////////////////////////////// BUSCA ITERATIVA
void busca(struct tree *raiz, int info, struct tree **aux)
{
    while (raiz != NULL && info != raiz->info)
    {
        if (info < raiz->esq)
            raiz = raiz->esq;
        else
            raiz = raiz->dir;
    }
    *aux = raiz;
}

//exclusao(&*raiz, e, pai, 'e');

void exclusao (Tree **raiz, Tree *e, Tree *pai, char lado)
{
	
	if (e->esq == NULL && e->dir == NULL) //e->esq == e->dir
	{
		
	}
	else if (e->esq == NULL || e->dir == NULL)
	{
		
	} else {
		
		if (lado == 'e')
		{
			
		}
		else
		{
			
		}
	}
}

void balanceamento(struct tree **raiz)
{
    struct tree *no;
    struct tree *e;
    struct tree *pai;

    int aux;
    int qdir;
    int qesq;
    int fb;

    struct fila *f;
    init(&f);
    enqueue(&f, *raiz);
    while (!isEmpty(f))
    {
        dequeue(&f, &no);

        do
        {
            qdir = qesq = 0;
            quantNo(no->dir, &qdir);
            quantNo(no->esq, &qesq);

            fb = qdir - qesq;

            if (abs(fb) > 1)
            {
                aux = no->info;
                busca(*raiz, aux, &e, &pai);

                if (no->esq == NULL)
                    no = no->dir;
                else if (no->dir == NULL)
                    no = no->esq;

                if (fb > 0)
                    exclusao(&*raiz, e, pai, 'd');
                else
                    exclusao(&*raiz, e, pai, 'e');

                insere(&*raiz, aux);
            }
        } while (abs(fb) > 1);
    }

    if (no->esq != NULL)
        enqueue(&f, no->esq);

    if (no->dir != NULL)
        enqueue(&f, no->dir);
}


int main()
{
    
    return 0;
}
