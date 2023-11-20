#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char *repeat(char *s, int n, char *sep){
    int i = 0;
    int j = 0;
    int len = 0;
    int len_sep = 0;
    while(s[len] != '\0'){
        len++;
    }
    while(sep[len_sep] != '\0'){
        len_sep++;
    }
    char *s2 = (char *)malloc((len * n + (n - 1) * len_sep + 1) * sizeof(char));
    for(i = 0; i < n; i++){
        for(j = 0; j < len; j++){
            s2[i * (len + len_sep) + j] = s[j];
        }
        if(i != n - 1){
            for(j = 0; j < len_sep; j++){
                s2[i * (len + len_sep) + len + j] = sep[j];
            }
        }
    }
    s2[i * (len + len_sep)] = '\0';
    return s2;
}