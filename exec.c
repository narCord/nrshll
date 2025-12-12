#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// true = interno,  false = externo
bool determine_command_type(const char *cmd){
    if (strcmp(cmd, "cd")){
        return true;
    }
    else if (strcmp(cmd, "exit")){
        return true;
    }
    else if (strcmp(cmd, "echo")){
        return true; 
    }
    else if (strcmp(cmd, "pwd")){
        return true; 
    }
    else if (strcmp(cmd, "help")){
        return true; 
    }
    else if (strcmp(cmd, "alias")){
         return true;
    }
    else{
        return false; 
    }
}

// Ejectuo esta funcion dentro de un proceso hijo creado en el loop principal
int execute_external(char **cmd_and_args){
    // execlp acepta un char *, que es el nombre del programa a ejecutar
    // y un char ** que seran los argumentos del programa (ignora la primera posicion
    // del char **, que seria el nombre del programa) 
    execvp(cmd_and_args[0], cmd_and_args);

    return 0;
}
