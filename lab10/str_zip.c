#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char *str_zip(char *s1, char *s2) {
    int len1 = 0, len2 = 0;
    char *result;
    int i = 0, j = 0, k = 0;

    while (s1[len1] != '\0') {
        len1++;
    }
    while (s2[len2] != '\0') {
        len2++;
    }

    result = (char *)malloc((len1 + len2 + 1) * sizeof(char));

    while (k < len1 + len2) {
        if (i < len1) {
            result[k++] = s1[i++];
        }
        if (j < len2) {
            result[k++] = s2[j++];
        }
    }

    result[k] = '\0';

    return result;
}