#include "my_string_lib.h"
#include <stdio.h>

void rm_right_space(char *s){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    i--;
    while(s[i] == ' '){
        i--;
    }
    s[i+1] = '\0';
}