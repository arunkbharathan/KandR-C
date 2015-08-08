/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/

#include <stdio.h>
#include <ctype.h>
#define SIZE 10

int getch(void);
void ungetch(int);

int main()
{
	int i,n, array[SIZE], getint(int *);
	printf("\nEnter integers seperated by space (EOF to end):->");
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for( i = 0; i < n; i++)
		printf("\n%d",array[i]);
	putchar('\n');
	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign, d;
	while (isspace(c = getch()))
		/* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it is not a number */
		return 0;
		}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		{
			c = getch();
			d=c;
			if(!isdigit(c))
			{
				if(c != EOF)
					ungetch(c);
				ungetch(d);
				return d;
			}
		}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	if(c == EOF)
	    return EOF;
	return c;
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

