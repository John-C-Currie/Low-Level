#include "my_string_lib.h"
#include <stdio.h>
#include <stdlib.h>

char *str_connect(char **strs, int n, char c) {
    int i, j, k;
    int len = 0;
    int len_sep = 0;

    for (i = 0; i < n; i++) {
        j = 0;
        while (strs[i][j] != '\0') {
            len++;
            j++;
        }
    }

    if (n > 1) {
        len_sep = n - 1;
    }

    char *s2 = (char *)malloc((len + len_sep + 1) * sizeof(char));

    k = 0;
    for (i = 0; i < n; i++) {
        j = 0;
        while (strs[i][j] != '\0') {
            s2[k] = strs[i][j];
            k++;
            j++;
        }
        if (i != n - 1) {
            s2[k] = c;
            k++;
        }
    }
    s2[k] = '\0';

    return s2;
}