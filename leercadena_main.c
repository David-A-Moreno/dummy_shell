#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"


int main(int argc, char *argv[]) {

char comando[100]="";
char **vector;

    if (argc == 1) {

        printf("Indique el programa que desea que se ejecute\n");
        exit(EXIT_FAILURE);
    }

    for (int j = 1; j < argc; j++) {

        if(j == 1) {

           strcpy(comando, argv[j]);

        }
        else {

           strcat(comando," ");
           strcat(comando,argv[j]);
        }

    }
    vector = de_cadena_a_vector(comando);
    execvp(vector[0],vector);

    perror("Return from execlp() not expected");
    exit(EXIT_FAILURE);

}
