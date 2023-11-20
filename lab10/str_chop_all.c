#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char **str_chop_all(char *s, char c){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = 0;
    int count = 0;
    while(s[len] != '\0'){
        len++;
    }
    for(i = 0; i < len; i++){
        if(s[i] == c){
            count++;
        }
    }
    char **s2 = (char **)malloc((count + 2) * sizeof(char *));
    for(i = 0; i < count + 2; i++){
        s2[i] = (char *)malloc((len + 1) * sizeof(char));
    }
    for(i = 0; i < len; i++){
        if(s[i] == c){
            s2[j][k] = '\0';
            j++;
            k = 0;
        }
        else{
            s2[j][k] = s[i];
            k++;
        }
    }
    s2[j][k] = '\0';
    s2[j + 1] = NULL;
    return s2;
}