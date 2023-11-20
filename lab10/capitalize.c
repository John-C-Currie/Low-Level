#include "my_string_lib.h"
#include <stdio.h>

void capitalize(char *s){
    int i = 0;
    while(s[i] != '\0' && s[i] != ' '){
        if(s[i] >= 'a' && s[i] <= 'z' && (i == 0 || s[i-1] == ' ')){
            s[i] = s[i] - 32;
        }
        i++;
    }
}