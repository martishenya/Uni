#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//////////////////////////////////// DEFINICION DE TIPOS ////////////////////////////////////

struct infoViaje{
	
	char nif[10];
	char nombreApellidos[31];
	char destino[20];
	double presupuesto;
	
};

typedef struct infoViaje tipoelemento;
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


//////

typedef  struct componente* lista;

struct componente
{
	tipoelemento elemento;
	lista enlace;
};

//////////////////////////////////// OPERACIONES LISTA////////////////////////////////////



void inicializarLista(lista* l)
{
	*l=NULL;
}

void insertarLista(lista *l, tipoelemento x)
{
	lista aux;

	aux=(struct componente *)malloc(sizeof(struct componente));
	if (aux==NULL)
	{
		printf("No hay memoria. No se pueder realizar la insercion\n");
	}
	else
	{
		aux->elemento=x;
		aux->enlace=*l;
		*l=aux;
	}
}

int esVaciaLista(lista l)
{
	return (l==NULL);
}

void primeroLista(lista l, tipoelemento* x)
{
	if (l==NULL)
	{
		printf("La lista est? vacia");
	}
	else
	{
		*x=l->elemento;
	}
}

void restoLista(lista *l)
{
	if (*l==NULL)
	{
		printf("Lista vacia");
	}
	else
	{
		*l=(*l)->enlace;
	}
}


//////////////////////////////////// OPERACIONES COLA////////////////////////////////////




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
		printf("La cola est· vacia");
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



int main(void){
	
	tipoelemento x;
	cola c;
	lista l;
	
	int num, i;
	
	double presupMin;
	
	char destino[20];
	
	colaVacia(&c);
	inicializarLista(&l);

	printf("\nnumero de personas: ");
	scanf(" %d", &num); 
	
	for (i=0; i < num; i++){
		
		printf("\n\nViaje de persona %d\n", i + 1);

		
		printf("NIF: ");
		scanf(" %9s", x.nif);

		printf("Nombre y Apellidos: ");
		scanf(" %30[^\n]", x.nombreApellidos);

    	printf("\nDestino: ");
    	scanf(" %19s", x.destino);
		
		printf("\nPresupuesto disponible: ");
		scanf(" %lf", &x.presupuesto);
		
		insertarCola(&c, x);
		
	}
	
	printf("\ndestino: ");
	scanf(" %19s", destino);
	
	
	while(!esVacia(c)){
		
		primeroCola(c, &x);
		
		if(strcmp(x.destino, destino) == 0){
			
			insertarLista(&l, x);
			
		}
		
		quitarCola(&c);
		
	}
	
	
	printf("\npresupuesto minimo: ");
	scanf(" %lf", &presupMin);
	
	printf("\nlas personas que disponen de un presupuesto superior a presupuesto minimo: ");
	
	while(!esVaciaLista(l)){
		
		primeroLista(l, &x);
		
		if(x.presupuesto > presupMin){
			
			printf(" \n%s", x.nombreApellidos);
			
		}
		
		restoLista(&l);
		
	}
	
	
	
	return 0;
}
