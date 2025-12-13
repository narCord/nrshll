#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

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
    int error = 0;
    error = execvp(cmd_and_args[0], cmd_and_args);
    switch(error){
        case EACCES:
            printf("EACCES");
            break;
        case EIO:
            printf("EIO");
            break;
        case ELOOP:
            printf("ELOOP");
            break;
        case ENAMETOOLONG:
            printf("ENAMETOOLONG");
            break;
        case ENOENT:
            printf("ENOENT");
            break; 
        case ENOEXEC:
            printf("ENOEXEC");
            break;  
        case ESTALE:
            printf("ESTALE");
            break;
        case ENOTDIR:
            printf("ENOTDIR");
            break; 
        case EFAULT:
            printf("EFAULT");
            break;
        case EPERM:
            printf("EPERM");
            break;
        case EBADF:
            printf("EBADF");
    }

    return 0;
}
