//for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;

/*   Write a loop equivalent to the for loop above without using && or || .  */

#include<stdio.h>

int
main ()
{
  int i = 0, lim = 20;
  char c, s[1000];

  while (i < lim - 1)
    {
      if ((c = getchar ()) == '\n')
	break;
      if (c == EOF)
	break;

      s[i++] = c;

    }

  s[i] = '\0';

  printf ("\n%s\n", s);

  return (0);
}
