#include "my_string_lib.h"
#include <stdio.h>

int num_in_range(char *s1, char b, char t){
    int i = 0;
    int count = 0;
    while(s1[i] != '\0'){
        if(s1[i] >= b && s1[i] <= t){
            count++;
        }
        i++;
    }
    return count;
}