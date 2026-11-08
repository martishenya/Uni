

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//////////////////////////////////// Definición de tipos ////////////////////////////////////

struct monomio {
    double coef;
    int exp;
};

typedef struct monomio tipoelementolista;


typedef  struct componente* lista;

struct componente
{
	tipoelementolista elemento;
	lista enlace;
};

//////////////////////////////////// OPERACIONES ////////////////////////////////////

void inicializarLista(lista* l)
{
	*l=NULL;
}

void insertarLista(lista *l, tipoelementolista x)
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

void insertarOrden(lista *l, tipoelementolista x)
{
	lista aux;

	if(esVaciaLista(*l))
	{
		aux=(struct componente *)malloc(sizeof(struct componente));

		if(aux==NULL)
		{
			printf("No hay memoria. No se puede realizar la insercion\n");
		}
		else
		{
			aux->elemento=x;
			aux->enlace=*l;
			*l=aux;
		}
	}
	else
	{
		if(x.exp < (*l)->elemento.exp)
		{
			aux=(struct componente *)malloc(sizeof(struct componente));

			if(aux==NULL)
			{
				printf("No hay memoria. No se puede realizar la insercion\n");
			}
			else
			{
				aux->elemento=x;
				aux->enlace=*l;
				*l=aux;
			}
		}
		else
		{
			insertarOrden(&((*l)->enlace), x);
		}
	}
}

void primeroLista(lista l, tipoelementolista* x)
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


/////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	
	int i = 0, num;
	
	double x, res;
	
	
	tipoelementolista info;
	
	lista l;

	inicializarLista(&l);
	
	printf("\nnumero de elementos:");
	scanf(" %d", &num); 
	
	for(i=0; i < num; i++){
		
		printf("\nIntroduce el coeficiente del elemento %d: ", i);
		scanf("%lf", &info.coef);
		
		printf("\nIntroduce el exponente   del elemento %d: ", i);
		scanf("%d", &info.exp);
		
		insertarOrden(&l, info);
		
	}
	
	
	printf("\nIntroduce el valor de x ");
		scanf("%lf", &x);
	

	res = 0;
	
	if(esVaciaLista(l)){
		
		printf("\nPolinomio esta vacio ");
		return 0;
		
	}
	
	
	
	while(!esVaciaLista(l)){
		
		primeroLista(l, &info);
		
		res += info.coef * (pow(x, info.exp));
		
		restoLista(&l);
		
	}
	
	printf("El resultado es: %lf", res);
	
	return 0;
}




