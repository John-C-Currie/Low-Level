#include "my_string_lib.h"
#include <stdio.h>

void rm_left_space(char *s){
    int i = 0;
    int j = 0;
    while(s[i] == ' '){
        i++;
    }
    while(s[i] != '\0'){
        s[j] = s[i];
        i++;
        j++;
    }
    s[j] = '\0';
}
