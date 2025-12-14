#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_prompt(int max_length){
    char cwd[max_length];

    if (getcwd(cwd, max_length) != NULL){
        printf("%s > ", cwd);
    }
    else{
        perror("Error printing prompt");
        exit(1);
    }
}
