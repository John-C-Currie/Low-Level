#include "my_string_lib.h"
#include <stdlib.h>
#include <stdio.h>

char *replace(char *s, char *pat, char *rep) {
    int len_s = 0;
    while (s[len_s] != '\0') {
        len_s++;
    }

    int len_pat = 0;
    while (pat[len_pat] != '\0') {
        len_pat++;
    }

    int len_rep = 0;
    while (rep[len_rep] != '\0') {
        len_rep++;
    }

    int count = 0;
    const char *ptr = s;
    while (*ptr != '\0') {
        if (*ptr == *pat) {
            int match = 1;
            for (int i = 1; i < len_pat; i++) {
                if (*(ptr + i) != *(pat + i)) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                count++;
                ptr += len_pat;
                continue;
            }
        }
        ptr++;
    }

    int len_result = len_s + count * (len_rep - len_pat);

    char *result = (char *)malloc((len_result + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    char *dest = result;
    ptr = s;
    while (*ptr != '\0') {
        if (*ptr == *pat) {
            int match = 1;
            for (int i = 1; i < len_pat; i++) {
                if (*(ptr + i) != *(pat + i)) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                for (int i = 0; i < len_rep; i++) {
                    *dest = rep[i];
                    dest++;
                }
                ptr += len_pat;
                continue;
            }
        }
        *dest = *ptr;
        dest++;
        ptr++;
    }

    *dest = '\0';

    return result;
}