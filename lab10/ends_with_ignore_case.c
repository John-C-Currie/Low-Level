#include "my_string_lib.h"
#include <stdio.h>

int ends_with_ignore_case(char *s1, char *suff){
    int i = 0;
    int j = 0;
    int s1_len = 0;
    int suff_len = 0;
    while(s1[s1_len] != '\0'){
        s1_len++;
    }
    while(suff[suff_len] != '\0'){
        suff_len++;
    }
    if(suff_len > s1_len){
        return 0;
    }
    else{
        for(i = s1_len - suff_len; i < s1_len; i++){
            if(s1[i] >= 'A' && s1[i] <= 'Z'){
                if(s1[i] + 32 != suff[j]){
                    return 0;
                }
            }
            else{
                if(s1[i] != suff[j]){
                    return 0;
                }
            }
            j++;
        }
        return 1;
    }
}