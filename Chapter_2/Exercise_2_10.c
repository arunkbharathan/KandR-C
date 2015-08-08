/*Rewrite the function lower , which converts upper case letters to lower case,
with a conditional expression instead of if-else .*/

#include<stdio.h>
int lower (int c);
#define lim 100

void
main ()
{
  char s[lim];
  int c, i;

  printf ("\nEnter a string: ");
  for (i = 0; i < lim - 1 && (c = getchar ()) != '\n' && c != EOF; ++i)
    {

      s[i] = lower (c);
    }
  s[i] = '\0';

  printf ("\nLower case: %s\n", s);
}


int
lower (int c)
{
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
