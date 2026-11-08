#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////UDALIT POTOM!! ////////////////////

//Si una persona pide mas entradas de las que quedan disponibles,
//se pasa a la siguiente petición o se termina el reparto de entradas?

/////////////////////////UDALIT POTOM!! ////////////////////

//////////////////////////////////// Definición de tipos ////////////////////////////////////
//Colas memoria din·mica - implementaciÛn principio/final

#include <stdio.h>
#include <stdlib.h>

struct peticion{
	
	char nif[10];
	int entradas;
	char tarjeta[20];
	
		
};

typedef struct peticion tipoelemento;
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









//////////////////////////////////// OPERACIONES ////////////////////////////////////




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
	int i, num;
	
	colaVacia(&c);
	
	printf("\nnumero de peticiones:");
	scanf(" %d", &num); 
	
	
	for(i=0; i < num; i++){
		
		printf("\n\nPEticion %d\n", i + 1);

		
		printf("NIF: ");
		scanf(" %9s", x.nif);


		do {
			
    		printf("\nNumero de entradas(<= 5): ");
    		scanf("%d", &x.entradas);

    	} while (x.entradas < 1 || x.entradas > 5);

		
		
		printf("\nNumero de la tarjeta: ");
		scanf(" %19s", x.tarjeta);
		
		insertarCola(&c, x);
	}
	
	//aqui cambio el uso de num, ahora es para el numero de entradas disponible
	
	printf("\nnumero de entradas disponibles:");
	scanf("%d", &num); 
	
	while(!esVacia(c) && num > 0){
		
		primeroCola(c, &x);
		
		if(x.entradas > num){
			
			printf("\nLa cantidad de entradas no es suficiente ");
			
            
//            si la frase orden riguoso en el enunciado significa que no podemos seguir vendiendo las
//            entradas en el caso cuando no hay suficientes para una persona
            

//            limpiamos la memoria:
            while(!esVacia(c)){
                quitarCola(&c);
            }
            
//            y salimos del ciclo directamente
            break;
            

            
			
		}else{
			
			//aqui tengo el importe int porque en el ejercicio no hay caso cuando lo seria double/float(10 * numEntradas(int))
			
			printf("NIF: %s, el importe a abonar: %d eur",x.nif, x.entradas * 10);
			num -= x.entradas;
			quitarCola(&c);
			
		}
        

        }
    
//        si el numeros de entradas ya es 0 pero la cola no esta vacia, limpiamos la memoria
            while(!esVacia(c)){
                quitarCola(&c);
	}
	
	
	return 0;
}
