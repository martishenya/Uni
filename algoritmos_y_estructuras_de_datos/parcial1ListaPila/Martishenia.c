#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//////////////////Definicion de tipos:

struct fecha{
	
	int dia;
	int mes;
	int anno;
	
};

struct dato{
	
	char nif[11];
	struct fecha fechaInicio;
	struct fecha fechaFinal;
	char destino[40];
	double anticipo;
	
};




typedef struct dato tipoelemento;


typedef  struct componente* lista;


typedef struct componentepila* pila;

//////////////////OPERACIONES PARA LA LISTA
///////He elegido la lista para primera estructura porque tenemos que tener las peticiones accesibles

struct componente
{
	tipoelemento elemento;
	lista enlace;
};

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

//////////////////OPERACIONES PARA LA PILA

///////He elegido la pila para segunda estructura porque tenemos que tener el orden inverso y con la idea LIFO de pila esto podemos alcanzar



struct componentepila
{
	tipoelemento elemento;
	pila sig;
};


void pilaVacia(pila *p)
{
	*p=NULL;
}

int esVaciaPila(pila p)
{
	return (p==NULL);
}

void insertarPila(pila *p, tipoelemento x)
{
	pila aux;

	aux=(struct componentepila *)malloc(sizeof(struct componentepila));
	if (aux == NULL)
	{
		printf("Error. Memoria agotada");
	}
	else
	{
		aux->sig=*p;
		aux->elemento=x;
		*p=aux;
	}
}

void cima(pila p, tipoelemento* x)
{
	if (p==NULL)
	{
		printf("Error. Pila Vacia");
	}
	else
	{
		*x=p->elemento;
	}
}

void borrar(pila *p)
{
	pila aux;

	if ((*p)==NULL)
	{
		printf("Error. Pila vacia");
	}
	else
	{
		aux=*p;
		*p=(*p)->sig;
		free(aux);
	}
}



int main(){
	
	
	
	tipoelemento x;
	
	lista l;
	pila p;
	
	//Aqui inicializamos nuestras estructuras
	
	inicializarLista(&l);
	pilaVacia(&p);
	
	int num, i, mesAux;
	double anticipoTotal = 0;
	
	
	
	
	
	
	printf("Introduce de peticiones");
	scanf(" %d", &num);
	
	for(i = 0; i < num; i++){
		
		printf("NIF:\n");
		scanf(" %s", x.nif);
		
		printf("anno de inicio:\n");
		scanf(" %d", &x.fechaInicio.anno);
		
		printf("mes de inicio:\n");
		scanf(" %d", &x.fechaInicio.mes);
		
		printf("dia de inicio:\n");
		scanf(" %d", &x.fechaInicio.dia);
		
		printf("anno de final:\n");
		scanf(" %d", &x.fechaFinal.anno);
		
		printf("mes de final:\n");
		scanf(" %d", &x.fechaFinal.mes);
		
		printf("dia de final:\n");
		scanf(" %d", &x.fechaFinal.dia);
		
		printf("destino: \n");
		scanf(" %s", x.destino);
		
		printf("anticipio entregado: \n");
		scanf(" %lf", &x.anticipo);
		
		//aqui rellenamos la lista con cada paso del bucle
		
		insertarLista(&l, x);
	}
	
	
	
	while(!esVaciaLista(l)){
		
		//sacamos el elemento primero de la lista para hacer comprobaciones
		
		primeroLista(l, &x);
		
		if(x.fechaFinal.anno == 2026 && x.fechaInicio.anno == 2026){
			
			//insertamos solo aquellos elementos que son de la condicion
			
			insertarPila(&p, x);
			
		}
		
		//para avanzar leendo la lista tenemos que restar/ mover el puntero en la lista 
		
		restoLista(&l);
		
	}
	
	//en este paso ya tenemos la lista rellenada con datos correspondientes
	
	printf("introduce el mes: \n");
	scanf(" %d", &mesAux);
	
	printf("NIF de personas que han solicitado destino Salamanca y en el mes: %d del anno 2026\n", mesAux);
	
	while(!esVaciaPila(p)){
		
		//aqui sacamos a variable x la info de la pila para mostar la informacion que corresponde con la condicion 
		
		cima(p, &x);
		
		if(strcmp(x.destino, "Salamanca") == 0 && x.fechaInicio.mes == mesAux){
			
			
			//hacemos de los nif necesarios 
			printf("NIF: %s\n", x.nif);
			
			
			anticipoTotal += x.anticipo;
			
		}
		
		//avanzamos leendo la pila de la logica last in first out que supone que las peticiones almacenan en orden inverso
		
		borrar(&p);
		
	}
	
	printf("Anticipo total: %f \n", anticipoTotal);
	
	
	
	return 0;
	
}


