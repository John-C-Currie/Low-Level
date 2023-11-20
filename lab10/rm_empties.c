#include "my_string_lib.h"
#include <stdio.h>

void rm_empties(char **words)
{
    while (*words != NULL)
    {
        int len = 0;
        while ((*words)[len] != '\0')
        {
            len++;
        }
        if (len == 0)
        {
            if (*(words + 1) != NULL)
            {
                *words = *(words + 1);
                *(words + 1) = "";
            }
            else
            {
                *words = NULL;
            }
        }
        else
        {
            words++;
        }
    }
}