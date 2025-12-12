#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int max_length = (int) sysconf(_SC_ARG_MAX);
    int c = 0;
    int *counter = &c;
    char *command;
    char **tokenized_cmd;
    pid_t pid;

    printf("Max command length %d\n", max_length);

    while(true){
        command = read_prompt(max_length); 
        tokenized_cmd = tokenize(command, counter); 

        for (int i = 0; i < *counter; i++){
            printf("%s\n", tokenized_cmd[i]);
        }

        pid = fork();
        if (pid == -1){
            //error
        }
        else if (pid == 0){ // hijo
            execute_external(tokenized_cmd);
        }
        else if (pid > 0){ // padre
            int status = 0;
            waitpid(pid, &status, 0);
        }

        free(command);
    }

    return 0;
}
