//1.Realiza una función inicializarPtro que inicialice a NULL el puntero que recibe como parámetro.
//Haz que este puntero sea de tipo puntero a struct datosPoint.
//Llama a esta función desde la main pasándole ptroPoint y visualiza a continuación la dirección almacenada en ptroPoint, es decir a dónde apunta.
//¿Podrías rellenar los campos x e y de los datos apuntados por el puntero? Si no sabes contestar prueba a hacerlo en la main y observa qué pasa.


//2. Realiza una función inicializarPunto que permita inicializar una variable de tipo struct datosPoint que recibirá como parámetro.
//Dentro de la función inicializa los campos x e y a dos valores que introduzca el usuario.
//Llama a esta función desde la main para inicializar correctamente point.
//A continuación, reserva memoria del montón para la variable ptroPoint e inicializa sus datos a los mismos valores de point. Visualiza los datos de point y los apuntados por ptroPoint para comprobar que son los mismos.
//Modifica ahora los datos apuntados por ptroPoint y visualiza los datos de point. ¿Se han modificado? ¿Por qué?


//3. Declara un array de 10 enteros (a) y un puntero a entero (ptro).
//Visualiza cuánto ocupa la variable a.¿Es lo que esperabas?
//Asigna ptro = a; ¿Me da algún error? ¿por qué?
//Visualiza en un printf la dirección almacenada en ptro y la dirección de la variable a. ¿Qué observas?
//Escribe ahora printf("\n a es %p",a);¿cuánto vale? ¿Qué nos dice?

//A continuación, prueba el siguiente código, antes de hacerlo, piensa que crees que va a visualizar.
//
//int i; int a[10] = {0,1,2,3,4,5,6,7,8,9};
//int *ptro; ptro = a; printf("\n\n");
//for (i=0;i<10;i++){ printf("[%d]",ptro[i]); //acceso con sintaxis de array }
//    printf("\n\n");
//for (i=0;i<10;i++,ptro++){ //aritmética de punteros
//    printf("[%d]",*ptro); }
//    printf("\n\n");
//    
//¿Se ha modificado la dirección apuntada por ptro después del primer for? ¿Y después del segundo? Prueba ahora a incluir el segundo for en una función (ver prototipo y definición a continuación).
//    ¿Qué pasa ahora con la dirección apuntada por ptro después de llamar a la función visualizar, se modifica? ¿Por qué?

#include <stdlib.h>
#include <stdio.h>


struct datosPunto{
    double x;
    double y;
};

void inicializarPtro(struct datosPunto ** puntStru);

void inicializarPunto(struct datosPunto * puntStru);

void visualizar(int *ptro);

int main(void) {
    
    struct datosPunto * ptroPoint;
    
    struct datosPunto point;
    
    
    
    int * ptro;
    
    
    
    //---------------------------------

    //    APARTADO 1

    //---------------------------------
    
    inicializarPtro(&ptroPoint);
    
    printf("la dirección a la que apunta ptroPoint: %p\n", ptroPoint);
    
    printf("No podemos rellenar porque la dirreccion que tiene ptroPoint es NULL que significa que no lo tiene todavia\n\n");
    
    
    
    //---------------------------------

    //    APARTADO 2

    //---------------------------------
    
    inicializarPunto(&point);
    
    ptroPoint = (struct datosPunto *)malloc(sizeof(struct datosPunto));
    
    ptroPoint->x = point.x;
    ptroPoint->y = point.y;
    
    printf("Datos de ptroPoint x:%2.f y:%2.f\n", ptroPoint->x, ptroPoint->y);
    printf("Datos de point x:%2.f y:%2.f\n", point.x, point.y);
    printf("Son los mismos\n");
    
    ptroPoint->x = 55;
    ptroPoint->y = 66;
    
    printf("Los valores de point no hemos cambiados despues de cambiar los valores de ptroPoint porque las dirrecciones son diferentes:\n");
    
    printf("Datos de ptroPoint x:%2.f y:%.2f\n", ptroPoint->x, ptroPoint->y);
    printf("Datos de point x:%2.f y:%.2f\n\n", point.x, point.y);
    
    
    //---------------------------------

    //    APARTADO 3

    //---------------------------------
    
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    
    printf("a: %lu\n", sizeof(a));
    
    ptro = a;
    
    printf("Esta operacion no da ningun error porque variable a(array) es la dirreccion de primer elemento asi que aqui solamente damos la direccion de array a puntero ptro\n");
    
    printf("aqui vemos lo que he dicho antes\n");
    
    printf("la dirección a la que apunta a: %p\n", a);
    
    printf("la dirección a la que apunta ptro: %p\n", ptro);
    
    
    
    
    printf("a es %p\n",a);
    
    
    
    printf("nos dice que imprimir a con %%p muestra la dirección del primer elemento del array\n\n");
    
    int i;
    
    printf("\nDireccion ptro antes de primer for: %p\n", ptro);
    
    for (i = 0; i < 10; i++) {
        printf("[%d]", ptro[i]);
    }
    
    printf("\nDireccion ptro despues de primer for: %p\n", ptro);
    
    ///
    
    printf("\n\nDireccion ptro antes del segundo for: %p\n", ptro);

    for (i = 0; i < 10; i++, ptro++) {
        printf("[%d]", *ptro);
    }

    printf("\nDireccion ptro despues del segundo for: %p\n", ptro);
    

    printf("\nEn dos casos va a visualizar los valores del array\n");
    printf("En primer caso el puntero no se cambia, pero en el segundo si porque aritmética de punteros muevalo a la derecha y despues del for va a estar en un punto despues del array\n");
    
    ptro = a;
    
    printf("\nDireccion ptro antes de visualizar: %p\n", ptro);

    visualizar(ptro);

    printf("\nDireccion ptro despues de visualizar: %p\n", ptro);
    
    
    
    printf("El uso de la funcion no cambia el puntero porque alli dentro trabaja con su copia\n");
    
    ///PARTE VOLUNTARIA 4
    
    int *p1,*p2,*p3;
    p1 = (int *)malloc(sizeof(int));
    p2 = (int *)malloc(sizeof(int));
    p3 = (int *)malloc(sizeof(int));
    
    *p1 = 10;
    *p2 = 20;
    *p3 = 30;
    
    printf("\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    //libero p1
    free(p1);
    
    printf("\n\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    //libero p3
    free(p3);
    
    //reservo p1
    p1 = (int *)malloc(sizeof(int));
    *p1 = 99;
    printf("\n\n Dato apuntado por p1 es %d dirección del dato %p",*p1,p1);
    printf("\n Dato apuntado por p2 es %d dirección del dato %p",*p2,p2);
    printf("\n Dato apuntado por p3 es %d dirección del dato %p",*p3,p3);
    printf("\n");
    
    printf("\nEste parte nos muestra que despues de fucnion free la variable sigue tener la dirrecion antigua pero el progr ya no tiene acceso a esta memoria\n");
    printf("\nPor eso puede salir el resultado que no esperamos\n");
    
    
    
    
    ///PARTE VOLUNTARIA 5
    
    int *puntero;

    puntero = (int *)malloc(sizeof(int));
    *puntero = 23;

    printf("\nAntes de la segunda reserva: valor = %d, direccion = %p", *puntero, puntero);

    puntero = (int *)malloc(sizeof(int));

    printf("\nDespues de la segunda reserva: valor = %d, direccion = %p", *puntero, puntero);

    
    
    free(puntero);
    
    
    printf("\nAsi no podemos hacer porque perdimos la primera dericcion despues del malloc \n");

    
    return 0;
}

void inicializarPtro(struct datosPunto ** puntStru){
    
    *puntStru = NULL;
    
}

void inicializarPunto(struct datosPunto * puntStru){
    
    printf("\nIntroduzca los valores:");
    scanf("%lf", &puntStru -> x);
    scanf("%lf", &puntStru -> y);
}

void visualizar(int *ptro){
    int i;

    printf("\nDireccion ptro dentro de visualizar: %p\n", (void *)ptro);

    for (i = 0; i < 10; i++, ptro++) {
        printf("[%d]", *ptro);
    }

    printf("\nDireccion ptro al final de visualizar: %p\n", (void *)ptro);
}
