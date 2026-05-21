//
//  main.c
//  practica7FicherosBinarios
//
//


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct datosAlumno
{
    int nExp; //número de expediente del alumno
    char nombre[50]; //nombre del alumno
    char apellidos[100]; //apellidos de alumno
};

struct datosAsignatura
{
    int codigo; //código de la asignatura
    char nombreAsig[40]; //nombre de la asignatura
    int curso; //curso en que se imparte
};
struct datosMatriculado
{
    int nExp; //número de expediente del alumno matriculado
    int codigo; //código de la asignatura
    
};

void volcarAlumn(char nombreOrigen[], char nombreDestino[]);

void visualizarAlumnos(char nombre[]);
void visualizarAsignaturas(char nombre[]);
void visualizarMatriculados(char nombre[]);

void visualizarInfoDeAlumno(char nf[]);
void visualizarInfoDeAsignatura(char nf[]);
void anadirAlumno(char nf[]);

void eliminarAlumno(char nfAlumn[], char nfMatr[]);

void generarFicheroDeTexto(char nfAlumn[], char nfAsign[], char nfMatr[]);

void matricularAlumno(char nfAlumn[], char nfAsign[], char nfMatr[]);

int menu(void);

int main(void)
{
    int opc;
    
    do{
        opc = menu();
        switch (opc)
        {
            case 1:visualizarAlumnos("alumnos.bin");
                break;
            case 2: visualizarAsignaturas("asignaturas.bin");
                break;
            case 3: visualizarMatriculados("matriculados.bin");
                break;
            case 4:
                visualizarInfoDeAlumno("alumnos.bin");
                break;
            case 5:
                visualizarInfoDeAsignatura("asignaturas.bin");
                break;
            case 6:
                anadirAlumno("alumnos.bin");
                break;
            case 7:
                generarFicheroDeTexto("alumnos.bin", "asignaturas.bin", "matriculados.bin");
                break;
            case 8:
                eliminarAlumno("alumnos.bin", "matriculados.bin");
                break;
            case 9:
                matricularAlumno("alumnos.bin", "asignaturas.bin", "matriculados.bin");
                break;
            default:
                break;
        }
    } while (opc != 0);
    return 1;
}

int menu(void) {
    int opc;
    do {
        printf("\n1. Visualizar fichero alumnos");
        printf("\n2. Visualizar fichero asignaturas");
        printf("\n3. Visualizar fichero matriculados");
        
        printf("\n4. Visualizar la información de un alumno");
        printf("\n5. Visualizar la información de una asignatura");
        printf("\n6. Añadir un alumno");
        printf("\n7. Generar un fichero de texto");
        
        printf("\n8. Eliminar un alumno");
        
        printf("\n9. Matricular alumno en asignatura");
        
        printf("\n0. SALIR");
        printf("\nIntroduce una opcion: ");
        scanf("%d",&opc);
        
    } while (opc<0 || opc>9);
    return opc;
}


void volcarAlumn(char nombreOrigen[], char nombreDestino[]){
    
    FILE *fOrigen, *fDestino;
    
    struct datosAlumno reg;
    
    fOrigen = fopen(nombreOrigen, "rb");
    
    fDestino = fopen(nombreDestino, "wb");
    
    if (fOrigen == NULL || fDestino == NULL){
        
        printf("\nERROR DE APERTURS");
        return;
        
    }
    
    
    fread(&reg, sizeof(struct datosAlumno), 1, fOrigen);
    
    while(!feof(fOrigen)){
        
        fwrite(&reg, sizeof(struct datosAlumno), 1, fDestino);
        fread(&reg, sizeof(struct datosAlumno), 1, fOrigen);
        
    }
    
    fclose(fOrigen);
    fclose(fDestino);
    remove(nombreOrigen);
}



void visualizarAlumnos(char nf[])
{
    FILE *f;
    struct datosAlumno alum;
    
    f = fopen(nf, "rb");
    if (f == NULL) {
        printf("\n Error en la apertura\n");
        
    }
    else
    {
        fread(&alum, sizeof(struct datosAlumno), 1, f);
        while (!feof(f))
        {
            printf("\nExp: %d\t Nombre: %s %s", alum.nExp, alum.nombre, alum.apellidos);
            fread(&alum, sizeof(struct datosAlumno), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}

void visualizarAsignaturas(char nf[])
{
    FILE *f;
    struct datosAsignatura asig;
    
    f = fopen(nf, "rb");
    if (f == NULL) { printf("\n Error en la apertura\n"); }
    else
    {
        
        fread(&asig, sizeof(struct datosAsignatura), 1, f);
        while (!feof(f))
        {
            printf("\nCodigo: %d\t NombreAsignatura: %s\t Curso: %d", asig.codigo, asig.nombreAsig, asig.curso);
            fread(&asig, sizeof(struct datosAsignatura), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}
void visualizarMatriculados(char nf[])
{
    FILE *f;
    struct datosMatriculado m;
    
    f = fopen(nf, "rb");
    if (f == NULL) { printf("\n Error en la apertura\n"); }
    else
    {
        
        fread(&m, sizeof(struct datosMatriculado), 1, f);
        while (!feof(f))
        {
            printf("\nExp: %d\t CodigoAsignatura: %d", m.nExp, m.codigo);
            fread(&m, sizeof(struct datosMatriculado), 1, f);
        }
        printf("\n\n");
        fclose(f);
    }
}

void visualizarInfoDeAlumno(char nf[]){
    
    FILE *f;
    
    struct datosAlumno reg;
    
    int numExp;
    
    f = fopen(nf, "rb");
    
    if (f == NULL){
        printf("\n Error en la apertura\n");
        return;
    }
    
    printf("\nIntroduce el numero de expediente: ");
    scanf("%d",&numExp);
    
    fread(&reg, sizeof(struct datosAlumno), 1, f);
    
    
    
    while(!feof(f) && reg.nExp != numExp){
        
        fread(&reg, sizeof(struct datosAlumno), 1, f);
        
    }
    
    if(feof(f)){
        
        printf("\nNo hay alumno con este numero de expediente");
        
    }else{
        
        
        printf("numExp: %d alumno: %s %s", reg.nExp, reg.nombre, reg.apellidos);
    }
    
    fclose(f);
    
    
}


void visualizarInfoDeAsignatura(char nf[]){
    
    FILE *f;
    
    struct datosAsignatura reg;
    
    int codigo;
    
    f = fopen(nf, "rb");
    
    if (f == NULL){
        printf("\n Error en la apertura\n");
        return;
    }
    
    printf("\nIntroduce el codigo: ");
    scanf("%d",&codigo);
    
    fread(&reg, sizeof(struct datosAsignatura), 1, f);
    
    
    
    while(!feof(f) && reg.codigo != codigo){
        
        fread(&reg, sizeof(struct datosAsignatura), 1, f);
        
    }
    
    if(feof(f)){
        
        printf("\nNo hay asignatura con este codigo");
        
    }else{
        
        
        printf("codigo: %d Nombre: %s Curso: %d", reg.codigo, reg.nombreAsig, reg.curso);
    }
    
    fclose(f);
    
    
}

void anadirAlumno(char nf[]){
    
    FILE *f, *faux;
    struct datosAlumno reg, regNuevo;
    
    f = fopen(nf, "rb");
    
    faux = fopen("aux.bin", "wb");
    
    if(f == NULL || faux == NULL){
        
        printf("\nERROR DE LECTURA");
        return;
        
    }
    
    printf("\nNum de exp: ");
    scanf("%d", &regNuevo.nExp);
    
    fread(&reg, sizeof(struct datosAlumno), 1, f);
    
    while(!feof(f) && reg.nExp < regNuevo.nExp){
        
        fwrite(&reg, sizeof(struct datosAlumno), 1, faux);
        fread(&reg, sizeof(struct datosAlumno), 1, f);
        
    }
    
    if(reg.nExp == regNuevo.nExp){
        
        printf("\nYa existe este numero de exp ");
        
        fclose(f);
        fclose(faux);
        remove("aux.bin");
        
        return;
        
    }
    
    printf("\nNombre de nuevo alumno: ");
    scanf(" %s", regNuevo.nombre);
    
    printf("\nApellidos de nuevo alumno: ");
    scanf(" %s[^\n]", regNuevo.apellidos);
    
    fwrite(&regNuevo, sizeof(struct datosAlumno), 1, faux);
    
    while(!feof(f)){
        
        fwrite(&reg, sizeof(struct datosAlumno), 1, faux);
        fread(&reg, sizeof(struct datosAlumno), 1, f);
        
    }
    
    fclose(f);
    fclose(faux);
    volcarAlumn("aux.bin", nf);
    
//    remove(nf);
//    rename("aux.bin", nf);
    
}

void generarFicheroDeTexto(char nfAlumn[], char nfAsign[], char nfMatr[]){
    
    FILE *fAlumn, *fAsign, *fMatr, *fTexto;
    int numExp;
    
    struct datosAlumno regAlumn;
    struct datosAsignatura regAsign;
    struct datosMatriculado regMatr;
    
    fAlumn = fopen(nfAlumn, "rb");
    fAsign = fopen(nfAsign, "rb");
    fMatr = fopen(nfMatr, "rb");
    
    fTexto = fopen("InfoMatr.txt", "w");
    
    
    if(fAlumn == NULL || fAsign == NULL || fMatr == NULL || fTexto == NULL){
        
        printf("ERROR DE APERTURA");
        return;
    }
    
    printf("Introduce el nuemro de exp:");
    scanf("%d", &numExp);
    
    fread(&regAlumn, sizeof(struct datosAlumno), 1, fAlumn);
    
    while(!feof(fAlumn) && regAlumn.nExp != numExp){
        
        fread(&regAlumn, sizeof(struct datosAlumno), 1, fAlumn);
        
    }
    
    if(feof(fAlumn)){
        
        printf("\nNo hay este numExp..");
        
        fclose(fAlumn);
        fclose(fAsign);
        fclose(fMatr);
        fclose(fTexto);
        return;
        
    }
        
    fprintf(fTexto, "Nombre: %s %s\n", regAlumn.nombre, regAlumn.apellidos);
        
    fprintf(fTexto, "Asignaturas matriculadas: \n");
        
    fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
        
    while(!feof(fMatr) && regMatr.nExp != numExp){
            
            fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
            
    }
        
    if(feof(fMatr)){
        
        printf("\nEste numExp no esta matriculado..");
        
        fclose(fAlumn);
        fclose(fAsign);
        fclose(fMatr);
        fclose(fTexto);
        return;
    }
            
//        fread(&regAsign, sizeof(struct datosAsignatura), 1, fAsign);
//
//        while(!feof(fAsign) && regAsign.codigo != regMatr.codigo){
//
//            fread(&regAsign, sizeof(struct datosAsignatura), 1, fAsign);
//
//        }
//
//        if(feof(fAsign)){
//
//            printf("\nENo hay info de la asignatura con codigo %d en la lista", regMatr.codigo);
//
//        }else{
//
//            fprintf(fTexto,"%s Curso %d\n",regAsign.nombreAsig, regAsign.curso);
//
//        }
            
//        fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
            
        while(!feof(fMatr) && regMatr.nExp == numExp){
                
            rewind(fAsign);
                
            fread(&regAsign, sizeof(struct datosAsignatura), 1, fAsign);
                
            while(!feof(fAsign) && regAsign.codigo != regMatr.codigo){
                    
                fread(&regAsign, sizeof(struct datosAsignatura), 1, fAsign);
                    
            }
                
            if(feof(fAsign)){
                    
                printf("\nENo hay info de la asignatura con codigo %d en la lista", regMatr.codigo);
                    
            }else{
                    
                fprintf(fTexto,"\t%s Curso %d\n",regAsign.nombreAsig, regAsign.curso);
                    
            }
                
                
                
            fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
                
                
                
        }
            
    
        
    
    
    fclose(fAlumn);
    fclose(fAsign);
    fclose(fMatr);
    fclose(fTexto);
    
}

void eliminarAlumno(char nfAlumn[], char nfMatr[]){
    
    FILE *fAlumn, *fauxAlumn, *fMatr, *fauxMatr;
    struct datosAlumno regAlumn;
    struct datosMatriculado regMatr;
    int numExp;
    int check = 0;
    
    fAlumn = fopen(nfAlumn, "rb");
    fauxAlumn = fopen("auxAlumn", "wb");
    
    if(fAlumn == NULL || fauxAlumn == NULL){
        printf("\nERROR DE APERTURA");
        return;
    }
    
    printf("\nIntroduce el numero de exp para eliminar: ");
    scanf("%d", &numExp);
    
    fread(&regAlumn, sizeof(struct datosAlumno), 1, fAlumn);
    
    while(!feof(fAlumn)){
        
        if(regAlumn.nExp != numExp){
            fwrite(&regAlumn, sizeof(struct datosAlumno), 1, fauxAlumn);
        }else{
            check = 1;
        }
        
        fread(&regAlumn, sizeof(struct datosAlumno), 1, fAlumn);
    }
    
    fclose(fAlumn);
    fclose(fauxAlumn);
    
    if(check == 0){
        printf("\nNo existe alumno con este numero de expediente");
        remove("auxAlumn");
        return;
    }
    
    remove(nfAlumn);
    rename("auxAlumn", nfAlumn);
    
    fMatr = fopen(nfMatr, "rb");
    fauxMatr = fopen("auxMatr", "wb");
    
    if(fMatr == NULL || fauxMatr == NULL){
        printf("\nERROR DE APERTURA");
        return;
    }
    
    fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
    
    while(!feof(fMatr)){
        
        if(regMatr.nExp != numExp){
            fwrite(&regMatr, sizeof(struct datosMatriculado), 1, fauxMatr);
        }
        
        fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
    }
    
    fclose(fMatr);
    fclose(fauxMatr);
    
    remove(nfMatr);
    rename("auxMatr", nfMatr);
    
    printf("\nAlumno eliminado correctamente");
}


//volunt2
void matricularAlumno(char nfAlumn[], char nfAsign[], char nfMatr[]){
    
    FILE *fAlumn, *fAsign, *fMatr, *fauxMatr;
    
    struct datosAlumno regAl;
    struct datosAsignatura regAsig;
    struct datosMatriculado regMatr, regMatrNuevo;
    
    
    printf("\nIntroduce el numero de expediente: ");
    scanf("%d", &regMatrNuevo.nExp);
    
    fAlumn = fopen(nfAlumn, "rb");
    
    if(fAlumn == NULL){
        printf("\nERROR DE APERTURA");
        return;
    }
    
    fread(&regAl, sizeof(struct datosAlumno), 1, fAlumn);
    
    
    
    while(!feof(fAlumn) && regAl.nExp != regMatrNuevo.nExp){
        
        fread(&regAl, sizeof(struct datosAlumno), 1, fAlumn);
    }
    
    if(feof(fAlumn)){
        printf("\nNo existe alumno con este numero de expediente");
        fclose(fAlumn);
        return;
    }
    
    fclose(fAlumn);
    
    
    
    printf("\nIntroduce el codigo de asignatura: ");
    scanf("%d", &regMatrNuevo.codigo);
    
    fAsign = fopen(nfAsign, "rb");
    
    if(fAsign == NULL){
        
        printf("\nERROR DE APERTURA");
        return;
    }
    
    
    
    fread(&regAsig, sizeof(struct datosAsignatura), 1, fAsign);
    
    while(!feof(fAsign) && regAsig.codigo != regMatrNuevo.codigo){
        
        fread(&regAsig, sizeof(struct datosAsignatura), 1, fAsign);
    }
    
    if(feof(fAsign)){
        printf("\nNo existe asignatura con este codigo");
        fclose(fAsign);
        return;
    }
    
    fclose(fAsign);
    
    
    
    
    
    
    fMatr = fopen(nfMatr, "rb");
    fauxMatr = fopen("auxMatr", "wb");
    
    if(fMatr == NULL || fauxMatr == NULL){
        printf("\nERROR DE APERTURA");
        return;
    }
    
    
    
    
    fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
    
    while(!feof(fMatr) &&
          (regMatr.nExp < regMatrNuevo.nExp ||
          (regMatr.nExp == regMatrNuevo.nExp && regMatr.codigo < regMatrNuevo.codigo))){
        
        fwrite(&regMatr, sizeof(struct datosMatriculado), 1, fauxMatr);
        fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
    }
   
    
    
    if(!feof(fMatr) &&
       regMatr.nExp == regMatrNuevo.nExp &&
       regMatr.codigo == regMatrNuevo.codigo){
        
        printf("\nEl alumno ya esta matriculado");
        
        fclose(fMatr);
        fclose(fauxMatr);
        remove("auxMatr");
        
        return;
    }
    
    fwrite(&regMatrNuevo, sizeof(struct datosMatriculado), 1, fauxMatr);
    
    
    while(!feof(fMatr)){
        
        fwrite(&regMatr, sizeof(struct datosMatriculado), 1, fauxMatr);
        fread(&regMatr, sizeof(struct datosMatriculado), 1, fMatr);
    }
    
    
    
    fclose(fMatr);
    fclose(fauxMatr);
    remove(nfMatr);
    rename("auxMatr", nfMatr);
    
    
    
    printf("\nEl alumno %s %s ha sido matriculado en la asignatura %s",
           regAl.nombre, regAl.apellidos, regAsig.nombreAsig);
}
