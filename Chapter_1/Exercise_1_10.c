/*Write a program to copy its input to its output, replacing each tab by \t , each
backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an
unambiguous way.*/
#include <stdio.h>
/* count lines in input */
int main()
{
    int c;
    while ((c = getchar()) != EOF) {

	if (c == '\b') {
	    printf("\\b");
	    continue;
	}
	if (c == '\t') {
	    printf("\\t");
	    continue;
	}
	if (c == '\\') {
	    putchar('\\');
	    continue;
	}
	putchar(c);
    }
    return 0;

}
