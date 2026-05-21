//
//  main.c
//  practica5
//
//  Created by Administrador on 11/3/26.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tipoFecha {
    
    int dia;
    int mes;
    int ano;
    
};

struct tipoInfo {
    
    char idUser[21];
    char text[21];
    struct tipoFecha fecha;
    
};

struct nodo{
    
    struct tipoInfo info;
    struct nodo * anterior;
    struct nodo * siguiente;
    
};

struct listaDoble{
    
    struct nodo *primero;
    struct nodo *ultimo;
    
};

void mostrarMenu(void);
void newTweet(struct listaDoble * lista);
int compararFechas(struct tipoFecha fNueva, struct tipoFecha fLista);
void mostrarTodo(struct listaDoble lista);
void mostrarTweet(struct listaDoble lista);
void mostrarTodoUsuario(struct listaDoble lista);
void newTweetNoOrdenada(struct listaDoble * lista);

int main(int argc, const char * argv[]) {
    
    int opc;
    struct listaDoble lista;
    lista.primero = NULL;
    lista.ultimo = NULL;
    
    do{
        mostrarMenu();
        printf("\n\n\tElige la opcion:");
        scanf("%d", &opc);
        
        switch(opc){
                
            case 1:
                newTweetNoOrdenada(&lista);
                break;
            case 2:
                mostrarTweet(lista);
                break;
                
            case 3:
                mostrarTodoUsuario(lista);
                break;
                
            case 4:
                newTweet(&lista);
                break;
                
            case 5:
                mostrarTodo(lista);
                break;
            default:
                printf("\n\tOpcion no valida\n");
                
        }
        
    }while (opc != 0);
    
    
    
    return 0;
}

//если выдает 1 значит добавляемая дата свежее, чем существующая
int compararFechas(struct tipoFecha fNueva, struct tipoFecha fLista){
    
    if (fNueva.ano != fLista.ano)
        return fNueva.ano > fLista.ano;
    
    if (fNueva.mes != fLista.mes)
        return fNueva.mes > fLista.mes;
    
    return fNueva.dia > fLista.dia;
}





void newTweet(struct listaDoble * lista){
    
    struct nodo * nuevo = malloc(sizeof(struct nodo));
    struct nodo * current = lista->ultimo;
    
    if (nuevo == NULL){
        
        printf("ERROR DE MEMORIA");
        return;
    }
    
    printf("\n\t Introduce el id: ");
    scanf(" %20[^\n]", nuevo->info.idUser);

    printf("\n\t Introduce el texto: ");
    scanf(" %20[^\n]", nuevo->info.text);
    
    printf("\n\t Introduce el ano: ");
    scanf("%d", &nuevo->info.fecha.ano);
    printf("\n\t Introduce el mes: ");
    scanf("%d", &nuevo->info.fecha.mes);
    printf("\n\t Introduce el dia: ");
    scanf("%d", &nuevo->info.fecha.dia);
    
    if (lista->primero == NULL){
        
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;
        lista->primero = nuevo;
        lista->ultimo = nuevo;
        
    
//        тут у нас проверка если новая дата свежее старой то мы ее кидаем вправо
    }else if(compararFechas(nuevo->info.fecha, current->info.fecha) == 1){
        
        nuevo->siguiente = NULL;
        nuevo->anterior = current;
        current->siguiente = nuevo;
        lista->ultimo = nuevo;
//        самое важное последнее это же якорь!!!
        
    }else{
        
            
        
        
//        если мы получаем 1 в функции значит новая дата является свежее
        while(current->anterior != NULL && compararFechas(nuevo->info.fecha,  current->anterior->info.fecha) != 1){
            
            current = current->anterior;
            
            
        }
        
        if (current->anterior == NULL){
            
            nuevo->anterior = NULL;
            nuevo->siguiente = current;
            current->anterior = nuevo;
            lista->primero = nuevo;
            
        }else{
            
            nuevo->anterior = current->anterior;
            nuevo->siguiente = current;
            current->anterior = nuevo;
            nuevo->anterior->siguiente = nuevo;
            
            
        }
        
        

        
        
        
//        nuevo->siguiente = NULL;
//        nuevo->anterior = lista->ultimo;
//        lista->ultimo->siguiente = nuevo;
//        lista->ultimo = nuevo;
        
        
    }
    
}


void newTweetNoOrdenada(struct listaDoble * lista){
    
    struct nodo * nuevo = malloc(sizeof(struct nodo));
    
    if (nuevo == NULL){
        
        printf("ERROR DE MEMORIA");
        return;
    }
    
    printf("\n\t Introduce el id: ");
    scanf(" %20[^\n]", nuevo->info.idUser);

    printf("\n\t Introduce el texto: ");
    scanf(" %20[^\n]", nuevo->info.text);
    
    
    printf("\n\t Introduce el ano: ");
    scanf("%d", &nuevo->info.fecha.ano);
    printf("\n\t Introduce el mes: ");
    scanf("%d", &nuevo->info.fecha.mes);
    printf("\n\t Introduce el dia: ");
    scanf("%d", &nuevo->info.fecha.dia);
    
    nuevo->siguiente = NULL;
    
    if (lista->primero == NULL){
        
        nuevo->anterior = NULL;
        lista->primero = nuevo;
        lista->ultimo = nuevo;
        
    }else{
        
        nuevo->anterior = lista->ultimo;
        lista->ultimo->siguiente = nuevo;
        lista->ultimo = nuevo;
        
    }
}

void mostrarTodo(struct listaDoble lista){
    
    struct nodo * current = lista.primero;
    
    if(lista.primero == NULL){
        
        printf("La lista esta vacia");
        return;
        
    }
    
    while(current != NULL){
        
        printf("\n\tlogin: %s fecha: %d/%d/%d contenido: %s",current->info.idUser,current->info.fecha.dia,current->info.fecha.mes,current->info.fecha.ano,current->info.text);
        
        current = current->siguiente;
        
    }
}

void mostrarTweet(struct listaDoble lista){
    
    struct nodo * current = lista.ultimo;
    char logBusc[21];
    
    if(current == NULL){
        
        printf("no hay usuarios registrados");
        return;
        
    }
    
    printf("\n\t Introduce el login del usuario  ");
    scanf(" %20[^\n]", logBusc);
    
    while(current != NULL && strcmp(current->info.idUser, logBusc) != 0){
        
        current = current->anterior;
        
    }
    
    if(current == NULL){
        
        printf("El usuario %s no ha participado en la red",logBusc);
        
    }else{
        
        printf("\n\tla ultima entrada: \n\t\t %d/%d/%d  login:%s  text:%s", current->info.fecha.dia,current->info.fecha.mes,current->info.fecha.ano,current->info.idUser, current->info.text);
        
    }
}

void mostrarTodoUsuario(struct listaDoble lista){
    
    struct nodo * current = lista.ultimo;
    char logBusc[21];
    int e = 0;
    
    if(current == NULL){
        
        printf("no hay usuarios registrados");
        return;
        
    }
    
    printf("\n\t Introduce el login del usuario  ");
    scanf(" %20[^\n]", logBusc);
    
    while(current != NULL){
        
        if(strcmp(current->info.idUser, logBusc) == 0){
            e = 1;
            printf("\n\t\t %d/%d/%d  login:%s  text:%s", current->info.fecha.dia,current->info.fecha.mes,current->info.fecha.ano,current->info.idUser, current->info.text);
            
        }
        
        current = current->anterior;
        
        
    }
    
    if(e == 0){
        
        printf("El usuario %s no ha participado en la red",logBusc);
        
        
    }
    
}


void mostrarMenu(void){
    
    printf("\n\t**************MENU****************\n");
    printf("\n\t1.Añadir un tweet.");
    printf("\n\t2.Mostrar el último tweet de un usuario");
    printf("\n\t3.Visualizar los tweets de un usuario");
    printf("\n\t4.Añadir un tweet para una fecha concreta");
    printf("\n\t0. Salir");
    
}
