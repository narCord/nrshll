#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "parser.h"

char *read_prompt(int max_length){
    char *line;
    char *cmd;
    
    // Lee el prompt escrito por el usuario
    printf("> ");

    line = malloc(max_length);
    // Comprueba que el resultado de asignacion  con la funcion fgets no haya sido null
    if((cmd = fgets(line, max_length, stdin)) != NULL){
        //cmd[strcspn(cmd, "\n")] = 0;
        return cmd;
    } // Si hubiese un error lo manejo aqui
    else if (ferror(stdin)) {
        perror("Error");
        exit(0);
    }

    return NULL;
}

int get_cmd_length(const char *cmd){
    return strlen(cmd);
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
    
    // Asigno la memoria para tokens segun el numero de tokens contados y pongo el caracter nulo para rematar la cadena
    tokens = malloc(((*counter) + 1) * sizeof(char *));
    tokens[*counter] = NULL;

    // Relleno el array tokens con los punteros devueltos de strtok()
	tokens[0] = strtok(cmd_aux, " \t\n");
	for (int i = 1; i < *counter; i++){
		tokens[i] = strtok(NULL, " \t\n");
	}

    return tokens;
}
