/*Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.*/
#include <stdio.h>
/* count lines in input */
main ()
{
  int c, d = 0;

  while ((c = getchar ()) != EOF)
    {

      if ((c == ' ') && (d == ' '))
	{
	  d = c;
	  continue;
	}
      putchar (d);
      d = c;

    }
  putchar (d);
}
