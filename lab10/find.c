#include "my_string_lib.h"
#include <stdio.h>

int find(char *h, char *n){
    int iterator = 0;
    int target = 0;
    int index = 0;
    while(h[iterator] != '\0'){
        if(h[iterator] == n[target]){
            while(h[iterator] == n[target]){
                iterator++;
                target++;
            }
            if(n[target - 1] == '\0' || n[target] == '\0'){
                return index;
            }
            else{
                target = 0;
            }
        }
        else{
            iterator++;
            index++;
        }
    }
    return -1;
}