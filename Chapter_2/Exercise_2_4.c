/*Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2 .*/
#include<stdio.h>

void flush (char s[], int);
void squeeze (char s[], char q[]);
#define lim 100

int
main ()
{
  char s[lim];
  char q[lim], c;
  int i;

  printf ("\nEnter string to squeeze: ");
  for (i = 0; i < lim - 1 && (c = getchar ()) != '\n' && c != EOF; ++i)
    s[i] = c;
  s[i] = '\0';
  printf ("\nSqueeze using string: ");
  for (i = 0; i < lim - 1 && (c = getchar ()) != '\n' && c != EOF; ++i)
    q[i] = c;
  q[i] = '\0';

  squeeze (s, q);
  printf ("\nSqueezed: %s\n", s);
  return 0;

}

/*flush: delete all c from s*/
void
flush (char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

void
squeeze (char s[], char q[])
{
  int i;
  for (i = 0; q[i] != '\0'; i++)
    flush (s, q[i]);
}
