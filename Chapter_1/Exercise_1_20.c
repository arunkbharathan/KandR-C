/*Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?*/
#include <stdio.h>
#define MAXLINE 4000
#define TABSTOP 8

int getlyne(char line_input[], int lim);
int detab(char input[], char output[], int k);
int main()
{

    char input[MAXLINE], output[MAXLINE];

    int len = 0, k = 0;

    while ((len = getlyne(input, MAXLINE)) > 0) {
	if (len > MAXLINE) {
	    printf
		("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",
		 len, MAXLINE);
	    break;
	}
	if (len == 0)
	    break;

	k = detab(input, output, k);

    }
    output[k] = '\0';
    printf("\n%s", output);
    return 0;
}


int getlyne(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	s[i] = c;
    if (c == '\n') {
	s[i] = c;
	++i;
    }
    s[i] = '\0';
    return i;
}
	
int detab(char input[], char output[], int k)
{
    int j = 0, i = 0, t = 0, n = 0;
    for (i = 0; input[i] != '\n'; i++) {
	if (input[i] == '\t') {
	    t = TABSTOP - (n) % TABSTOP;
	    for (j = 0; j < t; j++) {
		output[k] = ' ';
		k++;
		n++;
	    }

	} else {
	    output[k] = input[i];
	    k++;
	    n++;
	}

    }
    output[k] = '\n';
    k++;
    return k;
}
