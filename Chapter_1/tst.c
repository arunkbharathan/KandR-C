#include <stdio.h>
#define MAXLINE 4000


int getlyne(char line_input[], int lim);
int rm_blank(char input[], int len);
int rmcomment(char input[], char output[], int k, int len);
int chk_synt(char output[], int len);
int x_barOR_w(char, char);
int c2 = 0;
int main()
{

    char input[MAXLINE], output[MAXLINE];

    int len = 0, c = 0, i = 0, j = 0, k = 0;

    while ((len = getlyne(input, MAXLINE)) > 0) {
	if (len > MAXLINE) {
	    printf
		("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",
		 len, MAXLINE);
	    break;
	}


	k = rmcomment(input, output, k, len);

    }
    if (k >= MAXLINE) {
	printf
	    ("\nInput file  length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct",
	     k, MAXLINE);
	return 0;
    }
    output[k] = '\0';
    printf("\n%s\n", output);

    if (!chk_synt(output, k)) {
	printf("\nNo Errors.\n");
    }
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

int rmcomment(char input[], char output[], int k, int len)
{
    int i = 0, j = 0, a = 0, d = 0, c1 = 0, alr = 0, n = 0;
    char x, y;
    extern int c2;
    if (c2 == 1) {
	alr = 1;
    }
    for (i = 0; i < len; i++) {

	y = input[i];

	if (y == '\'' && x != '\\' && d == 0 && c1 == 0 && c2 == 0
	    && alr == 0) {
	    a++;
	    a = a % 2;
	}
	if (y == '"' && x != '\\' && a == 0 && c1 == 0 && c2 == 0
	    && alr == 0) {
	    d++;
	    d = d % 2;
	}
	if (x == '/' && y == '/' && a == 0 && d == 0 && c2 == 0
	    && alr == 0) {
	    c1++;
	    c1 = c1 % 2;
	    input[i - 1] = '\n';
	    input[i] = '\0';
	    break;
	}
	if (x == '/' && y == '*' && a == 0 && d == 0 && c1 == 0
	    && alr == 0) {
	    c2++;
	    c2 = c2 % 2;
	    j = i - 1;
	}
	if (x == '*' && y == '/' && c2 == 1) {
	    c2++;
	    c2 = c2 % 2;
	    alr = 0;
	    for (n = j; n <= i; n++) {
		input[n] = ' ';
	    }
	}

	x = y;
    }
    if (c2 == 1) {
	input[j] = '\n';
	input[j + 1] = '\0';
    }



    i = 0;


    while (input[i] != '\0') {
	output[k] = input[i];
	k++;
	i++;
    }

    return k;
}


int chk_synt(char input[], int len)
{
    int i, j, k, lF, lS, lR, rF, rS, rR, V, A, D, E;
    char w, x, y;
    i = j = k = lF = lS = lR = A = D = rF = rS = rR = E = 0;

    for (i = 0; i < len; i++) {
	y = input[i];
	j = x_barOR_w(w, x);
	if (y == '{' && A == 0 && D == 0) {
	    lF++;
	}
	if (y == '[' && A == 0 && D == 0) {
	    lS++;
	}
	if (y == '(' && A == 0 && D == 0) {
	    lR++;
	}
	if (y == '}' && A == 0 && D == 0) {
	    rF++;
	}
	if (y == ']' && A == 0 && D == 0) {
	    rS++;
	}
	if (y == ')' && A == 0 && D == 0) {
	    rR++;
	}

	if (y == '\'' && D == 0 && j) {
	    A++;
	    A = A % 2;
	}
	if (y == '"' && A == 0 && j) {
	    D++;
	    D = D % 2;
	}



	w = x;
	x = y;
    }
    if ((rF - lF) != 0)
	printf("\n%d Flower Bracket Unmatched.\n", lF - rF);
    if ((rS - lS) != 0)
	printf("\n%d Square Bracket Unmatched.\n", lS - rS);
    if ((rR - lR) != 0)
	printf("\n%d Round Bracket Unmatched.\n", lR - rR);
    if ((rF - lF) == 0 && (rS - lS) == 0 && (rR - lR) == 0) {
	return 0;
    } else {
	printf("\n\'+\'=>left\n\'-\'=>right\n");
	return -1;
    }


}

int x_barOR_w(char w, char x)
{
    int b, a, y;
    a = (w == '\\');
    b = (x == '\\');
    y = ((!b) || a);
    return y;
}
