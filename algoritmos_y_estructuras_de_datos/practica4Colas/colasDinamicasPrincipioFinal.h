//Colas memoria dinámica - implementación principio/final

#include <stdio.h>
#include <stdlib.h>



typedef XXX tipoelemento;
typedef struct componenteCola* listaCola;

struct componenteCola
{
	tipoelemento elemento;
	listaCola sig;
};

typedef struct
{
	listaCola principio, final;
}cola;

void colaVacia(cola *q)
{
	q->principio=NULL;
	q->final=NULL;
}

int esVacia(cola q)
{
	return (q.principio==NULL && q.final==NULL);
}

void insertarCola(cola *q, tipoelemento x)
{
	listaCola aux;

	aux=(struct componenteCola *)malloc(sizeof(struct componenteCola));
	if (aux==NULL)
	{
		printf("No se puede reservar memoria");
	}
	else
	{
		aux->elemento=x;
		aux->sig=NULL;

//		if (esVacia(*q))
		if (q->principio==NULL && q->final==NULL)
		{
			q->principio=aux;
		}
		else
		{
			(q->final)->sig=aux;
		}

		q->final=aux;
	}
}

void primeroCola(cola q, tipoelemento* x)
{
//	if (esVacia(q))
	if (q.principio==NULL && q.final==NULL)
	{
		printf("Error. Cola vacia");
	}
	else
	{
		*x=(q.principio)->elemento;
	}
}

void quitarCola(cola *q)
{
	listaCola aux;

//	if (esVacia(*q))
	if (q->principio==NULL && q->final==NULL)
	{
		printf("La cola está vacia");
	}
	else
	{
		aux=q->principio;
		q->principio=(q->principio)->sig;
		free(aux);
		if (q->principio==NULL)
		{
			q->final=NULL;
		}
	}
}


