/*Exercise 5-11(b). Modify the program entab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.*/
/*Exercise 5-11(a). Modify the program detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.*/
#define MAXLINELEN 1000
#include <stdio.h>
#include <stdlib.h>
enum booleans { NO, YES };
enum input_category { NEWLINE = '\n', SPACE = ' ' };
int rule[MAXLINELEN];
int cmpfunc(const void *a, const void *b);


#define TABSTOP 8
int main(int argc, char **argv)
{
    char c;
    void make_rule(int[], char **, int);
    void entab(char);
    argv++;

    make_rule(rule, argv, argc);

    while ((c = getchar()) != EOF)
	entab(c);
    putchar('\n');
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int temp[1000];
void make_rule(int rule[], char **argv, int argc)
{
    int i;
    if (argc > 1) {
	for (i = 0; i < argc - 1; ++argv, ++i)
	    temp[i] = atoi(*argv);

	qsort(&temp[0], argc - 1, sizeof(int), cmpfunc);

	for (i = 0; i < argc - 1; ++i)
	    rule[temp[i]] = YES;


	for (i = temp[i - 1] + 1; i < 1000; i++)
	    rule[i] = ((i % TABSTOP) == 0) ? YES : NO;
    } else
	for (i = 0; i < 1000; i++)
	    rule[i] = ((i % TABSTOP) == 0) ? YES : NO;

}

int cpos = 0;
int space_count = 0;
void entab(char c)
{
    switch (c) {
    case NEWLINE:
	cpos = 0;
	for (; space_count > 0; space_count--)
	    putchar(' ');
	space_count = 0;
	putchar(c);
	break;

    default:
	cpos += space_count;
	for (; space_count > 0; space_count--)
	    putchar(' ');
	space_count = 0;
	putchar(c);
	cpos++;
	break;

    case SPACE:
	space_count++;
	if (rule[cpos + space_count] == YES)
	    putchar('\t');

	break;
    }
}
