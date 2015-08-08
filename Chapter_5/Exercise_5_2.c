/*Exercise 5-2. Write getfloat , the floating-point analog of getint . What type does getfloat
return as its function value?*/
/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 10

int getch(void);
void ungetch(int);


int main()
{
	int i,n,getfloat(double *);
	double array[SIZE];
	printf("\nEnter numbers seperated by space (EOF to end):->");
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	for( i = 0; i < n; i++)
		printf("\n%g",array[i]);
	putchar('\n');
	return 0;
}

int getfloat(double *pn)
{
    double val, power;
    int sign, c;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') 
    {
	    ungetch(c); /* it is not a number */
	    return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (val = 0.0; isdigit(c); c = getch())
        val = 10.0 * val + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) 
    {
        val = 10.0 * val + (c - '0');
        power *= 10;
        
    }
    *pn = sign * val / power;
    if (c != EOF)
	    ungetch(c);
    if(c == EOF)
	    return EOF;
    return 1;
    
}

#define BUFSIZE 100
static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;    /* next free position in buf */
 
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


