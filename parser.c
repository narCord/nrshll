#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "parser.h"

char *read_prompt(int prmpt_max_length){
    char prompt[prmpt_max_length];
    char *command;
    
    // Lee el prompt escrito por el usuario
    printf("> ");
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

char **tokenize(const char *cmd, int *counter){
	char *cmd_aux;
	char *tok;
    char **tokens;

	*counter = 0;
	cmd_aux = strdup(cmd);

    // Cuento los tokens totales
	tok = strtok(cmd_aux, " \t\n");
	while(tok != NULL){
        (*counter)++;
	    tok = strtok(NULL, " \t\n");
	}
    
    // Libero cmd_aux y copio de nuevo cmd
	free(cmd_aux);
	cmd_aux = strdup(cmd);
    
    // Asigno la memoria del
    tokens = malloc(((*counter) + 1) * sizeof(char *));
    
    // Relleno el array tokens con los punteros devueltos de strtok()
	tokens[0] = strtok(cmd_aux, " \t\n");
	for (int i = 1; i < *counter; i++){
		tokens[i] = strtok(NULL, " \t\n");
	}

    return tokens;
}
