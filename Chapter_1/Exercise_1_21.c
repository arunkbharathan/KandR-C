/*Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference?*/
#include <stdio.h>
#define MAXLINE 4000
#define TABSTOP 8

int getlyne(char line_input[], int lim);
int entab(char input[], char output[], int k);
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

	k = entab(input, output, k);

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

int entab(char input[], char output[], int k)
{
    int j = 0, i = 0, t = 0, s = 0, b = 0, cpos = 0;
    char y;
    for (i = 0; input[i] != '\n'; i++) {
	y = input[i];
	if (y == ' ') {
	    b++;
	    s++;
	    cpos++;
	} else if (y == '\t') {
	    t++;
	    cpos = cpos + TABSTOP - cpos % TABSTOP;
	    b = b + TABSTOP - cpos % TABSTOP;
	}

	if (cpos % TABSTOP == 0) {
	    if (s > 0 && t == 1) {
		output[k] = '\t';
		k++;
		t = 0;
		s = 0;
		b = 0;
	    }
	    if (s == 0 && t == 1) {
		output[k] = '\t';
		k++;
		t = 0;
		s = 0;
		b = 0;
	    }
	    if (s > 0 && t == 0) {
		output[k] = '\t';
		k++;
		t = 0;
		s = 0;
		b = 0;
	    }

	}

	if (y != ' ' && y != '\t') {
	    for (j = 0; j < s; j++) {
		output[k] = ' ';
		k++;
		b = 0;
		t = 0;
	    }
	    s = 0;
	    output[k] = y;
	    k++;
	    cpos++;
	}


    }
    output[k] = '\n';
    k++;
    return k;
}
