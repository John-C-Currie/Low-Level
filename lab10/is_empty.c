#include "my_string_lib.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

int is_empty(char *s){
    int i = 0;
    if(s == NULL){
        return 1;
    }
    while(s[i] != '\0'){
        if(!isspace(s[i])){
            return 0;
        }
        i++;
    }
    return 1;
}