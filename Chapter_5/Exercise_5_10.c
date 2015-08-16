/*Exercise 5-10. Write the program expr , which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument. For example,
expr 2 3 4 + *
evaluates 2 * (3+4).*/
#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#include <ctype.h>
#include <string.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
void push (double);
double pop (void);
int process_argv (char *argv[], char s[]);
/* reverse Polish calculator */
int main (int argc, char *argv[])
{
  int type;
  double op2;
  char s[MAXOP];

  if (argc < 4)
    {
      printf ("\nInput like \"%s 2 3 \\*\"\n", argv[0]);
      return -1;
    }
  argv++;

  while ((type = process_argv (argv, s)) != '\0')
    {

      switch (type)
	{
	case NUMBER:
	  push (atof (s));
	  break;
	case '+':
	  push (pop () + pop ());
	  break;
	case '*':
	  push (pop () * pop ());
	  break;
	case '-':
	  op2 = pop ();
	  push (pop () - op2);
	  break;
	case '/':
	  op2 = pop ();
	  if (op2 != 0.0)
	    push (pop () / op2);
	  else
	    printf ("error: zero divisor\n");
	  break;
	default:
	  printf ("error: unknown command %s\n", s);
	  break;
	}
      argv++;
    }
  printf ("%.8g\n", pop ());
  return 0;
}

#define MAXVAL 100		/* maximum depth of val stack */

int sp = 0;			/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push (double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf ("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop (void)
{
  if (sp > 0)
    return val[--sp];
  else
    {
      printf ("error: stack empty\n");
      return 0.0;
    }
}

int process_argv (char *argv[], char s[])
{

  char c;
  if (*argv == NULL)
    return '\0';
  c = *argv[0];
  if (ispunct (c))
    return c;
  else
    {
      strcpy (s, *argv);
      return NUMBER;
    }

}
