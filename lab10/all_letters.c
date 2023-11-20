#include "my_string_lib.h"
#include <stdio.h>
#include <ctype.h>

int all_letters(char *s){
    int i = 0;
    while(s[i] != '\0'){
        if(!isalpha(s[i])){
            return 0;
        }
        i++;
    }
    return 1;
}