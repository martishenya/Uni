

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//////////////////////////////////// Definición de tipos ////////////////////////////////////


struct fecha{
	
	int dia;
	int mes;
	int anno;
	
};


struct instancia{
	
	int numExp;
	struct fecha fecha;
	char titulacion[30];
	
	double importe;
	
	
};


typedef struct instancia tipoelementopila;

typedef struct componentepila* pila;


struct componentepila
{
	tipoelementopila elemento;
	pila sig;
};


//////////////////////////////////// OPERACIONES ////////////////////////////////////


void pilaVacia(pila *p)
{
	*p=NULL;
}

int esVaciaPila(pila p)
{
	return (p==NULL);
}

void insertarPila(pila *p, tipoelementopila x)
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

void cima(pila p, tipoelementopila* x)
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


int main(void){
	
	//////////////// Definición de variables ////////////////////////////////////
	
	pila p;
	tipoelementopila x;
	int num, i, mesBusc;
	char titulacionBusc[30];
	double importeTotal = 0;
	
	
	
	
	pilaVacia(&p);
	
	printf("numero de instancias:");
	scanf("%d", &num);
	
	for (i = 0; i < num; i++){
		
		printf("\nInstancia %d\n", i + 1);

		do {
			
    		printf("Numero de expediente: ");
    		scanf("%d", &x.numExp);

    	} while (x.numExp < 10000 || x.numExp > 99999);

		printf("Dia: ");
		scanf(" %d", &x.fecha.dia);
		
		printf("Mes: ");
		scanf(" %d", &x.fecha.mes);
		
		printf("Anno: ");
		scanf(" %d", &x.fecha.anno);
		
		printf("Titulacion: ");
		scanf(" %29[^\n]", x.titulacion);
		
		printf("Importe: ");
		scanf(" %lf", &x.importe);
		
		insertarPila(&p, x);
	}
	
	printf("el mes:");
	scanf(" %d", &mesBusc);
	
	printf("Titulacion:");
	scanf(" %29[^\n]", titulacionBusc);
	
	i = 0;
	
	while(!esVaciaPila(p)){
		
		cima(p, &x);
		if((x.fecha.mes == mesBusc) && (strcmp(x.titulacion,titulacionBusc) == 0)){
			
			importeTotal += x.importe;
			
			i++;
		}
		
		borrar(&p);
	}
	
	printf("\nImporte total: %.2f, numero de instancias apropiadas: %d de %d", importeTotal, i, num);
	
	
	return 0;
}
	




