#include "my_string_lib.h"
#include <stdio.h>

int diff(char *s1, char *s2){
    unsigned int i = 0;
    unsigned int count = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] != s2[i]){
            count++;
        }
        i++;
    }
    return count;
}
