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

void execute_external(){
    
}
