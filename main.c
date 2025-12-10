#include "parser.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *cmmnd;
    int *token_count;

    cmmnd = read_prompt(100);

//    printf("%s\n", cmmnd);
    tokenize_command(cmmnd, token_count);

    return 0;
}
