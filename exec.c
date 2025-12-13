#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

// true = interno,  false = externo
int determine_command_type(const char *cmd){
    if (strcmp(cmd, "cd") == 0){
        return 1;
    }
    else if (strcmp(cmd, "exit") == 0){
        return 1;
    }
    else if (strcmp(cmd, "help") == 0){
        return 1; 
    }
    else{
        return 0; 
    }
}

// Ejectuo esta funcion dentro de un proceso hijo creado en el loop principal
int execute_external(char **cmd_and_args){
    // execlp acepta un char *, que es el nombre del programa a ejecutar
    // y un char ** que seran los argumentos del programa (ignora la primera posicion
    // del char **, que seria el nombre del programa) 
    if (execvp(cmd_and_args[0], cmd_and_args)){
        printf("error\n");
    }
    
    return 0;
}
