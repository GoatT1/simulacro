#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define NOMBRE_TAM 32

struct data_S
{
    char nombre[NOMBRE_TAM];
    unsigned int edad;
    struct status *pestado;
};

struct status
{
    unsigned char activo:1;
    unsigned char memoria:1;
    unsigned char enmision:1;
    unsigned char america:1;
    unsigned char asia:1;
    unsigned char europa:1;
    unsigned char oceania:1;
    unsigned char africa:1;
};


void abrirArchivo(int * fd, char * nombre);
void calcularTamArch(int fd, long int *tam);
void reservarMemoria(char **pdatos, long int tam);
void leerArchivo(char **pdatos, long int tam, int fd);
void recorrerArchivo(char *pdatos,long int tam,struct data_S ** dato);

int main(int argc, char ** argv)
{
    int fd=-1;
    long int tam=0;
    char *pdatos=0;
    int leido=0;

    struct data_S *dato=0;

    if(argc>1)
    {
        printf("El nombre del archivo es %s\n",argv[1]);
        abrirArchivo(&fd, argv[1]);
        calcularTamArch(fd,&tam);
        reservarMemoria(&pdatos,tam);
        leerArchivo(&pdatos, tam, fd);

       //dato = (struct data_S*)malloc(10*sizeof(struct data_S));

        recorrerArchivo(pdatos,tam,&dato);


        close(fd);
        free(pdatos);

        

    }

    


    return 0;
}

void abrirArchivo(int * fd, char * nombre)
{
    *fd = open(nombre,O_RDONLY);
    if(*fd == -1)
    {
        printf("Error al abrir archivo\n");
    }
    else
    {
        printf("Archivo abierto");
    }
}

void calcularTamArch(int fd,long int *tam)
{
    *tam = lseek(fd,0,SEEK_END);
    printf("El tamaño del archivo es: %ld\n",*tam);
    lseek(fd,0,SEEK_SET);
}

void reservarMemoria(char **pdatos,long int tam)
{
    if(tam>0)
    {
        *pdatos=(char*)malloc(tam);
        if(*pdatos == 0)
        {
            printf("No hay espacio\n");
        }
        else
        {
            printf("Espacio reservado\n");
        }
    }
}

void leerArchivo(char **pdatos, long int tam,int fd)
{
    long int leido=0;

    if(fd!=-1)
    {
        leido = read(fd,*pdatos,tam);
    }
    if(leido == tam)
    {
        printf("Leido y cargado en la ram OK\n");

        *(*pdatos+tam)='\0';
        printf("%s",*pdatos);
    }
}

void recorrerArchivo(char *pdatos, long int tam,struct data_S ** dato)
{
    int j=0;
    int i=0;
    int k=0;
    char aux[30];
    int kAux=0;
    char *paux=0;
    int auxedad=0;
    

    *dato = (struct data_S*)malloc(10*sizeof(struct data_S));

    
        paux=pdatos;
        i=0;

        while(*pdatos != ',')
        {
            
            pdatos++;
            printf("u\n");
            //i++;
            j++;
        }
        *pdatos='\0';
        while(paux != pdatos)
        {
            strcpy((*dato)->nombre+i,paux);
            paux++;
            i++;

    
        }
        printf("%s",(*dato)->nombre);
    
       // printf("here");
        //j++;
        while(*(pdatos)!='\r' && *(pdatos+1)!='\n')
        {
            auxedad=atoi(pdatos);
            
            (*dato)->edad=(unsigned int)auxedad;
            pdatos++;
            j++;
            //printf("x");
    
        }
        printf("%u",(*dato)->edad);
     
    

    
    
}