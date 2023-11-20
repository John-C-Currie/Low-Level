#include "my_string_lib.h"
#include <stdio.h>

int main(){
    char s[] = "   hello world   ";
    printf("Before: %s\n", s);
    rm_space(s);
    printf("After: %s\n", s);
    printf("Is string empty? %d\n", is_empty(s));
    printf("Is string all letters? %d\n", all_letters(s));
    printf("Is hello in the string? %d\n", find(s, "hello"));
    printf("Is world in the string? %d\n", find(s, "world"));
    shorten(s, 5);
    printf("After shortening: %s\n", s);
    printf("Does string end with lo? %d\n", ends_with_ignore_case(s, "lo"));
    char* replaceS = replace(s, "lo", "ping");
    printf("Replace lo with ping: %s\n", replaceS);
    printf("After replacing: %s\n", replaceS);
    printf("Does string end with lo? %d\n", ends_with_ignore_case(replaceS, "lo"));
    printf("Does string end with ping? %d\n", ends_with_ignore_case(replaceS, "ping"));
    char **words = str_chop_all(replaceS, 'p');
    printf("Words: %s %s\n", words[0], words[1]);
    char *newS = str_connect(words, 2, 'p');
    return 0;
}