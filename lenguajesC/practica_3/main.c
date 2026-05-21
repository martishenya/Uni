

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct tipoInfo{
    
    char login[21];
    char nombre[31];
    char contrasena[17];
    
};


struct tipoNodo{
    
    struct tipoInfo usuario;
    struct tipoNodo *siguiente;
    
};



void registrar(struct tipoNodo ** primero);

struct tipoNodo * encontrarLogin(struct tipoNodo * primero, char logIntro[]);

void mostrarUsuario(struct tipoNodo * primero);

void mostrarTodos(struct tipoNodo * primero);

void cambiarContrasena(struct tipoNodo ** primero);


int menu(void);

int main(int argc, const char * argv[]) {
    
    struct tipoNodo *primero = NULL; //lista vacía
    
    int opc;
    
    do{
        opc = menu();
        
        switch (opc) {
            case 1:
                
                registrar(&primero);
 
                break;
            case 2:
                
                mostrarUsuario(primero);
                
                break;
            case 3:
                
                mostrarTodos(primero);
                
                break;
            case 4:
               
                cambiarContrasena(&primero);
                
                break;
            default:
                break;
        }
        
    }while (opc != 0);
    
    

    
    return 0;
}



void registrar(struct tipoNodo ** primero){
    
    struct tipoNodo *nuevo;
    
    struct tipoNodo *loginEncontrado;
    
    nuevo = (struct tipoNodo *)malloc(sizeof(struct tipoNodo));
    
    if (nuevo == NULL){
        
        printf("\n\tError de la memoria");
        
        return;
        
    }
    
    
    do{
        
        printf("\n\n\tIntroduce el login nuevo: ");
        scanf("%s", nuevo->usuario.login);
        
        loginEncontrado = encontrarLogin(*primero, nuevo->usuario.login);
        
        if (loginEncontrado != NULL){
            
            printf("\n\n\tEste login ya esta ocupado!");
            
        }
        else{
            
            printf("\n\n\tIntroduce su nombre: ");
            scanf("%s", nuevo->usuario.nombre);
            printf("\n\n\tIntroduce la contrasena: ");
            scanf("%s", nuevo->usuario.contrasena);
            
        }
        
    }while(loginEncontrado != NULL);
    
    
    
    
    
    
    
    
    nuevo->siguiente = *primero;
    *primero = nuevo;
    
    
}

struct tipoNodo * encontrarLogin(struct tipoNodo * primero, char logIntro[]){
    
    struct tipoNodo *current;
    
    current = primero;
        
        while(current != NULL){
            
            if(strcmp(current->usuario.login, logIntro) == 0){
                
                return current;
                break;
                
            }
            else{
                
                current = current->siguiente;
                
            }
            
        }
        
        return NULL;
    
}

void mostrarUsuario(struct tipoNodo * primero){
    
    struct tipoNodo *loginEncontrado;
    char logToFind[21];
    
    if (primero == NULL ){
        
        printf("\n\tNo hay usuarios registrados");
        return ;
        
    }
    else{
        
        
        
        printf("\n\n\tIntroduce el login para ver su info: ");
        scanf("%s", logToFind);
        
        loginEncontrado = encontrarLogin(primero, logToFind);
        
        if(loginEncontrado == NULL){
            
            printf("\n\n\tNo existe este usuario");
            
        }
        else{
            
            printf("\n\n\tNombre: %s \n\tContrasena: %s\n", loginEncontrado->usuario.nombre, loginEncontrado->usuario.contrasena);
            
        }
    }
}

void mostrarTodos(struct tipoNodo * primero){
    
    struct tipoNodo * current = primero;
    
    
    
    if (current == NULL){
        
        printf("\n\n\tNo hay usuarios");
        return;
        
    }
    else{
        
        while (current != NULL){
            
            printf("\n\n\tLogin: %s ", current->usuario.login);
            
            current = current->siguiente;
            
        }
        
    }
    
}

void cambiarContrasena(struct tipoNodo ** primero){
    
    char logToFind[21];
    
    struct tipoNodo *loginEncontrado;
    
    char contrasenaComprobar[17];
    char contrasenaComprobar2[17];
    
    
    if (*primero == NULL ){
        
        printf("\n\n\tNo hay usuarios registrados");
        return;
        
    }
    else{
        
        printf("\n\n\tIntroduce el login ");
        scanf("%s", logToFind);
        
        loginEncontrado = encontrarLogin(*primero, logToFind);
        
        if(loginEncontrado == NULL){
            
            printf("\n\n\tNo existe este usuario");
            return;
            
        }
        else{
            
            do{
                
                printf("\n\n\tIntroduce la contrasena: ");
                scanf("%s", contrasenaComprobar);
                
                if(strcmp(loginEncontrado->usuario.contrasena, contrasenaComprobar) != 0){
                    
                    printf("\n\n\tContrasena es incorrecta! Pruebe de nuevo.. ");
                    continue;
                    
                }
                
            }while(strcmp(loginEncontrado->usuario.contrasena, contrasenaComprobar) != 0);
            
            printf("\n\n\tContrasena es correcta!");
            
            printf("\n\n\tIntroduce la contrasena nueva: ");
            
            scanf("%s", contrasenaComprobar);
            
            do{
                
                printf("\n\n\tIntroduce la contrasena nueva otra vez: ");
                
                scanf("%s", contrasenaComprobar2);
                
                if (strcmp(contrasenaComprobar, contrasenaComprobar2) != 0){
                    
                    printf("\n\tILas contrsenas nuevas introducidas no coinciden");
                    continue;
                    
                }
                
            }while(strcmp(contrasenaComprobar, contrasenaComprobar2) != 0);
            
            strcpy(loginEncontrado->usuario.contrasena, contrasenaComprobar);
            
            printf("\n\n\tTodo correcto, la contrasena esta reemplazada!");
            
            
            
            
        }
    }
}
    


int menu(void){
    int opc;
    do{
        printf("\n\n**************MENU****************\n");
        printf("\n\t1.Registrarse");
        printf("\n\t2.Visualizar información sobre un usuario.");
        printf("\n\t3.Visualizar todos los usuarios");
        printf("\n\t4.Cambiar contraseña");

        printf("\n\t0.Salir");
        printf("\n\n\tIntroduce una opción: ");
        scanf("%d",&opc);
        
    }while ((opc<0) || (opc>4));
    return opc;
}
