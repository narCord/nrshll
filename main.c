#include "parser.h"

#include <stdio.h>
#include <string.h>

int main(){
    char *prmpt = read_prompt(100);

    printf("%s\n", prmpt);

    return 0;
}
