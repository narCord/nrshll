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

void exec_exit(){
    exit(0);
}

void exec_cd(char **cmd_and_args){
    chdir(cmd_and_args[1]);
}

int execute_internal(char **cmd_and_args){
    if (strcmp(cmd_and_args[0], "cd") == 0){
        exec_cd(cmd_and_args);
    }
    else if (strcmp(cmd_and_args[0], "exit") == 0){
        exec_exit();
    }
    else if (strcmp(cmd_and_args[0], "help") == 0){
        //exec_help();
    }
    else{
        //error
        return 1; 
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
