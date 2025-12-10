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
        return command;
    } // Si hubiese un error lo manejo aqui
    else if (ferror(stdin)) {
        perror("Error");
        exit(0);
    }
}

int get_command_length(const char *command){
    return strlen(command);
}

char** tokenize_command(const char *command, int *token_count){
    char *command_copy;
    char **tokens;
    int command_length = get_command_length(command);
    
    // Hago una copia de command para tokenizarla
    command_copy = malloc(sizeof(char) * command_length);
    strlcpy(command_copy, command, command_length + 1);

    
    // Para arreglar, hacer una primera pasada con strtok() para contar los tokens que habra
    // Despues, hacer una segunda
}
