

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct infoPersona{
    char dni[9];
    char nombre[20];
};

struct nodoPersona {
    struct infoPersona informacion;
    struct nodoPersona *siguiente;
    struct nodoPersona *anterior;
};

struct listaPersonas {
    struct nodoPersona *primero;
    struct nodoPersona *ultimo;
};


struct infoVentanilla{
    int numeroVentanilla;
    
    char operacion[20];
    int personasAtendidas;
};

struct nodoVentanilla {
    struct infoVentanilla informacion;
    struct listaPersonas personas; //lista doble de personas en la ventanilla
    struct nodoVentanilla *siguiente;
    struct nodoVentanilla *anterior;
};

struct listaVentanillas {
    struct nodoVentanilla *primero;
    struct nodoVentanilla *ultimo;
};

void crearListaDelistas(struct listaVentanillas *listaVentanillas);

void addNodoVentanilla(struct listaVentanillas *listaVentanillas);

void addNodoPersona(struct listaPersonas *listaPersonas);

int menu(void);

void visualizar(struct nodoVentanilla *primero);

void visualizarPersonas(struct nodoPersona *primero);

int contarPersonasCola(struct nodoPersona *primero);

void visualizarInfoVentanillasNumeroPersonas(struct nodoVentanilla *primero);

void gestionarCambio(struct nodoVentanilla *primero);

struct nodoVentanilla *buscarVentanilla(struct nodoVentanilla *primero, int numVentanillaBuscar);
//вернет нуль если не найдет ничего

struct nodoPersona *buscarPersona(struct nodoPersona *primero, char numDni[]);
//вернет нуль если нет

void eliminarPersonaSinLiberar(struct listaPersonas *lista, struct nodoPersona *personaASacar);

void conectarPersonaAlFinal(struct listaPersonas *lista, struct nodoPersona *personaAnadir);

void atenderPersona(struct nodoVentanilla *primero);

void visualizarVentanillaMasSaturada(struct nodoVentanilla *primero);

void cerrarVentanilla(struct nodoVentanilla *primero);

//волунт
void mostrarPersonasAtendidas(struct nodoVentanilla *primero);

int main(void) {
    struct listaVentanillas listaVentanillas;
    int opc;
    
    crearListaDelistas(&listaVentanillas);
    do {
        opc = menu();
        switch (opc) {
            case 1:
                visualizarInfoVentanillasNumeroPersonas(listaVentanillas.primero);
                break;
            case 2:
                gestionarCambio(listaVentanillas.primero);
                break;
            case 3:
                visualizar(listaVentanillas.primero);
                break;
            case 4:
                atenderPersona(listaVentanillas.primero);
                break;
            case 5:
                visualizarVentanillaMasSaturada(listaVentanillas.primero);
                break;
            case 6:
                cerrarVentanilla(listaVentanillas.primero);
                break;
            case 7:
                mostrarPersonasAtendidas(listaVentanillas.primero);
                break;
            case 0:
                printf("\nSaliendo...\n");
                break;
        }
    } while (opc != 0);
    return 0;
}

int menu(void)
{
    int opc;
    
    do{
        printf("\n1. Visualizar los numeros de ventanillas y el numero de personas a la cola");
        printf("\n2. Realizar un cambio de ventanilla");
        printf("\n3. Visualizar todo");
        printf("\n4. Atender una persona");
        printf("\n5. Visualizar la ventanilla mas saturada");
        printf("\n6. Cerrar ventanilla");
        printf("\n7. Mostrar número de personas atendidas");
        printf("\n0. Salir");
        printf("\nIntroduce la opcion deseada... ");
        scanf("%d", &opc);
    } while ((opc < 0) || (opc > 7));

    return opc;
}


void mostrarPersonasAtendidas(struct nodoVentanilla *primero){
    
    struct nodoVentanilla *recorre = primero;
        
        if (primero == NULL){
            
            printf("\nNo hay ventanillas");
            return;
        }
        
        while(recorre != NULL){
            
            printf("\nVentanilla: %d, personas atendidas: %d, en la cola: %d\n", recorre->informacion.numeroVentanilla,recorre->informacion.personasAtendidas, contarPersonasCola(recorre->personas.primero));
            
            recorre = recorre->siguiente;
        }
    
}


void gestionarCambio(struct nodoVentanilla *primero){
    
    int numeroVentanillaEstas, numeroVentanillaCambiar;
    char dniPersona[9];
    struct nodoVentanilla *ventanillaOrigen, *ventanillaDestino;
    struct nodoPersona *personaCambiar;
    
    printf("Introduce el numero de la ventanilla donde estas:");
    scanf(" %d", &numeroVentanillaEstas);
    ventanillaOrigen = buscarVentanilla(primero, numeroVentanillaEstas);
    
    if (ventanillaOrigen == NULL){
        
        printf("no existe esta ventanilla: %d", numeroVentanillaEstas);
        return;
    }
    
    printf("Introduce tu dni");
    scanf("%s", dniPersona);
    
    personaCambiar = buscarPersona(ventanillaOrigen->personas.primero, dniPersona);
    
    if(personaCambiar == NULL){
        
        printf("no estas en esa cola");
        return;
        
    }
    
    printf("introduce el numero de ventanilla a la que quieres cambiar");
    
    scanf("%d", &numeroVentanillaCambiar);
    
    ventanillaDestino = buscarVentanilla(primero, numeroVentanillaCambiar);
    
    if(ventanillaDestino == NULL){
        
        printf("no existe la ventanilla destino");
        return;
        
    }
    
    eliminarPersonaSinLiberar(&ventanillaOrigen->personas, personaCambiar);
    conectarPersonaAlFinal(&ventanillaDestino->personas, personaCambiar);
    
}

void atenderPersona(struct nodoVentanilla *primero) {
    int numeroVentanilla;
    struct nodoVentanilla *ventanilla;
    struct nodoPersona *personaAtendida;

    printf("Introduce el numero de ventanilla que va a atender: ");
    scanf("%d", &numeroVentanilla);

    ventanilla = buscarVentanilla(primero, numeroVentanilla);

    if (ventanilla == NULL) {
        printf("No existe esa ventanilla.\n");
        return;
    }

    if (ventanilla->personas.primero == NULL) {
        printf("No hay personas en la cola de esa ventanilla.\n");
        return;
    }

    personaAtendida = ventanilla->personas.primero;
    eliminarPersonaSinLiberar(&ventanilla->personas, personaAtendida);

    printf("Persona atendida -> DNI: %s, Nombre: %s\n",
           personaAtendida->informacion.dni,
           personaAtendida->informacion.nombre);
    
    ventanilla->informacion.personasAtendidas++;

    free(personaAtendida);
}

void eliminarPersonaSinLiberar(struct listaPersonas *lista, struct nodoPersona *personaASacar){
    
//    Есть такие варианты
//    единственный в списке
//    первый
//    последний
//    по середине
    
    
    if(lista->primero == personaASacar && lista->ultimo == personaASacar){
        
        lista->primero = NULL;
        lista->ultimo = NULL;
    }else if(lista->primero == personaASacar){
        lista->primero = personaASacar->siguiente;
        lista->primero->anterior = NULL;
    }else if(lista->ultimo == personaASacar){
        lista->ultimo = personaASacar->anterior;
        lista->ultimo->siguiente = NULL;
    }else{
        personaASacar->anterior->siguiente = personaASacar->siguiente;
        personaASacar->siguiente->anterior = personaASacar->anterior;
    }
    
}

void conectarPersonaAlFinal(struct listaPersonas *lista, struct nodoPersona *personaAnadir){
    
    if(lista->primero == NULL){
        
        lista->primero = personaAnadir;
    }else{
        
        lista->ultimo->siguiente=personaAnadir;
        
    }
    
    personaAnadir->anterior =lista->ultimo;
    personaAnadir->siguiente = NULL;
    lista->ultimo = personaAnadir;
}

struct nodoVentanilla *buscarVentanilla(struct nodoVentanilla *primero, int numVentanillaBuscar){
    
    struct nodoVentanilla *recorre = primero;
    
    while((recorre != NULL) && (recorre->informacion.numeroVentanilla != numVentanillaBuscar)){
        
        recorre = recorre->siguiente;
        
    }
    
    return recorre;
}

struct nodoPersona *buscarPersona(struct nodoPersona *primero, char numDni[]){
    
    struct nodoPersona *recorre = primero;

    while((recorre != NULL) && (strcmp(recorre->informacion.dni, numDni))){
        
        recorre = recorre->siguiente;
        
    }
    
    return recorre;
    
}

int contarPersonasCola(struct nodoPersona *primero){
    
    int cont = 0;
    struct nodoPersona *recorre = primero;
    
    while(recorre != NULL){
        cont++;
        recorre = recorre->siguiente;
    }
    
    return cont;
}

void visualizarInfoVentanillasNumeroPersonas(struct nodoVentanilla *primero){
    
    struct nodoVentanilla *recorre = primero;
//    int cont = 0;
    
    while(recorre != NULL){
        
        printf("Ventanilla № %d %s\n", recorre->informacion.numeroVentanilla, recorre->informacion.operacion);
        printf("Numero de las personas en la cola: %d", contarPersonasCola(recorre->personas.primero));
        recorre = recorre->siguiente;
        
    }
    
}

void visualizarPersonas(struct nodoPersona *primero){
    struct nodoPersona *recorre = primero;
    int contador = 1;
    if (primero == NULL){
        printf("\n\t No hay personas a la cola");
        return;
    }
    while (recorre != NULL){
        printf("\n\t %d: dni:%s nombre:%s",contador,recorre->informacion.dni,recorre->informacion.nombre);
        contador += 1;
        recorre = recorre->siguiente;
    }
    printf("\n\n");
}

void visualizar(struct nodoVentanilla *primero){
    struct nodoVentanilla *recorre = primero;
    if (primero == NULL){
        printf("\n Lista de ventanillas vacía");
        return;
    }
    while (recorre != NULL){
        printf("\n Ventanilla n. %d: %s",recorre->informacion.numeroVentanilla,recorre->informacion.operacion);
        visualizarPersonas(recorre->personas.primero);
        recorre = recorre->siguiente;
    }
    
}

void crearListaDelistas(struct listaVentanillas *listaVentanillas) {
    int n, i;
    
    //inicializo la lista
    listaVentanillas->primero = listaVentanillas->ultimo = NULL; //lista vacÌa
    printf("\n Introduce el numero de ventanillas que hay: ");
    scanf("%d", &n);
    
    for (i = 0;i < n; i++) {
        printf("\n Para la ventanilla %d",i+1);
        /***************************
        //LLAMAR A addNodoVentanilla
        ****************************/
        
        addNodoVentanilla(listaVentanillas);
    }
}

void addNodoVentanilla(struct listaVentanillas *listaVentanillas) {
    //aÒado por el final
    struct nodoVentanilla *nuevo;
    int numPersonas, i;
    
    //1. reservo
    nuevo = (struct nodoVentanilla *)malloc(sizeof(struct nodoVentanilla));
    if (nuevo == NULL) {
        printf("\n ERROR de memoria");
        return;
    }
    
    //2. relleno
    printf("\n Introduce la informacion del numero de la ventanilla: ");
    scanf("%d", &nuevo->informacion.numeroVentanilla);
    printf("\n Introduce la operacion de la ventanilla: ");
    fflush(stdin);
    fpurge(stdin);
    scanf("%s", nuevo->informacion.operacion);
    //tb relleno las personas
    printf("\n Introduce el numero de personas: ");
    scanf("%d", &numPersonas);
    
    nuevo->informacion.personasAtendidas = 0;
    
    //    в первую очередь нужно инициализировать пустой список людей
//    listaVentanillas->ultimo->personas.primero = NULL;
//    listaVentanillas->ultimo->personas.ultimo = NULL;
    nuevo->personas.primero = nuevo->personas.ultimo = NULL;
    for (i=0; i < numPersonas; i++){
        
        addNodoPersona(&nuevo->personas);
        
    }
    
    //3. Conecto con  la lista
    if (listaVentanillas->primero == NULL) {
        //lista vacia aÒado el primero
        listaVentanillas->primero = nuevo;
    }
    else {//no esta vacÌa, va despues del ultimo
        listaVentanillas->ultimo->siguiente = nuevo;
    }
    nuevo->siguiente = NULL;
    nuevo->anterior = listaVentanillas->ultimo;
    listaVentanillas->ultimo = nuevo;
}

void addNodoPersona(struct listaPersonas *listaPersonas) {
    struct nodoPersona *nuevo;
    //1. Reservo
    nuevo = (struct nodoPersona *)malloc(sizeof(struct nodoPersona));
    if (nuevo == NULL) {
        printf("\n ERROR de memoria");
        return;
    }
    
    //2.Relleno
    printf("\n DNI de la persona: ");
    fflush(stdin);
    fpurge(stdin);
    scanf("%s", nuevo->informacion.dni);
    printf("\n Nombre de la persona: ");
    fflush(stdin);
    fpurge(stdin);
    scanf("%s", nuevo->informacion.nombre);
    
    //3. Conecto
    if (listaPersonas->primero == NULL) {
        //lista vacia anado el primero
        listaPersonas->primero = nuevo;
    }
    else {//no esta vacÌa, va despues del ultimo
        listaPersonas->ultimo->siguiente = nuevo;
    }
    nuevo->siguiente = NULL;
    nuevo->anterior = listaPersonas->ultimo;
    listaPersonas->ultimo = nuevo;
}

void visualizarVentanillaMasSaturada(struct nodoVentanilla *primero) {
    struct nodoVentanilla *recorre;
    struct nodoVentanilla *masSaturada;
    int maxPersonas, personasActuales;
    
    if (primero == NULL) {
        printf("\nNo hay ventanillas\n");
        return;
    }
    
    masSaturada = primero;
    maxPersonas = contarPersonasCola(primero->personas.primero);
    
    recorre = primero->siguiente;
    
    while (recorre != NULL) {
        personasActuales = contarPersonasCola(recorre->personas.primero);
        
        if (personasActuales > maxPersonas) {
            maxPersonas = personasActuales;
            masSaturada = recorre;
        }
        
        recorre = recorre->siguiente;
    }
    
    printf("\nLa ventanilla mas saturada: %d", masSaturada->informacion.numeroVentanilla);
    printf("\nTiene %d personas\n", maxPersonas);
    
}

void cerrarVentanilla(struct nodoVentanilla *primero) {
    int numeroVentanilla;
    struct nodoVentanilla *ventanilla;
    struct nodoPersona *personaEliminar;

    printf("\nIntroduce el numero de ventanilla: ");
    scanf("%d", &numeroVentanilla);

    ventanilla = buscarVentanilla(primero, numeroVentanilla);

    if (ventanilla == NULL) {
        printf("\nNo existe la ventanilla\n");
        return;
    }

    if (ventanilla->personas.primero == NULL) {
        printf("\nNo hay personas en la cola");
        return;
    }

    while (ventanilla->personas.primero != NULL) {
        personaEliminar = ventanilla->personas.primero;
        eliminarPersonaSinLiberar(&ventanilla->personas, personaEliminar);
        free(personaEliminar);
    }

    printf("\nLa cola de la ventanilla %d esta eliminada\n", numeroVentanilla);
}

