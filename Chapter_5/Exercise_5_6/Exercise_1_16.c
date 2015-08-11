/*Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text.*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 50
/* maximum input line length */
int getlyne (char *line, int maxline);
void copy (char to[], char from[]);
/* print the longest input*/
int main ()
{
  int len;

  int max;

  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getlyne (line, MAXLINE)) > 0)
    {
      if (len > MAXLINE)
	{
	  printf
	    ("\nLine length %d larger than MAXLINE %d.\nIncrease array limit. \n\nProgram output not correct\n",
	     len, MAXLINE);
	  break;
	}
      if (len > max)
	{
	  max = len;
	  copy (longest, line);
	}
    }
  if (max > 0)			/* there was a line */
    printf ("\nLongest is %s", longest);
  return 0;
}

int getlyne (char *s, int lim)
{
  int c;
  char *v = s;
  for (; (c = getchar ()) != EOF && c != '\n';)
    *s++ = c;
  if (c == '\n')
  		*s++  = c;     
    
   *s  = '\0';

  return strlen(v);
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
