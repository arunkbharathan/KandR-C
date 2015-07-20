#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'/* signal that a number was found */

int print_stack(void);
void clear_stack();

int getop(char []);
void push(double);
double pop(void);
int store = 0;
/* reverse Polish calculator */
int main()
{
	int type;
	double op2,temp,W,X,Y,Z,L;
	op2 = temp = W = X = Y = Z = L = 0;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push( fmod(pop(),op2) );
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				L = pop();
				printf("\t%.8g\n", L);
				break;
			case '#':
				print_stack();
				getop(s);
				break;
			case '!':
				op2 = pop();
				temp = pop();
				push(op2);
				push(temp);
				getop(s);
				break;
			case '@':
				op2 = pop();
				push(op2);
				push(op2);
				getop(s);
				break;
			case '$':
				clear_stack();
				getop(s);
				break;
			case 's':
				push(sin(M_PI/180*pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case 'p':
				op2 = pop();
				push(pow(pop(),op2));
				break;
			case '=':
				store = 1;
				break;
			case 'W':
				if(store == 1)
				{
					W = pop();
					push(W);
					store = 0;
					getop(s);

				}
				else
					push(W);
				break;
			case 'X':
				if(store == 1)
				{
					X = pop();
					push(X);
					store = 0;
					getop(s);
				}
				else
					push(X);
				break;

			case 'Y':
				if(store == 1)
				{
					Y = pop();
					push(Y);
					store = 0;
					getop(s);
				}
				else
					push(Y);
				break;

			case 'Z':
				if(store == 1)
				{
					Z = pop();
					push(Z);
					store = 0;
					getop(s);
				}
				else
					push(Z);
				break;
			case 'L':
				push(L);
				break;				
			case '~':
				pop();
				getop(s);
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
			}
		}
	return 0;
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	     }
}

int print_stack(void)
{
	int temp;
	if (sp == 0)
	{
		printf("Stack Empty\n");
		return 0;
	}
	for(temp = sp-1; temp >= 0; --temp)
		printf("|%g|",val[temp]);
	printf("       First element is top of stack\n");
	return 0;

}
void clear_stack()
{
	sp = 0;
}

#include <ctype.h>
int getch(void);
void ungetch(int);
void ungets(char s[]);
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c, d=0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if( s[0] == '-')
		d = getch();
	if (!isdigit(c) && c != '.')
	{
		if( !isdigit(d))
		{
			if(s[0] == '-')
				ungetch(d);
			return c;    /* not a number */
		}
	}
	if(s[0] == '-')
	{
		s[1] = d;
		i = 1;
		c = d;
	}
	else
	{
		i=0;
	}

	if (isdigit(c))    /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')   /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

char buf;
int bufp;
int getch(void) /* get a (possibly pushed-back) character */
{
	if (bufp > 0) 
	{
		bufp--;
		return buf;
	}
	else
		return getchar();
}

void ungetch(int c)  /* push character back on input */
{
	buf = c;
	bufp = 1;
}
