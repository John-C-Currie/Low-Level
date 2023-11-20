#include "my_string_lib.h"
#include <stdio.h>

void shorten(char *s, int new_len){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    if(new_len < i){
        s[new_len] = '\0';
    }
}