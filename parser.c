#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

char* read_prompt(int prmpt_length){
    char prompt[prmpt_length];
    char *prompt_result;
    
    // Lee el prompt escrito por el usuario
    printf("prmpt> ");
    // Comprueba que el resultado de asignacion  con la funcion fgets no haya sido null
    if((prompt_result = fgets(prompt, prmpt_length, stdin)) != NULL){
        return prompt_result;
    } // Si hubiese un error lo manejo aqui
    else if (ferror(stdin)) {
        perror("Error");
        exit(0);
    }
}
