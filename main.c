#include "parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char *command;
    int c = 0;
    int *counter = &c;
    char testinput[] = " ls -l   caca /pedo  --pis";
    char **tokens;
    //cmmnd = read_prompt(100);

    //printf("%s\n", cmmnd);
    tokens = tokenize(testinput, counter);
    printf("Found tokens %d\n", *counter);

    for (int i = 0; i < *counter; i++){
        printf("%s\n", tokens[i]);
    }

    return 0;
}
