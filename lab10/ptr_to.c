#include "my_string_lib.h"
#include <stddef.h>
#include <stdio.h>

char *ptr_to(char *h, char *n){
    if(find(h, n) == -1){
        }
        else{
            return h + find(h, n);
        }
        return NULL;
}