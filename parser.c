#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "parser.h"

char* read_prompt(int prmpt_max_length){
    char prompt[prmpt_max_length];
    char *command;
    
    // Lee el prompt escrito por el usuario
    printf("prmpt> ");
    // Comprueba que el resultado de asignacion  con la funcion fgets no haya sido null
    if((command = fgets(prompt, prmpt_max_length, stdin)) != NULL){
        command[strcspn(command, "\n")] = 0;
        return prompt_result;
    } // Si hubiese un error lo manejo aqui
    else if (ferror(stdin)) {
        perror("Error");
        exit(0);
    }
}

int get_command_length(char *command){
    return strspn(command, "\0");
}

char* tokenize_command(char *command, int length){
    char *token;
    char *tokens[length];
    int i = 0;

    token = strtok(command, " ");
    do{
        tokens[i++] = token;
    } while (token = strtok(NULL, ","));
}
