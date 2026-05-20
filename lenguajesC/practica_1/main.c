//Define un tipo de dato estructura con dos campos reales dobles (double) x e y que sirva para almacenar un punto en un sistema de coordenadas.
//Declara una variable entera (llamada number), una variable puntero a entero (con nombre ptroInt), una variable del tipo de la estructura (point) y una variable puntero a la estructura (ptroPoint).
//Visualiza cuanto ocupan estas variables en tu máquina.

//Contesta a las siguientes preguntas en uno o varios printf.
//¿Cuál ocupa más?
//¿Cuáles ocupan lo mismo? ¿Por qué?
//¿Sabrías ahora decir cuánto ocupa un double en tu máquina sin usar sizeof? Razona tu respuesta.
//¿Cuánto ocupa *ptroInt? ¿Sabrías cuánto es antes de hacerlo?

//Nota: los datos que devuelve la función sizeof son de tipo unsigned long (un tipo especial de entero) y en el printf se visualizan con %lu


// 2) Inicializa number a 100, inicializa ptroInt para que apunte a number.
//Modifica el valor de los datos apuntados por ptroInt a 33.
//Ahora visualiza la dirección almacenada en ptroInt, los datos apuntados por ptroInt y en otro printf visualiza la dirección de memoria en la que se almacena number y su valor.
//¿Qué observas?
//Escribe un printf con lo que has observado. Nota: Para visualizar una dirección de memoria usa %p

//3) Realiza una función a la que le pases un puntero a entero y en la que le solicites al usuario que introduzca un nuevo valor para los datos apuntados léelo con scanf correctamente.
//Llama a esta función pasándole la dirección en la que está almacenada number y visualiza cuánto vale number antes y después de la llamada. ¿Se ha modificado? ¿por qué?

//4) Ahora llama a esta función desde la función main pasándole ptroInt y visualiza cuánto vale number antes y después de la llamada.
//¿Se ha modificado number? ¿por qué? ¿Y los datos apuntados por ptroInt, se han modificado?
//¿Por qué?
//Por último, ¿se ha modificado la dirección a la que apunta ptroInt? ¿Por qué?

//5) Declara ahora en tu main otro puntero a entero (ptroInt2) y visualiza la dirección de memoria donde está almacenado ptroInt2.
//Inicialízalo de manera dinámica usando malloc. Visualiza a qué dirección ha inicializado malloc la variable ptroInt2, es decir cuánto vale ptroInt2 o lo que es lo mismo a donde apunta ptroInt2.
//Ahora llama correctamente a la función realizada en el apartado 3 para inicializar los datos apuntados por ptroInt2 y visualiza tras la llamada cuánto vale el dato apuntado.

#include <stdlib.h>
#include <stdio.h>



struct coordenadas{
    double x;
    double y;
};

void func(int * numFunc);

int main(void) {
    
    printf("\nAPARTADO 1\n\n");
    
//---------------------------------

//    APARTADO 1

//---------------------------------
   
    int number;
    
    int * ptroInt;
    
    int * ptroInt2;
    
    struct coordenadas point;
    
    struct coordenadas * ptroPoint;
    
    printf("number: %lu\n", sizeof(number));
    
    printf("ptroInt: %lu\n", sizeof(ptroInt));
    
    printf("point: %lu\n", sizeof(point));
    
    printf("ptroPoint: %lu\n", sizeof(ptroPoint));
    
    
    
    printf("\nestructura ocupa mas\n");
    printf("los mismos son punteros\n");
    printf("la mitad del valor de estructura: 8\n");
    printf("ptroInt ocupa lo mismo que cualquier puntero (direccion)\n");
    
    printf("\n\nAPARTADO 2\n");
    
    //---------------------------------

    //    APARTADO 2

    //---------------------------------
    
    number = 100;
    
    ptroInt = &number;
    
    *ptroInt = 33;

    
    
    printf("%p\n", ptroInt);
    
    printf("%d\n", *ptroInt);
    
    printf("%p\n", &number);
    
    printf("%d\n", number);
    
    printf("\npodemos ver que las direcciones son iguales como los valores todo eso paso porque ptroInt apunte a number\n");
    
    printf("\n\nAPARTADO 3\n");
    
    //---------------------------------

    //    APARTADO 3

    //---------------------------------
    
    printf("number antes: %d\n\n", number);
    
    func(&number);
    
    printf("\nnumber despues: %d\n", number);
    
    printf("\nse ha cambiado porque en la funcion hicimos paso por referencia y cambiamos direcrtamente el valor del number\n");
    
    printf("\n\nAPARTADO 4\n");
    
    //---------------------------------

    //    APARTADO 4

    //---------------------------------
    
    printf("number antes: %d\n", number);
    
    printf("datos apuntados por ptroInt antes: %d\n\n", *ptroInt);
    
    printf("la dirección a la que apunta ptroInt antes: %p\n\n", ptroInt);

    func(ptroInt);
    
    printf("\nnumber despues: %d\n", number);
    
    printf("datos apuntados por ptroInt despues: %d\n", *ptroInt);
    
    printf("la dirección a la que apunta ptroInt despues: %p \n", ptroInt);
    
    printf("\nSi, se ha cambiado number *ptroInty porque apuntan al mismo dato \n");
    printf("La dirección a la que apunta ptroInt no se ha cambiado porque hemos cambiado solo los datos no la direccion \n");
    
    printf("\n\nAPARTADO 5\n");
    
    //---------------------------------

    //    APARTADO 5

    //---------------------------------
    
    printf("la dirección de memoria donde está almacenado ptroInt2: %p\n", &ptroInt2);
    
    ptroInt2 = (int *)malloc(sizeof(int));
    
    printf("la dirección de memoria donde está almacenado ptroInt2 despues de inicializarlo en malloc: %p\n", &ptroInt2);
    
    printf("que está almacenado en ptroInt2 despues de inicializarlo en malloc: %p\n", ptroInt2);
    
    func(ptroInt2);
    
    printf("valor de ptroInt2: %d\n", *ptroInt2);
    
    return 0;
}

void func(int * numFunc){
    
    
    printf("Introduzca el valor ");
    scanf("%d", numFunc);
    
    
}
