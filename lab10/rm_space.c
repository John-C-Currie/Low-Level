#include "my_string_lib.h"
#include <stdio.h>

void rm_space(char *s){
    rm_left_space(s);
    rm_right_space(s);
}
