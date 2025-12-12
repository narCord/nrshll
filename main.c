#include "parser.h"
#include "exec.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char cmmnd[100];
    int c = 0;
    int *counter = &c;
    char testinput[] = " ls -l   -a";
    char **tokens;

    cmmnd = read_prompt(100);

    tokens = tokenize(cmmnd, counter);
    printf("Found tokens %d\n", *counter);
    for(int i = 0; i < *counter; i++){
        printf("%s\n", tokens[i]);
    }

    execute_external(tokens);

    return 0;
}
