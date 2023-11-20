#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char *dedup(char* s){
    int len = 0;
    while(s[len] != '\0'){
        len++;
    }
    char *deduplicated = (char*) malloc(len + 1);
    int deduplicatedIndex = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < deduplicatedIndex; j++) {
            if (s[i] == deduplicated[j]) {
                isDuplicate = 1;
                break;
            }
        }

        if (!isDuplicate) {
            deduplicated[deduplicatedIndex++] = s[i];
        }
    }

    deduplicated[deduplicatedIndex] = '\0';

    return deduplicated;
}
    

