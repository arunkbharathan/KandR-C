/*Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/
#include <stdio.h>
#define MAXLINE 4000

int getlyne(char line_input[], int lim);
int rm_blank(char input[], char output[], int k, int lim);
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


	k = rm_blank(input, output, k, len);



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

int rm_blank(char input[], char output[], int k, int len)
{
    int i, j, c;
    c = len - 1;
    i = 0;
    j = 0;

    while (input[c] == ' ' || input[c] == '\t') {
	i++;
	input[c] = '\0';
	j = 0;
	if (c == 0) {
	    j = 1;
	    break;
	}
	c--;
    }
    if (j == 0) {
	for (i = 0; input[i] != '\0'; i++) {
	    output[k] = input[i];
	    k++;
	}

    }
    return k;
}
