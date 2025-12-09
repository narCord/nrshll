#include <stdio.h>
#include <string.h>

#define MAX_LINE 100 

int main(){
    char prompt[MAX_LINE];
    char *prompt_result;
    
    // Lee el prompt escrito por el usuario
    printf("prmpt> ");
    // Comprueba que el resultado de asignacion  con la funcion fgets no haya sido null
    if((prompt_result = fgets(prompt, MAX_LINE, stdin)) != NULL){
        printf("Prompt was %s\n", prompt_result);
    } // Si hubiese un error lo manejo aqui
    else if (ferror(stdin)) {
        perror("Error");
    }

    return 0;
}
