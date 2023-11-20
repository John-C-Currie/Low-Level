#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char *pad(char *s, int d){
    int i = 0;
    int len = 0;
    while(s[len] != '\0'){
        len++;
    }
    if(len % d == 0){
        return s;
    }
    else{
        char *s2 = (char *)malloc((len + d - (len % d) + 1) * sizeof(char));
        for(i = 0; i < len; i++){
            s2[i] = s[i];
        }
        for(i = len; i < len + d - (len % d); i++){
            s2[i] = ' ';
        }
        s2[i] = '\0';
        return s2;
    }
}