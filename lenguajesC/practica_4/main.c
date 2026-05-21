#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tipoInfo {
    char login[21];
    char codigoProd[21];
    int unidades;
    float importe;
};

struct tipoNodo {
    struct tipoInfo info;
    struct tipoNodo *siguiente;
};

int menu(void);


void RealizarCompra(struct tipoNodo **primero);
void MostrarUltimaCompra(struct tipoNodo *primero);
void AnularUltimaCompra(struct tipoNodo **primero);
void VisualizarCompras(struct tipoNodo *primero);
void LiberarLista(struct tipoNodo *primero);

int main(void) {
    
    int opc;
    struct tipoNodo *primero = NULL;
    
    do {
        opc = menu();
        
        switch(opc) {
                
            case 1:
                RealizarCompra(&primero);
                break;
                
            case 2:
                MostrarUltimaCompra(primero);
                break;
                
            case 3:
                AnularUltimaCompra(&primero);
                break;
                
            case 4:
                VisualizarCompras(primero);
                break;
                
            case 0:
                printf("\nSaliendo...\n");
                break;
        }
        
    } while (opc != 0);
    
    LiberarLista(primero);
    
    return 0;
}

int menu(void) {
    
    int opc;
    
    do {
        printf("\n\n**************MENU****************\n");
        printf("\n\t1. Realizar compra");
        printf("\n\t2. Mostrar la ultima compra de un usuario");
        printf("\n\t3. Anular ultima compra de un usuario");
        printf("\n\t4. Visualizar las compras de un usuario");
        printf("\n\t0. Salir");
        printf("\n\n\tIntroduce una opcion: ");
        scanf("%d", &opc);
        
    } while ((opc < 0) || (opc > 4));
    
    return opc;
}

void RealizarCompra(struct tipoNodo **primero) {
    
    struct tipoNodo *nuevo;
    struct tipoNodo *current;
    struct tipoNodo *anterior;
    
    nuevo = malloc(sizeof(struct tipoNodo));
    
    if (nuevo == NULL) {
        printf("\nERROR DE MEMORIA");
        return;
    }
    
    printf("\nIntroduce su login: ");
    scanf("%20s", nuevo->info.login);
    
    printf("Introduce el codigo del producto: ");
    scanf("%20s", nuevo->info.codigoProd);
    
    printf("Introduce el numero de unidades: ");
    scanf("%d", &nuevo->info.unidades);
    
    printf("Introduce el importe: ");
    scanf("%f", &nuevo->info.importe);
    
    current = *primero;
    anterior = NULL;
    
    while (current != NULL && strcmp(current->info.login, nuevo->info.login) < 0) {
        anterior = current;
        current = current->siguiente;
    }
    
    if (current != NULL && strcmp(current->info.login, nuevo->info.login) == 0) {
        
        while (current->siguiente != NULL && strcmp(current->siguiente->info.login, nuevo->info.login) == 0) {
            current = current->siguiente;
        }
        
//        добираемся до последнего и встаем после
        nuevo->siguiente = current->siguiente;
        current->siguiente = nuevo;
        
    } else {
//        вот это варик когда мы не нашли логин
        
        nuevo->siguiente = current;
        
        if (anterior == NULL) {
//            это когда мы не сдвинулись по сути
            
            *primero = nuevo;
        } else {
            anterior->siguiente = nuevo;
        }
    }
    
    printf("\nCompra anadida correctamente\n");
}

void MostrarUltimaCompra(struct tipoNodo *primero) {
    
    char logBusc[21];
    struct tipoNodo *current = primero;
    struct tipoNodo *ultima = NULL;
    
    printf("\nIntroduce el login del usuario: ");
    scanf("%20s", logBusc);
    
    while (current != NULL) {
        
        if (strcmp(current->info.login, logBusc) == 0) {
            ultima = current;
        }
        
        current = current->siguiente;
    }
    
    if (ultima == NULL) {
        printf("\nEl usuario %s no ha realizado ninguna compra\n", logBusc);
    } else {
        printf("\nUltima compra de %s:", logBusc);
        printf("\nCodigo producto: %s", ultima->info.codigoProd);
        printf("\nUnidades: %d", ultima->info.unidades);
        printf("\nImporte: %.2f\n", ultima->info.importe);
    }
}

void AnularUltimaCompra(struct tipoNodo **primero) {
    
    char logBusc[21];
    struct tipoNodo *current = *primero;
    struct tipoNodo *anterior = NULL;
    struct tipoNodo *ultima = NULL;
    struct tipoNodo *anteriorUltima = NULL;
    
    printf("\nIntroduce el login del usuario: ");
    scanf("%20s", logBusc);
    
    while (current != NULL) {
        
        if (strcmp(current->info.login, logBusc) == 0) {
            ultima = current;
            anteriorUltima = anterior;
        }
        
        anterior = current;
        current = current->siguiente;
    }
    
    if (ultima == NULL) {
        printf("\nEl usuario %s no ha realizado ninguna compra\n", logBusc);
        return;
    }
    
    printf("\nCompra eliminada:");
    printf("\nCodigo producto: %s", ultima->info.codigoProd);
    printf("\nUnidades: %d", ultima->info.unidades);
    printf("\nImporte: %.2f\n", ultima->info.importe);
    
    if (anteriorUltima == NULL) {
        *primero = ultima->siguiente;
    } else {
        anteriorUltima->siguiente = ultima->siguiente;
    }
    
    free(ultima);
}

void VisualizarCompras(struct tipoNodo *primero) {
    
    char logBusc[21];
    struct tipoNodo *current = primero;
    int encontrado = 0;
    
    printf("\nIntroduce el login del usuario: ");
    scanf("%20s", logBusc);
    
    while (current != NULL) {
        
        if (strcmp(current->info.login, logBusc) == 0) {
            encontrado = 1;
            printf("\nCodigo producto: %s  Unidades: %d  Importe: %.2f",
                   current->info.codigoProd,
                   current->info.unidades,
                   current->info.importe);
        }
        
        current = current->siguiente;
    }
    
    if (encontrado == 0) {
        printf("\nEl usuario %s no ha realizado ninguna compra", logBusc);
    }
    
    printf("\n");
}

void LiberarLista(struct tipoNodo *primero) {
    
    struct tipoNodo *aux;
    
    while (primero != NULL) {
        aux = primero;
        primero = primero->siguiente;
        free(aux);
    }
}
