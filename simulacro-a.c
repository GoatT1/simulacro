#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

char* barras(char* s1);

int main(int argc, char ** argv[])
{
    char *datos[10];
    int fd=-1;

    for(int i=0;i<10;i++)
    {
        __fpurge(stdin);
        datos[i]=(char*)malloc(30*sizeof(char*));
        fgets(datos[i],30,stdin);
        __fpurge(stdin);

    }

    for(int i=0;i<10;i++)
    {
        barras(datos[i]);
    }

    fd = open("bDatosTruch.txt",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    for(int i=0;i<10;i++)
    {
        write(fd,datos[i],strlen(datos[i]));
    }

    close(fd);

    return 0;
}

char* barras(char* s1)
{
    char * inicio = s1;
    while(*inicio != '\0')
    {
        inicio++;
    }
    
    *inicio = '\r';
    *(inicio+1) = '\n';
    *(inicio+2) = '\0';

    return s1;
}
