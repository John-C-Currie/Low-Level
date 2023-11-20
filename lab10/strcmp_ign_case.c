#include "my_string_lib.h"
#include <stdio.h>

int strcmp_ign_case(char *s1, char *s2){
    int i = 0;
    int j = 0;
    int sum = 0;
    while(s1[i] != '\0' && s2[j] != '\0'){
        if(s1[i] != '\0'){
            if(s1[i] >= 'A' && s1[i] <= 'Z'){
                sum += (int) s1[i] + 32;
            }
            else{
                sum += (int) s1[i];
            }
            i++;
        }
        if(s2[j] != '\0'){
            if(s2[j] >= 'A' && s2[j] <= 'Z'){
                sum -= (int) s2[j] + 32;
            }
            else{
                sum -= (int) s2[j];
            }
            j++;
        }
    }
    return sum;
}