/*
 * Name:	XXX	XXXX
 * Section:	XX
 * Lab:  	CIS2107_Lab08_Manual
 * Goal: 	To design and implement functions taking pointers as arguments
            to process characters and strings.
 */

#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// functions prototypes
void *upperLower(const char *s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr(char *line, char *sub);
int countChar(char *line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[]);
void endsWithed(char *string[]);

int main()
{

    // random generator
    srand(time(NULL));

    // test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    // test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    // test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    // test for compareStr
    puts("\n");
    compareStr("Test1", "Test2");

    // test for comparePartialStr
    puts("\n");
    comparePartialStr("Test1", "Test2", 4);

    // test for randomize
    puts("\n");
    randomize();

    // test for tokenize number
    puts("\n");
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    // test for reverse
    puts("\n");
    char line[] = "Hello world";
    reverse(line);

    // test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    // test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    // test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    // test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    // test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    startsWithB(series);

    // test for endsWithed
    endsWithed(series);
}

// 1.(Displaying Strings in Uppercase and Lowercase)
void *upperLower(const char *s)
{
    const char *start = s;
    while (*s != '\0')
    {
        printf("%c", toupper(*s));
        s++;
    }
    printf("\n");
    s = start;
    while (*s != '\0')
    {
        printf("%c", tolower(*s));
        s++;
    }
}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4)
{
    return atoi(s1) + atoi(s2) + atoi(s3) + atoi(s4);
}

// 3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4)
{
    return atof(s1) + atof(s2) + atof(s3) + atof(s4);
}

// 4.(Comparing Strings)
void compareStr(const char *s1, const char *s2)
{
    if (strcmp(s1, s2) > 0)
    {
        printf("%s is greater than %s\n", s1, s2);
    }
    else if (strcmp(s1, s2) < 0)
    {
        printf("%s is less than %s\n", s1, s2);
    }
    else
    {
        printf("%s is equal to %s\n", s1, s2);
    }
}

// 5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n)
{
    printf("Comparison of first %d chars: ", n);

    if (strncmp(s1, s2, n) > 0)
    {
        printf("%s is greater than %s\n", s1, s2);
    }
    else if (strncmp(s1, s2, n) < 0)
    {
        printf("%s is less than %s\n", s1, s2);
    }
    else
    {
        printf("%s is equal to %s\n", s1, s2);
    }
}

// 6.(Random Sentences)
void randomize(void)
{

    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};
    char sentence[100];

    for (int i = 0; i < 20; i++)
    {
        strcpy(sentence, article[rand() % 5]);
        sentence[0] = toupper(sentence[0]);
        strcat(sentence, " ");
        strcat(sentence, noun[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, verb[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, preposition[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, article[rand() % 5]);
        strcat(sentence, " ");
        strcat(sentence, noun[rand() % 5]);
        strcat(sentence, ".");
        puts(sentence);
    }
}

// 7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num)
{
    char *token = strtok(num, "()-");
    while (token != NULL)
    {
        printf("%s", token);
        token = strtok(NULL, "()-");
    }
}

// 8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text)
{
    char *token = strtok(text, " ");
    char *words[100];
    int i = 0;
    while (token != NULL)
    {
        words[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%s ", words[j]);
    }
}

// 9.(Counting the Occurrences of a Substring)
int countSubstr(char *line, char *sub)
{
    int count = 0;
    char *start = line;
    while ((start = strstr(start, sub)) != NULL)
    {
        count++;
        start++;
    }
    return count;
}

// 10.(Counting the Occurrences of a Character)
int countChar(char *line, char c)
{
    int count = 0;
    while (*line != '\0')
    {
        if (*line == c)
        {
            count++;
        }
        line++;
    }
    return count;
}

// 11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string)
{
    int count[26] = {0};
    char *start = string;
    while (*start != '\0')
    {
        if (isalpha(*start))
        {
            count[tolower(*start) - 'a']++;
        }
        start++;
    }
    printf("Letter\t\tOccurrence\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c\t\t%d\n", 'a' + i, count[i]);
    }
}

// 12.(Counting the Number of Words in a String)
int countWords(char *string)
{
    int count = 0;
    char *token = strtok(string, " \n");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, " \n");
    }
    return count;
}

// 13.(Strings Starting with "b")
void startsWithB(char *string[])
{
    while (*string != NULL)
    {
        if (**string == 'b')
        {
            printf("%s\n", *string);
        }
        string++;
    }
}

// 14.(Strings Ending with "ed")
void endsWithed(char *string[])
{
    while (*string != NULL)
    {
        if (strlen(*string) >= 2 && *(*string + strlen(*string) - 2) == 'e' && *(*string + strlen(*string) - 1) == 'd')
        {
            printf("%s\n", *string);
        }
        string++;
    }
}