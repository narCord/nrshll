#include "parser.h"
#include "exec.h"
#include "prompt.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>

int main(){
    int max_length = (int) sysconf(_SC_ARG_MAX);
    int c = 0;
    int *counter = &c;
    char *cmd;
    char **tokenized_cmd;
    pid_t pid;

    printf("Max cmd length %d\n", max_length);

    while(true){
        print_prompt(max_length/2);
        cmd = read_prompt(max_length); 
        tokenized_cmd = tokenize(cmd, counter); 
        
        if(!determine_command_type(tokenized_cmd[0])){
            fflush(stdin);
            fflush(stdout);
            
            // Para ejecutar comandos externos creo un proceso hijo ad hoc
            pid = fork();
            if (pid == -1){
                //error
            }
            else if (pid == 0){ // hijo
                execute_external(tokenized_cmd);
                free(cmd);
                free(tokenized_cmd);
                exit(0);
            }
            else if (pid > 0){ // padre
                int status = 0;
                waitpid(pid, &status, 0);
            }
        }
        else{
            fflush(stdin);
            fflush(stdout);
            execute_internal(tokenized_cmd);
        }

        fflush(stdout);
        fflush(stdin);
        
        free(tokenized_cmd);
        free(cmd);
    }

    return 0;
}
