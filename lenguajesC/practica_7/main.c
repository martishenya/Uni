

#include <stdio.h>
#include <string.h>

struct datosFecha
{
   int dia;
   int mes;
   int anno;
};

struct datosCompra
{
    char nombre[40];//nombre de la compañía
    int numero; //número de acciones
    struct datosFecha fecha; //fecha de compra
    double precio; //precio de compra
};



int menu(void);

void volcar (char origen[],char destino[]);


void leerFicheroBinario(char nf[]);

void anadirCompraAFichero(char nf[]);

void visualizarTotales(char nf[]);

void modificarNumerosEnCompaniaFecha(char nf[]);

void vizualizarUltimaCompra(char nf[]);

void eliminarComprasCompania(char nf[]);




int main(void)
{
    int opc;

    do
    {
        opc = menu();
        switch (opc)
        {
        case 1: ;
                visualizarTotales("acciones.dat");
                break;
        case 2:
                anadirCompraAFichero("acciones.dat");
                break;
        case 3:leerFicheroBinario("acciones.dat");
                break;
        case 4:
                modificarNumerosEnCompaniaFecha("acciones.dat");
                break;
        case 5:
                vizualizarUltimaCompra("acciones.dat");
                break;
        case 6:
                eliminarComprasCompania("acciones.dat");
                break;
        }
    }while(opc != 0);

    return 0;
}
    





void volcar (char origen[],char destino[])
{
    struct datosCompra reg;
    FILE * fori,*fdes;

    fori = fopen(origen,"rb");
    fdes = fopen(destino,"wb");

    if ( (fori == NULL) || (fdes == NULL) ){
        printf("\n Error en la apertura");
        return;
    }
   
    fread(&reg,sizeof(struct datosCompra),1,fori);
    while (!feof(fori))
    {
        fwrite(&reg,sizeof(struct datosCompra),1,fdes);
        fread(&reg,sizeof(struct datosCompra),1,fori);
    }
    fclose(fori);
    fclose(fdes);
    remove(origen);
}


int menu(void)
{
    int opc;
    do
    {
        printf("\n 1. Visualizar las acciones por compañia");
        printf("\n 2. Añadir una compra");
        printf("\n 3. Visualizar Fichero");
        printf("\n 4. Modificar las acciones por nombre y fecha");
        printf("\n 5. Visualizar la ultima compra de una compania");
        printf("\n 6. Eliminar todas las compras de compania");
        printf("\n 0. Salir");

        printf("\n Introduce una opción: ");
        scanf("%d",&opc);
    }while ( (opc <0) || (opc>6) );
    return opc;
}


void leerFicheroBinario(char nom[])
{
    FILE *f;
    struct datosCompra reg;
    

    f = fopen(nom,"rb");
    if (f == NULL){
        printf("\n Error en la apertura del fichero");
        return;
    }
    fread(&reg, sizeof(struct datosCompra), 1, f);

    while (!feof(f))
    {
        printf("\n %s \tNumero: %d, \tPrecio: %.2lf \tFecha: [%d/%d/%d]",reg.nombre,reg.numero,reg.precio,reg.fecha.dia,reg.fecha.mes,reg.fecha.anno);
        fread(&reg, sizeof(struct datosCompra), 1, f);
    }
    fclose(f);
}

void anadirCompraAFichero(char nf[]){
    
    FILE *f, *faux;
    
    struct datosCompra regNuevo, reg;
    
    f = fopen(nf, "rb");
    
    faux = fopen("borrarLuego", "wb");
    
    if (f==NULL || faux==NULL){
        
        printf("Error en la apertura del fichero");
        return;
        
    }
    
    printf("\nIntroduce el nombre: ");
    scanf(" %s",regNuevo.nombre);
    
    printf("\nIntroduce el numero de acciones: ");
    scanf(" %d",&regNuevo.numero);
    
    printf("\nIntroduce el precio: ");
    scanf(" %lf",&regNuevo.precio);
    
    printf("\nIntroduce el anno: ");
    scanf(" %d",&regNuevo.fecha.anno);
    
    printf("\nIntroduce el mes: ");
    scanf(" %d",&regNuevo.fecha.mes);
    
    printf("\nIntroduce el dia: ");
    scanf(" %d",&regNuevo.fecha.dia);
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    while(!feof(f) && strcmp(reg.nombre, regNuevo.nombre) <= 0){
        
        fwrite(&reg, sizeof(struct datosCompra), 1, faux);
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    fwrite(&regNuevo, sizeof(struct datosCompra), 1, faux);
    
    while(!feof(f)){
        
        fwrite(&reg, sizeof(struct datosCompra), 1, faux);
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    fclose(f);
    fclose(faux);
    
    volcar("borrarLuego", nf);
    
    remove("borrarLuego");
    
}

void visualizarTotales(char nf[]){
    
    FILE *f;
    struct datosCompra reg;
    
    int numeroAcciones = 0;
    char nombreCompania[40];
    
    f = fopen(nf, "rb");
    
    if(f == NULL){
        
        printf("ERROR DE FICHERO");
        return;
        
    }
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    if(!feof(f)){
        
        strcpy(nombreCompania, reg.nombre);
        numeroAcciones = reg.numero;
        
    }
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    while(!feof(f)){
        
        if(strcmp(reg.nombre, nombreCompania) == 0){
            
            numeroAcciones = numeroAcciones + reg.numero;
            
        }else{
            
            printf("\n%s total comprado %d\n", nombreCompania, numeroAcciones);
            strcpy(nombreCompania, reg.nombre);
            numeroAcciones = reg.numero;
            
            
        }
        
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    printf("\n%s total comprado %d\n", nombreCompania, numeroAcciones);
    fclose(f);
    
}

void modificarNumerosEnCompaniaFecha(char nf[]){
    
    FILE *f, *faux;
    
    struct datosCompra reg, regNuevo;
    
    f = fopen(nf, "rb");
    faux = fopen("aux", "wb");
    
    if(f == NULL || faux == NULL){
        
        printf("\nERROR DE APERTURA");
        return;
        
    }
    
    printf("\nIntroduce el nombre de compania que quieres modificar: ");
    scanf("%s",regNuevo.nombre);
    printf("\nIntroduce el anno de compania que quieres modificar: ");
    scanf("%d",&regNuevo.fecha.anno);
    printf("\nIntroduce el mes de compania que quieres modificar: ");
    scanf("%d",&regNuevo.fecha.mes);
    printf("\nIntroduce el dia de compania que quieres modificar: ");
    scanf("%d",&regNuevo.fecha.dia);
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    while(!feof(f) && (strcmp(reg.nombre, regNuevo.nombre)!= 0 || reg.fecha.anno != regNuevo.fecha.anno || reg.fecha.mes != regNuevo.fecha.mes || reg.fecha.dia != regNuevo.fecha.dia  )){
        
        fwrite(&reg, sizeof(struct datosCompra), 1, faux);
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    if(feof(f)){
        
        printf("\nNo hay compania de ese nombre y fecha");
        
//        важно закрыть ваще
        fclose(f);
        fclose(faux);
        remove("aux");
        
        return;
    }
        
        printf("\nIntroduce el numero de acciones para modificar: ");
        scanf("%d",&regNuevo.numero);
        
        reg.numero = regNuevo.numero;
    
    while(!feof(f)){
        
        fwrite(&reg, sizeof(struct datosCompra), 1, faux);
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    
    fclose(f);
    fclose(faux);
    
    volcar("aux", nf);
    
    remove("aux");
}

//Visualizar la última compra de una compañía. Para ello se introducirá el nombre de
//la compañía y se visualizará la última compra realizada (la última de las guardadas
//para esa compañía). En caso de no haber comprado para esa compañía se indicará
//mediante un mensaje.

void vizualizarUltimaCompra(char nf[]){
    
    FILE *f;
    
    struct datosCompra reg, regUltimo;
    
    int check = 0;
    
    char nombre[40];
    
    
    
    f = fopen(nf, "rb");
    
    if(f==NULL){
        
        printf("\nERROR DE APERTURA");
        return;
        
    }
    
    printf("\nIntroduce el nombre de compania para mostrar su ultima compra: ");
    scanf(" %39s",nombre);
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    
    ////////////////////////////////////PARA EL CASO CUANDO FECHAS ESTAN ORDENADAS AL REVES//////////////////////////////////////////////
//    while(!feof(f) && strcmp(reg.nombre, nombre)!=0){
//
//
//        fread(&reg, sizeof(struct datosCompra), 1, f);
//    }
//
//    if(feof(f)){
//
//        printf("\nNo hay esta compania en la lista..");
//        fclose(f);
//        return;
//
//    }
//
//    regUltimo = reg;
//
//    while(!feof(f)){
//
//        fread(&reg, sizeof(struct datosCompra), 1, f);
//
//    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    
    while(!feof(f)){
        
        if(strcmp(reg.nombre, nombre)==0){
            
            regUltimo = reg;
            check = 1;
            
        }
        fread(&reg, sizeof(struct datosCompra), 1, f);
    }
    
    if(check == 0){
        
        printf("\nNo hay esta compania en la lista..");
        fclose(f);
        return;
        
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    printf("Ultima compra de compania %s fue realizada: %d/%d/%d con numero de acciones: %d y precio: %lf", regUltimo.nombre,  regUltimo.fecha.dia, regUltimo.fecha.mes, regUltimo.fecha.anno, regUltimo.numero, regUltimo.precio);
    
    fclose(f);
}


void eliminarComprasCompania(char nf[]){
    
    FILE *f, *faux;
    
    struct datosCompra reg;
    
    char nombre[40];
    
    f = fopen(nf, "rb");
    
    faux = fopen("aux", "wb");
    
    if(f == NULL || faux == NULL){
        
        printf("\nERROR DE APERTURA");
        return;
        
    }
    
    printf("\nIntroduce el nombre de compania para eliminar sus compras: ");
    scanf(" %39s",nombre);
    
    fread(&reg, sizeof(struct datosCompra), 1, f);
    
    
    while(!feof(f)){
        
        if(strcmp(reg.nombre, nombre)!=0){
            
            fwrite(&reg, sizeof(struct datosCompra), 1, faux);
            
        }
        
        fread(&reg, sizeof(struct datosCompra), 1, f);
        
    }
    
    fclose(f);
    fclose(faux);
    
    volcar("aux", nf);
    
    remove("aux");
    
}
