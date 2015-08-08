/*Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/
#include <stdio.h>
#define MAXLINE 4000
#define CPL 20			//coloumn per line

int getlyne(char line_input[], int lim);
int fold(char input[], char output[], int k, int len, int copyflag);

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
	if (len < CPL) {
	    k = fold(input, output, k, len, 1);
	    continue;
	}

	k = fold(input, output, k, len, 0);

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

int fold(char input[], char output[], int k, int len, int copyflag)
{
    int i = 0, t = 0, b = 0, a = 0;

    if (copyflag == 1) {
	for (i = 0; i < len; i++) {

	    output[i + k] = input[i];

	}
	k = i + k;
	return k;
    }

    for (i = CPL; i < len; i += CPL) {
	if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
	    input[i] = '\n';
	} else {
	    a = i;
	    while (input[i] > ' ' && i >= 0) {
		i--;
	    }

	    if (b == i) {
		i = a;
		continue;
	    }
	    b = i;
	    input[i] = '\n';
	}

    }

    for (i = k; t < (len - 1); i++) {
	if (i > k)
	    t = i - k;
	else
	    t = k - i;
	output[i] = input[t];

    }
    k = t + k;
    return k + 1;

}
