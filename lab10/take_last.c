#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

void take_last(char *s, int n) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }

    if (n > length) {
        n = length;
    }
    
    char *temp = malloc((n + 1) * sizeof(char));
    int i, j;
    for (i = length - n, j = 0; i < length; i++, j++) {
        temp[j] = s[i];
    }
    temp[j] = '\0';
    
    for (i = 0; i <= j; i++) {
        s[i] = temp[i];
    }
    
    free(temp);
}