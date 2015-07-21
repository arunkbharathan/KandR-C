/*Exercise 4-4. Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.*/
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
/* reverse Polish calculator */
int main()
{
	printf("\n INFO");
	printf("\n------");
	printf("\n\n Reverse Polish Calculator");
	printf("\n\n entering 1 2 - does 1-2");
	printf("\n Please enter 0.xx instead of .xx");
	printf("\n ! + enter: swap top 2 element of stack.");
	printf("\n # + enter: To print stack.");
	printf("\n i j k #: adds digis i,j,k to stack, i is at top of stack.");
	printf("\n @ + enter: Duplicate last element in stack.");
	printf("\n $ + enter: clear the stack.");
	printf("\n ~ + enter: delete element at top of stack.\n\n");
	int type;
	double op2,temp;
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
				printf("\t%.8g\n", pop());
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

#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;    /* next free position in buf */

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
